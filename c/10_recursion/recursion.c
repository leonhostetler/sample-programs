/**************************************************************
* recursion.c -- A basic program containing a function with
*	an example of recursion.
*
* Author: Leon Hostetler, Jul 15, 2018
*
**************************************************************/
#include <stdio.h>

/* Global Variables */
int num;                                                    /* number to take factorial of */
char line[200];                                             /* character array to store user input */

/* Function Prototypes */
int factorial(int mynum);

/* Main Program */
int main()
{

    /* Read in a number from the user */
    printf("\nEnter a smallish integer.\n");
    fgets(line, sizeof(line), stdin);                       /* read user input */
    sscanf(line, "%d", &num);                               /* convert to number */
    printf("\nYou entered the number: %d\n", num );

    printf("\nThe factorial of %d is %d.\n", num, factorial(num));

    return(0);
}


/********************************************************* 
* factorial -- This function uses recursion to compute
*	the factorial of a number
*
* parameters
*      -- the integer
*
* returns
*      -- the factorial of the integer
**********************************************************/
int factorial(int mynum)
{
    if (mynum==0)
        return 1;
    /* else */ 
    return mynum*factorial(mynum-1);
}
