#include "templates.h"

#define EXIT_SUCCESS 0;

int main_entry(int argc, char **argv) {
	ramWrite8Bit();
	ramWrite16Bit();
	ramWrite32Bit();

	stringWrite();
	skipWrite();

	return EXIT_SUCCESS;
}