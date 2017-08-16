#include "templates.h"

void main_entry(int argc, char **argv) {
	ramWrite8Bit();
	ramWrite16Bit();
	ramWrite32Bit();

	stringWrite();
	skipWrite();
	fillMemory();
	corrupter();
	searchTemplate();
}