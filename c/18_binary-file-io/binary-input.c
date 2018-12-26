/**************************************************************
* binary-input.c -- A basic program to read an array from a
* 	binary file. This is to be used after binary-output.c
* 
* NOTE: Reading in from a binary file requires knowing the size
*	of the object being read in. I.e. you need to know the
*	type and size of objects that were written to the file
*	in the first place. Then you can declare objects of that
*	size and type and read from the file into those objects.
*
* Author: Leon Hostetler, Jul 16, 2018
*
**************************************************************/
#include <stdio.h>

/* Main Program */
int main()
{

    FILE *input_file;  		   		 /* Binary file to read from */
    input_file = fopen("data.txt", "rb");	 /* Open binary output file for reading */

    /* We know the input file should contain a double array with four elements */
    double myinputarray[4];

    /* Read the array from the binary file */
    fread(&myinputarray, 1, sizeof(myinputarray), input_file);

    /* Close the file */
    fclose(input_file);
    
    /* Let us see what we got by printing the array */
    for(int i=0; i<4; ++i)
	printf(" %lf ", myinputarray[i]);
   
    return(0);
}

