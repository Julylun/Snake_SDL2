#include "Number.h"


int Number::random(const int startNumber, const int endNumber)
{
	std::random_device rd;	// only used once to initialize (seed) engine
	std::mt19937 rng(rd());

	std::uniform_int_distribution<int> uni(startNumber, endNumber);

	return uni(rng);
}
