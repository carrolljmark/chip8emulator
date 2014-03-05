
// .h file for the corresponding chip8.c

#define MEMORYSIZE 4096
#define NUMREGISTERS 16
#define STACKLEVELS 16

typedef unsigned char byte;
typedef unsigned short word;


typedef struct chip8_cpu{

	word opcode;
	byte memory[MEMORYSIZE];
	byte registers[NUMREGISTERS];
	word address_reg;
	byte stack[STACKLEVELS];
	word program_counter;
	// will need timers, graphics, and sound

} chip8;


void load_game(chip8* c8e);

