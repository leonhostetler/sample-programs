main-program is a sample modular program. To run it, use
	./main-program


To build the program, use
	make


To build the program from scratch, i.e. to delete the existing executable and object files, first clean out the existing files by running
	make clean
Then to rebuild the program, use
	make

########################################
#
# DESCRIPTION
#
########################################

The program consists of three files written in c:
	square-matrices.h -- The header file associated with the square matrices module. It must be included in any script that uses the functions from the square-matrices module since it contains the function prototypes and definitions.
	main-program.c	  -- This is the main program
	square-matrices.c -- This is contains the functions of the square-matrices module


To create this program, which is broken into several pieces, we use the UNIX make utility. This utility uses the information in the file "makefile" to compile the modular program. When we do this, make creates a compiled executable called "main-program".









