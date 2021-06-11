#include <SDL.h>
#include "pch.h"
#include "RandomEngine.h"

std::default_random_engine RandomEngine::sm_dre;

void RandomEngine::Init()
{
	sm_dre.seed((unsigned int)&sm_dre);
}

int RandomEngine::UniformRange(int min, int max)
{
	std::uniform_int_distribution<int> d(min, max);
	return d(sm_dre);
}

int RandomEngine::NormalRange(int mu, int sigma)
{
	std::normal_distribution<>d(mu, sigma);
	return static_cast<int>(d(sm_dre));
}

bool RandomEngine::Half()
{
	std::uniform_int_distribution<int> d(0, 1);
	if (d(sm_dre) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void RandomEngine::SetNewSeed()
{
	sm_dre.seed(SDL_GetTicks());
}

void RandomEngine::SetNewSeed(unsigned int seed)
{
	sm_dre.seed(seed);
}