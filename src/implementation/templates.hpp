#pragma once

#include "internal/library_functions.hpp"
#include "internal/enumerations.hpp"
#include "internal/internal_templates.hpp"
#include "internal/definitions.hpp"

__attribute__((noinline))
void ramWrite8Bit() {
	/* Define the address and 8-bit value to write */
	unsigned int *address = (unsigned int *) 0x10000000;
	unsigned char value = 0x12;

	writeInternal(address, value, EIGHT_BIT);
}

__attribute__((noinline))
void ramWrite16Bit() {
	/* Define the address and 16-bit value to write */
	unsigned int *address = (unsigned int *) 0x10000000;
	unsigned short value = 0x1234;

	writeInternal(address, value, SIXTEEN_BIT);
}

__attribute__((noinline))
void ramWrite32Bit() {
	/* Define the address and 32-bit value to write */
	unsigned int *address = (unsigned int *) 0x10000000;
	unsigned int value = 0x12345678;

	writeInternal(address, value, THIRTY_TWO_BIT);
}

// TODO Avoid .rodata, do NOT use this template yet
__attribute__((noinline))
void stringWrite() {
	/* Define the string to write (null-terminated) and the address to write it to */
	unsigned char string[] = "Wolfgang\0";
	unsigned int *address = (unsigned int *) 0x10647CFC;

	stringWriteInternal(string, address);
}

__attribute__((noinline))
void skipWrite() {
	/*	Define the start address, the amount of writes, the offset between each write, the increment of
	 	the value after each write, the value to write and the data type of the value */
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
	/* 	Define the starting address, the amount of bytes to write, the value to write into the memory
	 	range and the data type of the value */
	unsigned int *address = (unsigned int *) 0x10647CFC;
	unsigned int length = 0xC;
	unsigned int value = 0x13371338;
	enum dataType dataType = THIRTY_TWO_BIT;

	fillMemoryInternal(address, length, value, dataType);
}

__attribute__((noinline))
void corrupter() {
	/*	Define the starting and ending address for the data corruption,
	 	the value to find, the value to replace it with and the data type of the value */
	unsigned int *startingAddress = (unsigned int *) 0x10647CFC;
	unsigned int *endingAddress = (unsigned int *) 0x10650000;
	unsigned int searchValue = 0x13371338;
	unsigned int searchValueReplacement = 0x12345678;
	enum dataType dataType = THIRTY_TWO_BIT;

	corrupterInternal(startingAddress, endingAddress, searchValue, searchValueReplacement, dataType);
}

__attribute__((noinline))
void searchTemplate() {
	/*	Define the byte search template to be found in the memory, the match count for selecting any of
	 	the matches, the offset between the match and the actual write, the replacement bytes to write,
	 	the starting address in the memory and the ending address for the search */
	unsigned char searchTemplate[] = {0x00, 0x00};
	unsigned int matchCount = 2;
	unsigned int offset = 0x8;
	unsigned char replacement[] = {0x11, 0x12};
	unsigned int *startingAddress = (unsigned int *) 0x10647CFC;
	unsigned int *endingAddress = (unsigned int *) 0x10650000;

	unsigned int searchTemplateArraySize = getArraySize(searchTemplate);
	unsigned int replacementArraySize = getArraySize(replacement);
	writeSearchTemplateInternal(searchTemplate, searchTemplateArraySize, matchCount, offset, replacement,
								replacementArraySize, startingAddress, endingAddress);
}

// TODO Avoid .rodata, do NOT use this template yet
__attribute__((noinline))
void writePointer() {
	/*	Define the pointer's base address, the starting and ending memory ranges for each
	 	offset iteration, the offsets themselves, the value to be written and the data type
	 	of the value */
	unsigned int *baseAddress = (unsigned int *) 0x10000000;
	unsigned int startingMemoryRanges[] = {0x1000000, 0x1300000, 0x1200000};
	unsigned int endingMemoryRanges[] = {0x2000000, 0x2100000, 0x2200000};
	int offsets[] = {0x30, 0x50, -0x70};
	unsigned int value = 0x13371337;
	enum dataType dataType = THIRTY_TWO_BIT;

	int offsetsCount = getArraySize(offsets);
	writePointerInternal(baseAddress, startingMemoryRanges, endingMemoryRanges, offsets, offsetsCount, value, dataType);
}