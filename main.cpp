#include <cstdlib>
#include <cstdio>
#include "src/implementation/templates.hpp"
#include "src/implementation/examples/mario_kart_8.hpp"

#define TABS "\t\t\t"

void testFillMemory32() {
	unsigned int length = 0xC;
	auto *address = (unsigned int *) malloc(length);
	unsigned int value = 0x13371337;
	enum dataType dataType = THIRTY_TWO_BIT;
	fillMemoryInternal(address, length, value, dataType);

	for (int valueIndex = 0; valueIndex < length; valueIndex += getBytesCount(dataType)) {
		if (readInternal(address, dataType) != value) {
			printf("fillMemory32()%sfailed\n", TABS);
			goto AFTER_FILL_MEMORY;
		}
	}

	printf("fillMemory32()%spassed\n", TABS);

	AFTER_FILL_MEMORY:;

	free(address);
}

void testFillMemory8() {
	unsigned int length = 0xC;
	auto *address = (unsigned int *) malloc(length);
	unsigned int value = 0x37;
	enum dataType dataType = EIGHT_BIT;
	fillMemoryInternal(address, length, value, dataType);

	for (int valueIndex = 0; valueIndex < length; valueIndex += getBytesCount(dataType)) {
		if (readInternal(address, dataType) != value) {
			printf("fillMemory8()%sfailed\n", TABS);
			goto AFTER_FILL_MEMORY;
		}
	}

	printf("fillMemory8()%spassed\n", TABS);

	AFTER_FILL_MEMORY:;

	free(address);
}

void testFillMemory() {
	testFillMemory8();
	testFillMemory32();
}

void testWriteSearchTemplate() {

}

int main() {
	randomVR();
	exit(EXIT_SUCCESS);

	testFillMemory();
	testWriteSearchTemplate();

	return EXIT_SUCCESS;
}