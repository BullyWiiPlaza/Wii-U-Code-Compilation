#pragma once

inline void incrementPointerByAbsolute(unsigned int **address, unsigned int increment) {
	*address = (unsigned int *) ((unsigned char *) address + increment);
}