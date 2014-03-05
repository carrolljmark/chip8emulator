
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



void print_memory(chip8 *c8e, int start, int end){
	int i, ind=0;
	for(i=start; i<end; i+=0x01){
		ind++;
		if(ind == 8){
			//printf("\n");
		}
		printf("0x%03x\n", c8e->memory[i]);
	}
}



int main(int argc, char **argv){
	
	chip8 chip8_cpu;
	load_game(&chip8_cpu);
	print_memory(&chip8_cpu, 0x200, MEMORYSIZE-0x200);


	return 0;

}
