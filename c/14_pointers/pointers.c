/**************************************************************
* pointers.c -- A basic program illustrating the use of
*	pointers in c.
* 
* NOTE: When an array is passed to a function, c automatically
*	only passes a pointer to the array.
*
* Author: Leon Hostetler, Jul 16, 2018
*
**************************************************************/
#include <stdio.h>

/* Function Prototypes */
void addtopointer(int *mypointer);

/* Main Program */
int main()
{

    int mynum = 5;
    printf("\nMy num is currently %d\n", mynum);

    /* Pass the address of mynum to a function which adds
	a number to the thing being pointed to. Note the
	ampersand which is the "addressof" operator. Attaching
	an ampersand like this makes &mynum and pointer to
	mynum.
     */
    addtopointer(&mynum);
    printf("\nMy num is now %d\n", mynum);
    
    return(0);
}

/****************************************************************
addtopointer -- This function takes in a pointer and adds 3 to
	the thing being pointed to. Note the asterisk in the 
	parameter list which denotes that the incoming parameter
	is a pointer.
****************************************************************/
void addtopointer(int *mypointer)
{
    /* The asterisk tells us that 3 is being added not to 
	the variable mypointer, but to the thing which the
	pointer called mypointer is pointing to.
    */
    *mypointer += 3;
}
