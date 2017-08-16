#pragma once

inline unsigned long getStringLength(const char *string) {
	const char *character;

	for (character = string; *character; ++character);
	return (character - string);
}

inline int compareMemory(const void *first, const void *second, int size) {
	const unsigned char *p1 = (const unsigned char *) first, *p2 = (const unsigned char *) second;
	while (size--)
		if (*p1 != *p2)
			return *p1 - *p2;
		else
			p1++, p2++;
	return 0;
}

inline void copyMemory(void *source, void *destination, int size) {
	char *characterPointerSource = (char *) source;
	char *characterPointerDestination = (char *) destination;

	for (int index = 0; index < size; index++)
		characterPointerDestination[index] = characterPointerSource[index];
}