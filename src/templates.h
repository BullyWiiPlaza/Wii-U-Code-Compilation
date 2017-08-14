#pragma once

#include "utilities.h"
#include "enumerations.h"
#include "internal_templates.h"

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