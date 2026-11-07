/*****************************************************************************\
     Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
                This file is licensed under the Snes9x License.
   For further information, consult the LICENSE file in the root directory.
\*****************************************************************************/

#pragma once

#include <windows.h>
#include "IS9xSoundOutput.h"
#include <mmsystem.h>
#include <vector>

class CWaveOut : public IS9xSoundOutput
{
  private:
    void BeginPlayback(void);
    void StopPlayback(void);
    void ProcessSound(void);
    int GetAvailableBytes();
    void RecoverFromUnderrun();

    HWAVEOUT hWaveOut;
    bool initDone;

    volatile LONG bufferCount;
    // Free space for pacing comes from the device play cursor, not WOM_DONE
    // arrival — winmm's callback pump can lag playback by a full period.
    UINT64 submittedBytes;
    UINT64 playedBytesAccum;
    DWORD  lastPosBytes;
    UINT64 PlayedBytes();
    UINT32 sumBufferSize;
    UINT32 singleBufferSamples;
    UINT32 singleBufferBytes;
    const UINT32 blockCount = 8;
    UINT32 writeOffset;
    UINT32 partialOffset;
    std::vector<WAVEHDR> waveHeaders;

    // Anti-click helpers: waveOut switches between queued blocks without
    // any crossfade, so a discontinuity after an underrun is audible as a
    // click. Fade the first blocks back in after playback (re)starts.
    int fadeInRemaining;
    int fadeInFrames;
    void ApplyFadeIn(BYTE *data, UINT32 bytes);
  
  public:
    CWaveOut(void);
    ~CWaveOut(void);

    // Inherited from IS9xSoundOutput
    bool InitSoundOutput(void);
    void DeInitSoundOutput(void);
    bool SetupSound(void);
    void SetVolume(double volume);
	std::vector<std::wstring> GetDeviceList();
	int FindDeviceIndex(TCHAR *audio_device);

	static void CALLBACK WaveCallback(HWAVEOUT hWave, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
};
