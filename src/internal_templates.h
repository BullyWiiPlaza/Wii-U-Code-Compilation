#pragma once

#include "utilities.h"
#include "enumerations.h"

inline void writeInternal(unsigned int *address, unsigned int value, enum dataType dataType) {
	switch (dataType) {
		case EIGHT_BIT:
			*(unsigned char *) address = (unsigned char) value;
			break;

		case SIXTEEN_BIT:
			*(unsigned short *) address = (unsigned short) value;
			break;

		case THIRTY_TWO_BIT:
			*address = value;
			break;
	}
}

inline void stringWriteInternal(const unsigned char *string, unsigned int *address) {
	unsigned long stringLength = getStringLength((const char *) string);
	for (unsigned int stringIndex = 0; stringIndex < stringLength; stringIndex++) {
		writeInternal(address, string[stringIndex], EIGHT_BIT);
	}
}

inline void skipWriteInternal(unsigned int *address, unsigned int writesCount, unsigned int offsetBetweenWrites,
							  unsigned int valueIncrement, unsigned int value, enum dataType dataType) {
	for (unsigned int writesIndex = 0; writesIndex < writesCount; writesIndex++) {
		writeInternal(address, value, dataType);

		value += valueIncrement;
		address += offsetBetweenWrites;
	}
}