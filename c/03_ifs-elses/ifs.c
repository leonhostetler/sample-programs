/**************************************************************
* ifs.c -- A basic program to learn how to deal with          *
*   various types of if statements.                           *
*                                                             *  
* Author: Leon Hostetler, May 3, 2018                         *
*                                                             *
***************************************************************/
#include <stdio.h>

int main()
{

    /* Basic if with single statement */
    if (6 < 8)
       printf("Yes, 6 is less than 8\n");     

    /* An if with multiple statements requires curly braces */
    if (6 > 3) {
        printf("\nYes, 6 is more than 3.\n");
        printf("It really is.\n");
    }

    /* An if/else */
    if (5 <= 4) {
        printf("\n5 is less than or equal to 4\n");
    } else {
        printf("\n5 is not less than or equal to 4\n");
    }

    /* An if/elseif */
    if ("apple" == "pear") {
        printf("\nYes, apples are pears.\n");
    } else if ("apple" == "strawberry") {
        printf("\nApples are strawberries.\n");
    } else if ("apple" == "chicken") {
        printf("\nApples are chickens.\n");
    } else {
        printf("\nApples are only apples.\n");
    }


    return(0);
}
