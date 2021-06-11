#pragma once
#include <random>

class RandomEngine
{
public:
	static void Init();
	static int UniformRange(int min, int max);
	static int NormalRange(int mu, int sigma);
	static bool Half();
	static void SetNewSeed();
	static void SetNewSeed(unsigned int seed);
private:
	static std::default_random_engine sm_dre;
};