CC = gcc
DEBUG_FLAGS = -g -Wall
STL = -std=c++11
CFLAGS = $(DEBUG_FLAGS) -O0 # $(STL)
LDFLAGS = -lm

# name the executable
EXE 	= chip8

#OBJ	= 		

EXEOBJ 	= obj/chip8.o

all: bootstrap $(EXE)

# build executable
$(EXE): $(OBJ) $(EXEOBJ) src/*.h
	@echo "LD $@"
	@ $(CC) $(CFLAGS) -o $@ $(OBJ) obj/$@.o $(LDFLAGS)

# build object files
obj/%.o: src/%.c
	@echo "CXX $@"
	@ ${CC} ${CFLAGS} -c $< -o $@

bootstrap:
	@mkdir -p obj

clean:
	rm -f $(EXE)
	rm -f obj/*.o 
	rmdir obj
