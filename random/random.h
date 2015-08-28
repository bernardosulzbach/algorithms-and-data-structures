#pragma once

#include <random>

// A Mersenne Twister is not really cheap and its initialization is a bit tricky
// (there is a lot of state to get right), so it seemed a good idea to write a
// header that could provide the other projects with a Mersenne Twister for
// randomness.

// Returns the global uniform random number generator.
// Pass it to a distribution to get pseudo random numbers in the range you need.
std::mt19937 &global_urng();