#include "implementation/templates.hpp"
#include "implementation/examples/mario_kart_8.hpp"

void main_entry(int argc, char **argv) {
	ramWrite8Bit();
	ramWrite16Bit();
	ramWrite32Bit();
	stringWrite();
	skipWrite();
	fillMemory();
	corrupter();
	searchTemplate();
	writePointer();

	randomVR();
}