#include "implementation/templates.hpp"
#include "implementation/examples/mario_kart_8.hpp"

__attribute__((noinline))
void testInlineAssembly() {
	asm volatile(
	"nop\n"
			"nop\n"
			"bne END\n"
			"beq END\n"
			"b END\n"
			"bgt END\n"
			"bgtlr cr7\n"
			"bge END\n"
			"bgtlr cr7\n"
			"blt END\n"
			"bltlr cr7\n"
			"ble END\n"
			"blelr cr7\n"
			"nop\n"
			"END:"
	);
}

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
	testInlineAssembly();
}