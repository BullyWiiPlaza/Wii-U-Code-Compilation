#pragma once

static inline unsigned long getStringLength(const unsigned char string[]) {
	const unsigned char *character;

	for (character = string; *character != 0; ++character);
	return (character - string);
}

static inline int compareMemory(const void *first, const void *second, int size) {
	const unsigned char *p1 = (const unsigned char *) first, *p2 = (const unsigned char *) second;
	while ((size--) != 0)
		if (*p1 != *p2)
			return *p1 - *p2;
		else
			p1++, p2++;
	return 0;
}

static inline void copyMemory(const unsigned char *source, void *destination, int size) {
	char *characterPointerSource = (char *) source;
	char *characterPointerDestination = (char *) destination;

	for (int index = 0; index < size; index++) {
		characterPointerDestination[index] = characterPointerSource[index];
	}
}