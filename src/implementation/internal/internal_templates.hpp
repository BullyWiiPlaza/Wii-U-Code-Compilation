#pragma once

#include "library_functions.hpp"
#include "enumerations.hpp"
#include "definitions.hpp"
#include "pointer_utilties.hpp"

static inline void stringWriteInternal(unsigned int *address,
									   const unsigned char *string,
									   unsigned long length) {
	unsigned int stringIndex = 0;
	enum dataType dataType = EIGHT_BIT;
	unsigned int incrementPerIteration = 1;

	for (; stringIndex < length; stringIndex += incrementPerIteration) {
		writeInternal(address, string[stringIndex], dataType);
		incrementPointerByAbsolute(&address, incrementPerIteration);
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
									 unsigned int searchValue, unsigned int searchValueReplacement,
									 enum dataType dataType) {
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

static inline void
writeSearchTemplateInternal(const unsigned char *searchTemplate,
							unsigned int searchTemplateArraySize,
							unsigned int matchCount,
							unsigned int offset,
							const unsigned char *replacement,
							unsigned int replacementArraySize,
							unsigned int *startingAddress,
							const unsigned int *endingAddress) {
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

static inline void writePointerInternal(unsigned int *baseAddress, const unsigned int *startingMemoryRanges,
										const unsigned int *endingMemoryRanges, const int *offsets,
										int offsetsCount, unsigned int value, enum dataType dataType) {
	unsigned int *currentAddress = baseAddress;

	for (int offsetsIndex = 0; offsetsIndex < offsetsCount; offsetsIndex++) {
		// Read pointer value and add the offset
		unsigned int *baseAddressValue = (unsigned int *) *currentAddress;
		baseAddressValue += offsets[offsetsIndex];

		// Validate memory ranges
		if (baseAddressValue < (unsigned int *) startingMemoryRanges[offsetsIndex] ||
			baseAddressValue > (unsigned int *) endingMemoryRanges[offsetsIndex]) {
			goto POINTER_FOLLOWING_FAILED;
		}

		currentAddress = baseAddressValue;
	}

	writeInternal(currentAddress, value, dataType);

	POINTER_FOLLOWING_FAILED:;
}

#define EXECUTE_ASSEMBLY_RETURN_ADDRESS 0x010F6AE0

// This must be the last piece of code to run every time
static inline void executeAssemblyReturn() {
	((void (*)()) EXECUTE_ASSEMBLY_RETURN_ADDRESS)();
}