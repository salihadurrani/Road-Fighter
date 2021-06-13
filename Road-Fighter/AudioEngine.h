// Aiman Jamil (2020060)

#pragma once
#include "SEAudio.h"

class AudioEngine
{
public:
	static bool Init();
	static void Quit();

	static void PlayBGM(int fade_ms = 0);
	static void RewindBGM();
	static void StopBGM(int fade_ms = 0);
	static void PauseBGM();
	static void ResumeBGM();
	static void LoadBGMFromFile(const char* filename);
	static void LoadBGMFromMem(void* mem, unsigned int size);
	static void BGMVolume(int new_volume);
	static int BGMVolume();
	static void SetFinishedBGMCB(void(*cb)() = nullptr);

	static SEAudio* LoadSEAudioFromFile(const char* filename);
	static SEAudio* LoadSEAudioFromMem(void* mem, unsigned int size);
	static void FreeSEAudio(SEAudio* se);
	static void StopAllSEAudio();
private:
	static Mix_Music* sm_pMusBGM;
	static int sm_nBGMVolume;
	static bool sm_bChannelUsed[64];
private:
	static int __FindEmptyChannel();
};