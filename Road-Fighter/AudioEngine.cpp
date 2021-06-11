#include "pch.h"
#include "AudioEngine.h"

Mix_Music* AudioEngine::sm_pMusBGM;
int AudioEngine::sm_nBGMVolume;
bool AudioEngine::sm_bChannelUsed[64];

bool AudioEngine::Init()
{
	if (Mix_Init(MIX_INIT_OGG | MIX_INIT_MID) == 0)
	{
		return false;
	}
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
	Mix_AllocateChannels(8);
	return false;
}

void AudioEngine::Quit()
{
	Mix_AllocateChannels(0);
	Mix_FreeMusic(sm_pMusBGM);
	Mix_CloseAudio();
	Mix_Quit();
}

void AudioEngine::PlayBGM(int fade_ms)
{
	Mix_PlayMusic(sm_pMusBGM, 0);
}

void AudioEngine::RewindBGM()
{
	Mix_RewindMusic();
}

void AudioEngine::StopBGM(int fade_ms)
{
	Mix_FadeOutMusic(fade_ms);
}

void AudioEngine::PauseBGM(void)
{
	Mix_PauseMusic();
}

void AudioEngine::ResumeBGM()
{
	Mix_ResumeMusic();
}

void AudioEngine::LoadBGMFromFile(const char* filename)
{
	//del old one
	if (sm_pMusBGM != nullptr)
	{
		Mix_FreeMusic(sm_pMusBGM);
	}

	//load new one
	sm_pMusBGM = Mix_LoadMUS(filename);
	if (sm_pMusBGM == nullptr)
	{
		std::cout << "LoadBGMFromFile() couldn't load music from file." << std::endl;
	}
}

void AudioEngine::LoadBGMFromMem(void* mem, unsigned int size)
{
	auto rw = SDL_RWFromMem(mem, size);
	if (rw == nullptr)
	{
		std::cout << "LoadBGMFromMem() couldn't load rwops from mem." << std::endl;
		return;
	}
	sm_pMusBGM = Mix_LoadMUS_RW(rw, 1);//free rw
	if (sm_pMusBGM == nullptr)
	{
		std::cout << "LoadBGMFromMem() couldn't load music from rwops." << std::endl;
		return;//?
	}
}

void AudioEngine::BGMVolume(int new_volume)
{
	if (new_volume < 0 || new_volume>128)
	{
		std::cout << "BGMVolume() new volume out of range.It have been set to 64." << std::endl;
		Mix_VolumeMusic(64);
		sm_nBGMVolume = 64;
	}
	else
	{
		Mix_VolumeMusic(new_volume);
		sm_nBGMVolume = new_volume;
	}
}

int AudioEngine::BGMVolume()
{
	return sm_nBGMVolume;
}

void AudioEngine::SetFinishedBGMCB(void(*cb)())
{
	Mix_HookMusicFinished(cb);
}

SEAudio* AudioEngine::LoadSEAudioFromFile(const char* filename)
{
	Mix_Chunk* pChunk = Mix_LoadWAV(filename);
	if (pChunk == nullptr)
	{
		std::cout << "LoadSEAudioFromFile() couldn't load from file." << std::endl;
		return new SEAudio(nullptr, 0);
	}

	int freeChannel = __FindEmptyChannel();
	if (freeChannel == -1)
	{
		std::cout << "LoadSEAudioFromFile() could't find free channel." << std::endl;
		Mix_FreeChunk(pChunk);
		return new SEAudio(nullptr, 0);
	}

	auto obj = new SEAudio(pChunk, freeChannel);
	if (obj == nullptr)
	{
		std::cout << "LoadSEAudioFromFile() could't allocate mem for seaudio." << std::endl;
		Mix_FreeChunk(pChunk);
		return new SEAudio(nullptr, 0);
	}

	return obj;
}

SEAudio* AudioEngine::LoadSEAudioFromMem(void* mem, unsigned int size)
{
	auto rw = SDL_RWFromMem(mem, size);
	if (rw == nullptr)
	{
		std::cout << "LoadSEAudioFromFile() couldn't load from mem." << std::endl;
		return new SEAudio(nullptr, 0);
	}

	Mix_Chunk* pChunk = Mix_LoadWAV_RW(rw, 1);//free rw
	if (pChunk == nullptr)
	{
		std::cout << "LoadSEAudioFromFile() couldn't load from rw." << std::endl;
		return new SEAudio(nullptr, 0);
	}

	int freeChannel = __FindEmptyChannel();
	if (freeChannel == -1)
	{
		std::cout << "LoadSEAudioFromFile() could't find free channel." << std::endl;
		Mix_FreeChunk(pChunk);
		return new SEAudio(nullptr, 0);
	}

	auto obj = new SEAudio(pChunk, freeChannel);
	if (obj == nullptr)
	{
		std::cout << "LoadSEAudioFromFile() could't allocate mem for seaudio." << std::endl;
		Mix_FreeChunk(pChunk);
		return new SEAudio(nullptr, 0);
	}

	return obj;
}

void AudioEngine::FreeSEAudio(SEAudio* se)
{
	sm_bChannelUsed[se->GetChannel()] = false;
	se->FreeChunk();
	delete se;
	se = nullptr;
}

void AudioEngine::StopAllSEAudio()
{
	Mix_HaltChannel(-1);
}

int AudioEngine::__FindEmptyChannel()
{
	int freeChannel = -1;
	for (int i = 0; i != 64; i++)
	{
	}
	return 0;
}