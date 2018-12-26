/**************************************************************
* binary-output.c -- A simple program that writes an array to
*	a binary file. This is to be used in conjunction with
*	the script binary-input.c
* 
* Author: Leon Hostetler, Jul 16, 2018
*
**************************************************************/
#include <stdio.h>

/* Main Program */
int main()
{

    FILE *output_file;  			 /* Binary file to write to */
    output_file = fopen("data.txt", "wb");	 /* Create and open binary output file */

    double myarray[] = {1.3,34.3,-43.3,394.0};    /* Create a sample array */

    /* Print the array to the screen */
    for(int i=0; i<4; ++i)
	printf(" %lf ", myarray[i]);

    /* Write the array to the binary file */
    fwrite(&myarray, 1, sizeof(myarray), output_file);

    /* Close the file */
    fclose(output_file);
    
    return(0);
}

