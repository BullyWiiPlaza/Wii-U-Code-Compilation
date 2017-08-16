#pragma once

#include "library_functions.h"
#include "enumerations.h"
#include "internal_templates.h"
#include "definitions.h"

__attribute__((noinline))
void ramWrite8Bit() {
	unsigned int *address = (unsigned int *) 0x10000000;
	unsigned char value = 0x12;

	writeInternal(address, value, EIGHT_BIT);
}

__attribute__((noinline))
void ramWrite16Bit() {
	unsigned int *address = (unsigned int *) 0x10000000;
	unsigned short value = 0x1234;

	writeInternal(address, value, SIXTEEN_BIT);
}

__attribute__((noinline))
void ramWrite32Bit() {
	unsigned int *address = (unsigned int *) 0x10000000;
	unsigned int value = 0x12345678;

	writeInternal(address, value, THIRTY_TWO_BIT);
}

__attribute__((noinline))
void stringWrite() {
	unsigned char string[] = "Wolfgang";
	unsigned int *address = (unsigned int *) 0x10647CFC;

	stringWriteInternal(string, address);
}

__attribute__((noinline))
void skipWrite() {
	unsigned int *address = (unsigned int *) 0x10647CFC;
	unsigned int writesCount = 30;
	unsigned int offsetBetweenWrites = 8;
	unsigned int valueIncrement = 1;
	unsigned int value = 0x13371338;
	enum dataType dataType = EIGHT_BIT;

	skipWriteInternal(address, writesCount, offsetBetweenWrites, valueIncrement, value, dataType);
}

__attribute__((noinline))
void fillMemory() {
	unsigned int *address = (unsigned int *) 0x10647CFC;
	unsigned int length = 0xC;
	unsigned int value = 0x13371338;
	enum dataType dataType = THIRTY_TWO_BIT;

	fillMemoryInternal(address, length, value, dataType);
}

__attribute__((noinline))
void corrupter() {
	unsigned int *startingAddress = (unsigned int *) 0x10647CFC;
	unsigned int *endingAddress = (unsigned int *) 0x10650000;
	unsigned int searchValue = 0x13371338;
	unsigned int searchValueReplacement = 0x12345678;
	enum dataType dataType = THIRTY_TWO_BIT;

	corrupterInternal(startingAddress, endingAddress, searchValue, searchValueReplacement, dataType);
}

__attribute__((noinline))
void searchTemplate() {
	unsigned char searchTemplate[] = {0x00, 0x00};
	unsigned int matchCount = 2;
	unsigned int offset = 0x8;
	unsigned char replacement[] = {0x11, 0x12};
	unsigned int *startingAddress = (unsigned int *) 0x10647CFC;
	unsigned int *endingAddress = (unsigned int *) 0x10650000;

	unsigned int searchTemplateArraySize = getArraySize(searchTemplate);
	unsigned int replacementArraySize = getArraySize(replacement);
	writeSearchTemplateInternal(searchTemplate, searchTemplateArraySize, matchCount, offset, replacement, replacementArraySize, startingAddress, endingAddress);
}