#pragma once
#include <random>
namespace rnd
{
	static int rInt(const int& min, const int& max)
	{
		std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); 

		return dist6(rng);
	}
	
};

