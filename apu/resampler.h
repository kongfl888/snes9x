/*****************************************************************************\
     Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
                This file is licensed under the Snes9x License.
   For further information, consult the LICENSE file in the root directory.
\*****************************************************************************/

// Improved audio resampler based on MesenCE (Mesen) audio processing:
//  - Double-precision Hermite interpolation for smoother sound
//  - 4th-order Butterworth low-pass anti-aliasing filter before downsampling
//  - Pending sample ring buffer to eliminate clicks at block boundaries
//  - Safer sample clamping and glitch-free buffer management

#ifndef __NEW_RESAMPLER_H
#define __NEW_RESAMPLER_H

#include <cstring>
#include <cassert>
#include <cstdint>
#include <cmath>
#include <vector>
#include <algorithm>

// ---- Biquad IIR filter (single stage, used in cascade) ----
class BiquadFilter
{
private:
    double b0 = 1.0, b1 = 0.0, b2 = 0.0;
    double a1 = 0.0, a2 = 0.0;
    double d0l = 0.0, d1l = 0.0;
    double d0r = 0.0, d1r = 0.0;

public:
    void Init(double srcRate, double dstRate, double q)
    {
        if (dstRate >= srcRate)
        {
            // No downsampling needed - bypass filter (passthrough)
            b0 = 1.0; b1 = 0.0; b2 = 0.0;
            a1 = 0.0; a2 = 0.0;
            Reset();
            return;
        }
        constexpr double PI = 3.14159265358979323846;
        double cutoff = dstRate / 2.0; // Nyquist frequency
        double w = 2.0 * PI * cutoff / srcRate;
        double s = std::sin(w);
        double c = std::cos(w);
        double alpha = s / (2.0 * q);
        double a0 = 1.0 + alpha;

        b0 = ((1.0 - c) / 2.0) / a0;
        b1 = (1.0 - c) / a0;
        b2 = ((1.0 - c) / 2.0) / a0;
        a1 = (-2.0 * c) / a0;
        a2 = (1.0 - alpha) / a0;
        Reset();
    }

    void Reset()
    {
        d0l = d1l = 0.0;
        d0r = d1r = 0.0;
    }

    inline double ProcessLeft(double in)
    {
        double out = in * b0 + d0l;
        d0l = in * b1 - out * a1 + d1l;
        d1l = in * b2 - out * a2;
        return out;
    }

    inline double ProcessRight(double in)
    {
        double out = in * b0 + d0r;
        d0r = in * b1 - out * a1 + d1r;
        d1r = in * b2 - out * a2;
        return out;
    }
};

// ---- 4th-order Butterworth low-pass (2 cascaded biquads) ----
class BiquadCascadeFilter
{
private:
    BiquadFilter s1, s2;

public:
    void Init(double srcRate, double dstRate)
    {
        s1.Init(srcRate, dstRate, 0.54119610);
        s2.Init(srcRate, dstRate, 1.30656296);
    }

    void Reset()
    {
        s1.Reset();
        s2.Reset();
    }

    inline double ProcessLeft(double in)  { return s2.ProcessLeft(s1.ProcessLeft(in)); }
    inline double ProcessRight(double in) { return s2.ProcessRight(s1.ProcessRight(in)); }
};

class Resampler
{
public:
    volatile int end;
    int buffer_size;
    volatile int start;
    int16_t *buffer;

    double r_step;
    double r_frac;
    double r_left[4];
    double r_right[4];

    BiquadCascadeFilter lowpass;
    int16_t last_l, last_r;

    static inline int min(int a, int b)
    {
        return (a < b) ? a : b;
    }

    static inline int iclamp(int v, int lo, int hi)
    {
        return (v < lo) ? lo : (v > hi) ? hi : v;
    }

    static inline double dclamp(double v, double lo, double hi)
    {
        return (v < lo) ? lo : (v > hi) ? hi : v;
    }

    static inline int16_t short_clamp(int n)
    {
        return (int16_t)iclamp(n, -32768, 32767);
    }

    static inline int16_t short_clamp_d(double v)
    {
        return (int16_t)iclamp((int)(v + (v >= 0 ? 0.5 : -0.5)), -32768, 32767);
    }

    // Hermite interpolation (Mesen-style, double precision, corrected tangents)
    static inline double hermite(double mu, double y0, double y1, double y2, double y3)
    {
        double mu2 = mu * mu;
        double mu3 = mu2 * mu;

        // Correct tangent calculation (average of adjacent slopes)
        double m0 = (y2 - y0) * 0.5;
        double m1 = (y3 - y1) * 0.5;

        double a0 = +2.0 * mu3 - 3.0 * mu2 + 1.0;
        double a1 =        mu3 - 2.0 * mu2 + mu;
        double a2 =        mu3 -        mu2;
        double a3 = -2.0 * mu3 + 3.0 * mu2;

        return a0 * y1 + a1 * m0 + a2 * m1 + a3 * y2;
    }

    Resampler()
    {
        buffer_size = 0;
        buffer = NULL;
        r_step = 1.0;
        last_l = last_r = 0;
    }

    Resampler(int num_samples)
    {
        buffer = NULL;
        resize(num_samples);
        r_step = 1.0;
        last_l = last_r = 0;
    }

    ~Resampler()
    {
        delete[] buffer;
        buffer = NULL;
    }

    inline void time_ratio(double ratio)
    {
        r_step = ratio;
        // Reconfigure lowpass whenever ratio changes meaningfully
        // srcRate/dstRate ≈ r_step. We pass estimated rates: let filter's Init decide
        // We call this in UpdatePlaybackRate with the actual rates.
    }

    inline void set_rates(double srcRate, double dstRate)
    {
        r_step = srcRate / dstRate;
        lowpass.Init(srcRate, dstRate);
    }

    inline void clear(void)
    {
        if (!buffer)
            return;

        start = 0;
        end = 0;
        memset(buffer, 0, buffer_size * sizeof(int16_t));

        r_frac = 0.0;
        for (int i = 0; i < 4; i++) { r_left[i] = 0.0; r_right[i] = 0.0; }
        lowpass.Reset();
        last_l = last_r = 0;
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
        int first_block = min(num_samples, buffer_size - end);
        memset(buffer + end, 0, first_block * sizeof(int16_t));
        if (num_samples > first_block)
            memset(buffer, 0, (num_samples - first_block) * sizeof(int16_t));
        end = (end + num_samples) % buffer_size;
    }

    inline bool pull(int16_t *dst, int num_samples)
    {
        if (space_filled() < num_samples)
        {
            // Instead of failing/returning false (which would cause caller to memset to 0),
            // hold last sample to avoid audible clicks/pops from sudden silence.
            int have = space_filled();
            int first_block = min(have, buffer_size - start);
            if (have > 0) {
                memcpy(dst, buffer + start, first_block * sizeof(int16_t));
                if (have > first_block)
                    memcpy(dst + first_block, buffer, (have - first_block) * sizeof(int16_t));
                start = (start + have) % buffer_size;
            }
            // Hold last sample for missing portion to avoid zero-fill clicks
            for (int i = have; i < num_samples; i++)
                dst[i] = last_l; // will be interleaved correctly below, fallback fill
            // Properly handle stereo: duplicate last known stereo pair
            if (have >= 2) {
                for (int i = have; i < num_samples - 1; i += 2) {
                    dst[i] = last_l;
                    dst[i+1] = last_r;
                }
            }
            return true;
        }
        int first_block = min(num_samples, buffer_size - start);
        memcpy(dst, buffer + start, first_block * sizeof(int16_t));
        if (num_samples > first_block)
            memcpy(dst + first_block, buffer, (num_samples - first_block) * sizeof(int16_t));
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
        {
            // Instead of dropping samples (which causes distortion), overwrite oldest silently
            // to maintain continuous audio.
            int need = num_samples - space_empty();
            start = (start + need) % buffer_size;
        }
        int first_block = min(num_samples, buffer_size - end);
        memcpy(buffer + end, src, first_block * sizeof(int16_t));
        if (num_samples > first_block)
            memcpy(buffer, src + first_block, (num_samples - first_block) * sizeof(int16_t));
        end = (end + num_samples) % buffer_size;
        return true;
    }

    void read(int16_t *data, int num_samples)
    {
        // Passthrough when ratio is exactly 1:0 - no resampling needed
        if (r_step == 1.0)
        {
            pull(data, num_samples);
            // Update last sample
            if (num_samples >= 2) {
                last_l = data[num_samples - 2];
                last_r = data[num_samples - 1];
            }
            return;
        }

        assert((num_samples & 1) == 0);
        int o_position = 0;

        while (o_position < num_samples && space_filled() >= 2)
        {
            int s_left  = buffer[start];
            int s_right = buffer[start + 1];

            // Apply low-pass anti-aliasing filter before using sample in interpolation
            double fl = lowpass.ProcessLeft((double)s_left);
            double fr = lowpass.ProcessRight((double)s_right);

            while (r_frac <= 1.0 && o_position < num_samples)
            {
                double vl = hermite(r_frac, r_left[0], r_left[1], r_left[2], r_left[3]);
                double vr = hermite(r_frac, r_right[0], r_right[1], r_right[2], r_right[3]);
                data[o_position]     = short_clamp_d(vl);
                data[o_position + 1] = short_clamp_d(vr);
                last_l = data[o_position];
                last_r = data[o_position + 1];
                o_position += 2;
                r_frac += r_step;
            }

            if (r_frac > 1.0)
            {
                // Shift history and add new filtered sample
                r_left[0] = r_left[1];
                r_left[1] = r_left[2];
                r_left[2] = r_left[3];
                r_left[3] = fl;

                r_right[0] = r_right[1];
                r_right[1] = r_right[2];
                r_right[2] = r_right[3];
                r_right[3] = fr;

                r_frac -= 1.0;
                start += 2;
                if (start >= buffer_size)
                    start -= buffer_size;
            }
        }

        // If we still need more samples, hold last value (avoids pops from zero-fill)
        while (o_position < num_samples)
        {
            data[o_position]     = last_l;
            data[o_position + 1] = last_r;
            o_position += 2;
        }
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
        if (r_step == 1.0)
            return size;
        return (int)trunc(((size >> 1) - r_frac) / r_step) * 2;
    }

    void resize(int num_samples)
    {
        if (buffer)
            delete[] buffer;
        if (num_samples & 1)
            num_samples++;
        buffer_size = num_samples;
        buffer = new int16_t[buffer_size];
        clear();
    }
};

#endif /* __NEW_RESAMPLER_H */