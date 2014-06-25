
// .h file for the corresponding chip8.c

#define MEMORYSIZE 4096
#define NUMREGISTERS 16
#define STACKLEVELS 16

typedef unsigned char byte;
typedef unsigned short word;


typedef struct chip8_cpu{

    word opcode = 0;
    byte memory[MEMORYSIZE];
    byte registers[NUMREGISTERS];
    word address_reg = 0;
    byte stack[STACKLEVELS];
    word program_counter = 0;
    word stack_pointer = 0;
    // will need timers, graphics, and sound

} chip8;


void load_game(chip8* c8e);

