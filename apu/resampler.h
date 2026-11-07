/*****************************************************************************\
     Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
                This file is licensed under the Snes9x License.
   For further information, consult the LICENSE file in the root directory.
\*****************************************************************************/

#ifndef __NEW_RESAMPLER_H
#define __NEW_RESAMPLER_H

#include <cstring>
#include <cassert>
#include <cstdint>
#include <cmath>

/*
 * Resampler used by the APU (and MSU1) to convert the native SNES DSP rate
 * (~32040 Hz) to the configured playback rate.
 *
 * The original implementation used a 4-point Hermite (cubic) interpolator.
 * Cubic interpolation is cheap, but its frequency response droops well before
 * Nyquist and its stopband attenuation is poor, so the images of the 32 kHz
 * input (16-32 kHz band) are only partially removed. That is audible as a
 * slightly dull, "boxy" top end plus a grainy hiss riding on bright material.
 *
 * This version uses a polyphase windowed-sinc interpolator:
 *   - 64 taps per phase, 256 phases (interpolated), Kaiser window
 *     (beta = 8, better than -80 dB stopband) so the reconstruction is
 *     band limited instead of merely smoothed.
 *   - The cutoff follows the conversion ratio: for upsampling it sits just
 *     below the *input* Nyquist frequency (removing images), for downsampling
 *     it sits below the *output* Nyquist frequency (removing aliasing).
 *   - Accumulation is done in float and rounded (not truncated) to 16 bits,
 *     which removes the low level harmonic distortion of the old integer
 *     truncation.
 *
 * The filter is linear phase, so a fixed latency of TAPS/2 - 1 input frames
 * (31 frames at 32040 Hz, i.e. about 1 ms) is introduced. That is far below one emulated video frame and
 * is constant, so sound sync and dynamic rate control are unaffected.
 */

class Resampler
{
  public:
    enum
    {
        TAPS   = 64,   // taps per phase (linear phase, ~1 ms of latency)
        PHASES = 256   // fractional phase resolution
    };

    volatile int end;
    int buffer_size;
    volatile int start;
    int16_t *buffer;

    float r_step;
    float r_frac;

  private:
    // Input history, hist[TAPS - 1] is the most recent input frame.
    int16_t hist_l[TAPS];
    int16_t hist_r[TAPS];

    // Polyphase coefficient table, PHASES * TAPS floats.
    // One extra row holds frac == 1.0 so that the fractional phase can be
    // interpolated between two neighbours without wrapping special cases.
    float coef[(PHASES + 1) * TAPS];
    float table_ratio;
    bool table_valid;

  public:
    static inline int16_t short_clamp(int n)
    {
        return (int16_t)(((int16_t)n != n) ? (n >> 31) ^ 0x7fff : n);
    }

    static inline int min(int a, int b)
    {
        return ((a) < (b) ? (a) : (b));
    }

    Resampler()
    {
        this->buffer_size = 0;
        buffer = NULL;
        r_step = 1.0f;
        r_frac = 0.0f;
        table_ratio = 0.0f;
        table_valid = false;
        memset(hist_l, 0, sizeof(hist_l));
        memset(hist_r, 0, sizeof(hist_r));
        memset(coef, 0, sizeof(coef));
    }

    Resampler(int num_samples)
    {
        buffer = NULL;
        r_step = 1.0f;
        r_frac = 0.0f;
        table_ratio = 0.0f;
        table_valid = false;
        memset(hist_l, 0, sizeof(hist_l));
        memset(hist_r, 0, sizeof(hist_r));
        memset(coef, 0, sizeof(coef));
        resize(num_samples);
    }

    ~Resampler()
    {
        delete[] buffer;
        buffer = NULL;
    }

    inline void time_ratio(double ratio)
    {
        r_step = (float)ratio;

        // The table only depends on the cutoff, which is derived from the
        // ratio. Dynamic rate control nudges the ratio by a fraction of a
        // percent, which does not justify a rebuild; genuine rate changes do.
        if (!table_valid || std::fabs((double)r_step - table_ratio) > 0.005)
            build_table(r_step);
    }

  private:
    static inline float sinc(float x)
    {
        if (x == 0.0f)
            return 1.0f;

        x *= 3.14159265358979323846f;
        return std::sin(x) / x;
    }

    static float kaiser_i0(float x)
    {
        // Zeroth order modified Bessel function, series expansion.
        double sum = 1.0;
        double term = 1.0;
        double q = (double)x * 0.5;

        for (int k = 1; k < 32; k++)
        {
            term *= (q / k) * (q / k);
            sum += term;
            if (term < 1e-12 * sum)
                break;
        }

        return (float)sum;
    }

    void build_table(float ratio)
    {
        const float beta = 8.0f;
        const float half = TAPS / 2.0f;
        const float center = (TAPS / 2 - 1);
        float cutoff;

        // r_step is input rate / output rate, so a value below 1 means
        // upsampling and a value above 1 means downsampling.
        if (ratio <= 1.0f)
            cutoff = 0.95f;                 // upsampling: kill the input images
        else
            cutoff = 0.95f / ratio;         // downsampling: kill aliasing

        // Normalized Kaiser window, kept as a lookup to avoid recomputing
        // sqrt/I0 for every tap.
        float win[TAPS];
        for (int k = 0; k < TAPS; k++)
        {
            float d = (float)k - center;
            float q = d / half;

            if (q > -1.0f && q < 1.0f)
                win[k] = kaiser_i0(beta * std::sqrt(1.0f - q * q)) / kaiser_i0(beta);
            else
                win[k] = 0.0f;
        }

        for (int p = 0; p <= PHASES; p++)
        {
            float frac = (float)p / PHASES;
            float *c = &coef[p * TAPS];
            float sum = 0.0f;

            for (int k = 0; k < TAPS; k++)
            {
                // Distance in input samples between tap k and the output instant.
                float d = (float)k - (center + frac);
                c[k] = sinc(cutoff * d) * win[k];
                sum += c[k];
            }

            // Unity DC gain per phase, so the filter never introduces a level
            // shift (or a DC step) as the fractional phase moves.
            if (sum != 0.0f)
                for (int k = 0; k < TAPS; k++)
                    c[k] /= sum;
        }

        table_ratio = ratio;
        table_valid = true;
    }

  public:
    inline void clear(void)
    {
        if (!buffer)
            return;

        start = 0;
        end = 0;
        memset(buffer, 0, buffer_size * 2);

        r_frac = 0.0f;
        memset(hist_l, 0, sizeof(hist_l));
        memset(hist_r, 0, sizeof(hist_r));
    }

    inline void dump(int num_samples)
    {
        if (num_samples > 0 && space_filled() >= num_samples)
            start = (start + num_samples) % buffer_size;
    }

    inline void add_silence(int num_samples)
    {
         if (num_samples > 0 && space_empty() < num_samples)
            return;

        int first_block_size = min(num_samples, buffer_size - end);

        memset(buffer + end, 0, first_block_size * 2);

        if (num_samples > first_block_size)
            memset(buffer, 0, (num_samples - first_block_size) * 2);

        end = (end + num_samples) % buffer_size;

        return;
    }

    inline bool pull(int16_t *dst, int num_samples)
    {
        if (space_filled() < num_samples)
            return false;

        int first_block_size = buffer_size - start;

        memcpy(dst, buffer + start, min(num_samples, first_block_size) * 2);

        if (num_samples > first_block_size)
            memcpy(dst + first_block_size, buffer, (num_samples - first_block_size) * 2);

        start = (start + num_samples) % buffer_size;

        return true;
    }

    inline void push_sample(int16_t l, int16_t r)
    {
        if (space_empty() >= 2)
        {
            buffer[end] = l;
            buffer[end + 1] = r;
            end = (end + 2) % buffer_size;
        }
    }

    inline bool push(int16_t *src, int num_samples)
    {
        if (space_empty() < num_samples)
            return false;

        int first_block_size = min(num_samples, buffer_size - end);

        memcpy(buffer + end, src, first_block_size * 2);

        if (num_samples > first_block_size)
            memcpy(buffer, src + first_block_size, (num_samples - first_block_size) * 2);

        end = (end + num_samples) % buffer_size;

        return true;
    }

    void read(int16_t *data, int num_samples)
    {
        assert((num_samples & 1) == 0); // resampler always processes both stereo samples

        if (!table_valid)
            build_table(r_step);

        int o_position = 0;
        bool starved = false;

        while (o_position < num_samples)
        {
            // Advance the input history until the fractional read position
            // falls back into the newest input interval. With ratios larger
            // than 2 this can require several frames per output sample.
            while (r_frac >= 1.0f)
            {
                if (space_filled() < 2)
                {
                    starved = true;
                    break;
                }

                memmove(hist_l, hist_l + 1, (TAPS - 1) * sizeof(int16_t));
                memmove(hist_r, hist_r + 1, (TAPS - 1) * sizeof(int16_t));
                hist_l[TAPS - 1] = buffer[start];
                hist_r[TAPS - 1] = buffer[start + 1];

                start += 2;
                if (start >= buffer_size)
                    start -= buffer_size;

                r_frac -= 1.0f;
            }

            if (starved)
                break;

            // Interpolate between the two neighbouring phase rows. Plain
            // nearest-phase lookups leave a ~1/PHASES sample timing error that
            // shows up as spurious sidebands; blending removes it almost
            // completely for one extra table lookup.
            float fp = r_frac * (float)PHASES;
            int phase = (int)fp;
            if (phase < 0)
                phase = 0;
            if (phase >= PHASES)
                phase = PHASES - 1;
            float mu = fp - (float)phase;

            const float *c0 = &coef[phase * TAPS];
            const float *c1 = &coef[(phase + 1) * TAPS];
            float acc_l = 0.0f;
            float acc_r = 0.0f;

            for (int k = 0; k < TAPS; k++)
            {
                float g = c0[k] + (c1[k] - c0[k]) * mu;
                acc_l += g * (float)hist_l[k];
                acc_r += g * (float)hist_r[k];
            }

            // Round to nearest instead of truncating towards zero: truncation
            // adds a small DC-ish bias that shows up as low level distortion.
            int out_l = (int)std::lrintf(acc_l);
            int out_r = (int)std::lrintf(acc_r);

            data[o_position] = short_clamp(out_l);
            data[o_position + 1] = short_clamp(out_r);

            o_position += 2;
            r_frac += r_step;
        }

        // Should not happen (callers check avail() first), but never leave
        // uninitialised samples behind if the buffer ran dry mid-call.
        if (o_position < num_samples)
            memset(data + o_position, 0, (num_samples - o_position) * sizeof(int16_t));
    }

    inline int space_empty(void) const
    {
        return buffer_size - 2 - space_filled();
    }

    inline int space_filled(void) const
    {
        int size = end - start;
        if (size < 0)
            size += buffer_size;
        return size;
    }

    inline int avail(void)
    {
        int size = space_filled();
        // One frame of slack: the convolution needs the next input frame
        // before it can produce the sample that follows the current interval.
        int frames = (size >> 1) - 1;

        if (frames <= 0)
            return 0;

        int n = (int)std::trunc(((float)frames - r_frac) / r_step);
        if (n < 0)
            n = 0;

        return n * 2;
    }

    void resize(int num_samples)
    {
        if (buffer)
            delete[] buffer;
        // Only allow even buffer sizes
        if (num_samples & 1)
            num_samples++;
        buffer_size = num_samples;
        buffer = new int16_t[buffer_size];
        clear();
    }
};

#endif /* __NEW_RESAMPLER_H */
