
// Author: 		Mark Carroll
// Date created:	2014/3/3
// What:		CHIP-8 emulator written in C++


#include <stdlib.h>
#include <stdio.h>
#include "chip8.h"


// load game into ram starting at 0x200
void load_game(chip8 *c8e){

    // prompt user for game to play
    char filename[100];
    printf("Enter game to play: ");
    scanf("%99s", filename);
    FILE *input = fopen(filename, "rb");

    // continuously prompt until valid game name found
    while(input == NULL){
	printf("Invalid game name.\nEnter game to play: ");
	scanf("%s", filename);
	input = fopen(filename, "rb");
    }
    printf("You have entered: %s\n\n", filename);

    // attempt to copy game into memory starting at 0x200
    int read_size = fread(c8e->memory+0x200, 1, MEMORYSIZE-0x200, input);
    if(read_size != 0){
	printf("Game read in successfully!\n");
    }else{
	printf("Error reading in game. Exiting....\n");
	exit(0);
    }

}



void cpu_cycle(chip8 *c8e){

    // fetch an opcode
    c8e->opcode = (memory[c8e->program_counter] << 8) | memory[c8e->program_counter+1];

    // decode and execute opcodes
    switch(c8e->opcode & 0xF000){
    case 0x0000:
	break;
    case 0x1000: // jumps to address NNN
	c8e->program_counter = c83->opcode & 0x0FFF;
	break;
    case 0x2000: // calls subroutine at NNN
	c8e->stack[(c8e->stack_pointer++) & 0xF] = c8e->program_counter;
	c8e->program_counter = opcode & 0x0FFF;
	break;
    case 0x3000: // skips the next instruction is VX equals NN
	if(c8e->registers[(c8e->opcode & 0x0F00) >> 8] == (c8e->opcode & 0x00FF))
	    c8e->program_counter += 4;
	else
	    c8e->program_counter += 2;	       
	break;
    case 0x4000:
	if(c8e->registers[(c8e->opcode & 0x0F00) >> 8] != (c8e->opcode & 0x00FF))
	    c8e->program_counter += 4;
	else
	    c8e->program_counter += 2;	       
	break;
    case 0x5000:
	if(c8e->registers[(c8e->opcode & 0x0F00) >> 8] == c8e->registers[(c8e->opcode & 0x00F0) >> 4])
	    c8e->program_counter += 4;
	else
	    c8e->program_counter += 2;	       
	break;
    case 0x6000:
	break;
    case 0x7000:
	break;
    case 0x8000:
	break;
    case 0x9000:
	break;
    case 0xA000:
	c8e->address_reg = opcode & 0x0FFF;
	c8e->program_counter += 2;
	break;
    case 0xB000:
	break;
    case 0xC000:
	break;
    case 0xD000:
	break;
    case 0xE000:
	break;
    case 0xF000:
	break;
    default:
	printf("Unknown opcode: 0x%X\n", opcode);

    }

}


void print_memory(chip8 *c8e, int start, int end){
    int i, ind=0;
    for(i=start; i<end; i+=0x01){
	ind++;
	if(ind == 8){
	    //printf("\n");
	}
	//printf("0x%03x\n", c8e->memory[i]);
    }
}



int main(int argc, char **argv){
	
    chip8 chip8_cpu;
    load_game(&chip8_cpu);
    //print_memory(&chip8_cpu, 0x200, MEMORYSIZE-0x200);


    return 0;

}
