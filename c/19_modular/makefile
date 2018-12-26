#-------------------------------------------------#
#            Makefile for UNIX Systems            #
#             using a GNU C compiler              #
#-------------------------------------------------#
# The Makefile is a set of instructions for the
# make utility. It tells make how to compile a
# modular program using gcc.

# The following two lines are macros, e.g., every
# occurrence of $(CC) gets replaced by gcc
CC=gcc
CFLAGS=-g -Wall

# Description of compiler flags
# -g	adds debugging information to the executable
# -Wall	turns on most compiler warnings

# The target for the make utility
all: main-program

# Combine the object files using gcc into a program called "main-program"
main-program: main-program.o square-matrices.o
	$(CC) $(CFLAGS) -o main-program main-program.o square-matrices.o

# Make the object files by combining c and header files
main-program.o: main-program.c square-matrices.h
square-matrices.o: square-matrices.c square-matrices.h

# The command that is run if "make clean" is invoked
clean:
	rm -f main-program main-program.o square-matrices.o
