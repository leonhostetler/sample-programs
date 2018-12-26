/**************************************************************
* loops.c -- A basic program to learn how to deal with        *
*   various types of loops in C.                              *
*                                                             *  
* Author: Leon Hostetler, May 3, 2018                         *
*                                                             *
***************************************************************/
#include <stdio.h>

int number = 0;  /* a simple counter */


/**************************************************************
*                      Loops
*                      ^^^^^
*
* While Loop: The while loop is useful when you don't know the
*     number of iterations that will be required. 
*
* For Loop: The for loop is useful when you know beforehand
*     the number of iterations that will be required. You
*     can declare and initialize the counter variables right
*     within the for loop declaration.
*
***************************************************************/

int main()
{

    /* A basic while statement to print the numbers up to 100 */
    while (number < 101) {
        printf("%d, ", number);
        number++;
    }
    printf("...\n\n");  /* add ellipsis and newline after the final number */

    /* The same example with a for loop */
    for (int i = 0; i < 101; i++) { 
        printf("%d, ", i);
    }
    printf("...\n");

    /* This while loop runs until it is issued the 'break' statement */
    number = 0;  /* reset back to zero */
    while (1) {
        printf("I will not be a bad boy!\n");
        number++;
        if (number == 25)
            break;
    }

    /* The 'continue' statement tells a loop to restart from the top */
    number = 0;
    while (1) {
        if (number == 10) {  /* restart from the top i.e. skip 10 */
            number++;
            continue;
        }
        printf("%d, I will not be a bad boy!\n", number);
        number++;
        if (number == 25)
            break;
    }

    return(0);
}
