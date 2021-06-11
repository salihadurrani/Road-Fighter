#include "pch.h"
#include "SEAudio.h"

SEAudio::SEAudio(Mix_Chunk* pChunk, int channel)
{
	m_nChannel = channel;
	m_nPosAngle = 0;
	m_nPosDistance = 0;
	m_pChunk = pChunk;
}

void SEAudio::Play()
{
	if (m_pChunk != nullptr)
	{
		if (!Mix_Playing(m_nChannel))
		{
			Mix_PlayChannel(m_nChannel, m_pChunk, 0);
		}
	}
	else
	{
		std::cout << "SEAudio::Play() m_pChunk is null pointer." << std::endl;
	}
}

void SEAudio::Pause()
{
	Mix_Pause(m_nChannel);
}

void SEAudio::Resume()
{
	Mix_Resume(m_nChannel);
}

void SEAudio::Stop()
{
	Mix_HaltChannel(m_nChannel);
}

void SEAudio::SetPosition(int angle, int distance)
{
	Mix_SetPosition(m_nChannel, angle, distance);
	m_nPosAngle = angle;
	m_nPosDistance = distance;
}

int SEAudio::GetPositionAngle()
{
	return m_nPosAngle;
}

int SEAudio::GetPositionDistance()
{
	return m_nPosDistance;
}

int SEAudio::GetChannel()
{
	return m_nChannel;
}

void SEAudio::SetFinishedCB(void(*cb)(int channel_useless))
{
	Mix_ChannelFinished(cb);
}

void SEAudio::FreeChunk()
{
	Mix_FreeChunk(m_pChunk);
	m_pChunk = nullptr;
}