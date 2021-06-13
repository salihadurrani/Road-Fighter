// Aiman Jamil (2020060)

#pragma once
#include "SDL_mixer.h"

class SEAudio
{
public:
	SEAudio(Mix_Chunk* pChunk, int channel);
	void Play();
	void Pause();
	void Resume();
	void Stop();
	void SetPosition(int angle = 0, int distance = 0);
	int GetPositionAngle();
	int GetPositionDistance();
	int GetChannel();
	void SetFinishedCB(void(*cb)(int channel_useless) = nullptr);
	void FreeChunk();
private:
	Mix_Chunk* m_pChunk;
	int m_nChannel;
	int m_nPosAngle;
	int m_nPosDistance;
};