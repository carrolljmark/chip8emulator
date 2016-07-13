
# Author:		Mark Carroll <carrolljmark@gmail.com>
# Date created:		2016/07/03
# Description:		Simple makefile

CC = gcc

IDIR = include
SDIR = src
ODIR = obj

ROOT_DIR = $(CURDIR)

CFLAGS = -g -Wall
INCLUDES = -I$(ROOT_DIR)
LFLAGS = -lm

EXE 	= chip8
EXEOBJ 	= $(ODIR)/$(EXE).o

all: bootstrap $(EXE)

# build executable
$(EXE): $(ODIR) $(EXEOBJ)
	@echo "LD $@"
	@ $(CC) $(CFLAGS) $(INCLUDES) -o $@ $(ODIR) $(ODIR)/$@.o $(LFLAGS)

# build object files
$(ODIR)/%.o: $(SDIR)/%.c
	@echo "C $@"
	@ ${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

bootstrap:
	@mkdir -p $(ODIR)

clean:
	rm -f $(EXE)
	rm -f $(ODIR)/*.o
	rmdir $(ODIR)
