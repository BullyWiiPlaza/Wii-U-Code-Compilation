#pragma once

#include "library_functions.h"
#include "enumerations.h"
#include "definitions.h"
#include "pointer_utilties.h"

static inline void stringWriteInternal(const unsigned char *string, unsigned int *address) {
	unsigned long stringLength = getStringLength((const char *) string);
	for (unsigned int stringIndex = 0; stringIndex < stringLength; stringIndex++) {
		writeInternal(address, string[stringIndex], EIGHT_BIT);
	}
}

static inline void skipWriteInternal(unsigned int *address, unsigned int writesCount, unsigned int offsetBetweenWrites,
							  unsigned int valueIncrement, unsigned int value, enum dataType dataType) {
	for (unsigned int writesIndex = 0; writesIndex < writesCount; writesIndex++) {
		writeInternal(address, value, dataType);

		value += valueIncrement;
		incrementPointerByAbsolute(&address, offsetBetweenWrites);
	}
}

static inline void fillMemoryInternal(unsigned int *address, unsigned int length,
							   unsigned int value, enum dataType dataType) {
	unsigned int bytesCount = getBytesCount(dataType);
	unsigned int writesCount = length / bytesCount;

	for (unsigned int offset = 0; offset < writesCount; offset++) {
		writeInternal(address, value, dataType);
		incrementPointerByAbsolute(&address, bytesCount);
	}
}

static inline void corrupterInternal(unsigned int *startingAddress, const unsigned int *endingAddress,
							  unsigned int searchValue, unsigned int searchValueReplacement, enum dataType dataType) {
	unsigned int bytesCount = getBytesCount(dataType);
	unsigned int *currentAddress = startingAddress;

	while (currentAddress < endingAddress) {
		unsigned int currentValue = readInternal(currentAddress, dataType);
		if (currentValue == searchValue) {
			writeInternal(currentAddress, searchValueReplacement, dataType);
		}

		incrementPointerByAbsolute(&currentAddress, bytesCount);
	}
}

static inline void writeSearchTemplateInternal(const unsigned char *searchTemplate, unsigned int searchTemplateArraySize,
										unsigned int matchCount,
										unsigned int offset, unsigned char *replacement,
										unsigned int replacementArraySize,
										unsigned int *startingAddress, const unsigned int *endingAddress) {
	unsigned int countedMatches = 0;
	unsigned int *currentAddress = startingAddress;

	while (currentAddress < endingAddress) {
		int comparisonResult = compareMemory(currentAddress, searchTemplate, searchTemplateArraySize);

		if (comparisonResult == 0) {
			countedMatches++;

			if (countedMatches == matchCount) {
				incrementPointerByAbsolute(&currentAddress, offset);
				copyMemory(replacement, currentAddress, replacementArraySize);

				return;
			}
		}

		incrementPointerByAbsolute(&currentAddress, searchTemplateArraySize);
	}
}