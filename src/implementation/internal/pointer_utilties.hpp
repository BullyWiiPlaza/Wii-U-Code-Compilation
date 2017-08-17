#pragma once

static inline void incrementPointerByAbsolute(unsigned int **address, unsigned int increment) {
	*address = (unsigned int *) (((unsigned char *) *address) + increment);
}