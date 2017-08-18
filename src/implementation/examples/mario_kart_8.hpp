#pragma once

#define RANDOM_NUMBER_SEED_ADDRESS 0x11000000
#define VR_ADDRESS 0x2F748660

static unsigned long *randomNumberSeed = (unsigned long *) RANDOM_NUMBER_SEED_ADDRESS;

static inline int getRandomNumber() {
	*randomNumberSeed = *randomNumberSeed * 1103515245 + 12345;
	return (unsigned int) (*randomNumberSeed / 65536) % 32768;
}

static inline void setRandomNumberSeed(unsigned int seed) {
	*randomNumberSeed = seed;
}

static inline int random_number(int min_num, int max_num) {
	int result = 0, low_num = 0, hi_num = 0;

	if (min_num < max_num) {
		low_num = min_num;
		hi_num = max_num + 1; // include max_num in output
	} else {
		low_num = max_num + 1; // include max_num in output
		hi_num = min_num;
	}

	result = (getRandomNumber() % (hi_num - low_num)) + low_num;

	return result;
}

__attribute__((noinline))
void randomVR() {
	if (*randomNumberSeed == 0) {
		setRandomNumberSeed(1337);
	}
	unsigned int random = (unsigned int) random_number(0, 10000);
	*(unsigned int *) VR_ADDRESS = random;

	executeAssemblyReturn();
}