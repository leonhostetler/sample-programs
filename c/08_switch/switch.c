/**************************************************************
* switch.c -- A basic program to practice the switch
*       statement in C.
*
* Author: Leon Hostetler, May 4, 2018
*
* The general form of a switch statement:
*
* switch (expression) {
*     case constant1:
*         statement1;
*         statement2;
*             .
*             .
*             .
*         break;
*     case constant2:
*         statement1;
*             .
*             .
*             .
*     default:
*         defaultstatements;
*         break;
* }
*
* NOTE: Switch only works when the cases are integers or 
*     single characters. It doesn't work on strings.
*
**************************************************************/
#include <stdio.h>

char line[200];  /* user text input */
int num;         /* user number input */

int main()
{

    /* Read in a number from the user */
    printf("\nEnter a number from 0 to 9 for a random fact related to that number: ");
    fgets(line, sizeof(line), stdin);                       /* read user input */
    sscanf(line, "%d", &num);                               /* convert to number. Note the '&' */

    switch (num) { 
        case 0:
            printf("This is a number.\n");
            break;

        case 1:
            printf("\nOne\n");
            break;

        case 2:
            printf("two two\n");
            break;

        case 3:
            printf("1 + 1 + 1\n");
            break;

        case 4:
            printf("2*2 = 2^2\n");
            break;

        case 5:
            printf("sqrt(25).\n");
            break;

        case 6:
            printf("six six six six six six six six six six six six six\n");
            break;

        case 7:
            printf("42/6\n");
            break;

        case 8:
            printf("The number of sides in a square. Just kidding.\n");
            break;

        case 9:
            for (int i = 0; i < 9; ++i) {
                printf("Here are 9 lines:\n");
            }
            break;

        default:
            printf("\nThat was not an appropriate number. Bye!\n");
            break;
    }

    return(0);
}
