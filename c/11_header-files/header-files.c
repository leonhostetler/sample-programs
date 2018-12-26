/**************************************************************
* header-files.c -- A basic program illustrating the use of
*	header files in c
*
* Author: Leon Hostetler, Jul 15, 2018
*
**************************************************************/
#include <stdio.h> 					/* this is a standard header file */
#include "const.h"					/* this is a custom header file   */

/* Main Program */
int main()
{

    /* Read in a number from the user */
    printf("\nPi is approximately  %lf\n", PI);

    return(0);
}


