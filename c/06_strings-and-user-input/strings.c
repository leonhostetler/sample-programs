/**************************************************************
* strings.c -- A basic program to learn how to deal with      *
*   strings and user inputs in C.                             *
*                                                             *  
* Author: Leon Hostetler, May 3, 2018                         *
*                                                             *
***************************************************************/
#include <stdio.h>
#include <string.h>

char firstname[100];  /* a character array to store a string */
char lastname[100];
char fullname[200];
char yourname[200];
char line[200];       /* generic line read in from user  */
int length;           /* to store the length of a string */
int age;

/**************************************************************
*                      Strings
*                      ^^^^^^^
*
* Include the string.h file when working with strings.
*
* There is no 'string' datatype in C. Rather, strings are 1D
*     character arrays. Such a string will always terminate with
*     the null character.
*
* To print strings, use the %s designation.
*
***************************************************************/

int main()
{

    /*
    To assign a string to a character array, use 'strcpy'. In
    this case, the character arrays can hold strings up to 99
    characters in length, but if we assign a short string like
    "Leon," then firstname will be a string of length 4.
    */
    strcpy(firstname, "Leon");
    strcpy(lastname, "Hostetler");
    
    /* Printing strings */
    printf("My first name is %s.\n", firstname);
    printf("My last name is %s.\n", lastname);

    /* Can also initialize strings as */
    char mystring[] = "Goodness gracious!";
    printf("\n%s\n", mystring);

    /* Concatenating strings */
    strcpy(fullname, firstname);
    strcat(fullname, " ");
    strcat(fullname, lastname);
    printf("My full name is %s.\n", fullname);

    /* Getting the length of strings */
    length = strlen(fullname);
    printf("My full name is %d characters long.\n", length);

    /* Comparing two strings */
    if (strcmp(firstname, lastname) == 0) {
        printf("My first and last names are the same.\n");
    } else {
        printf("My first and last names are different.\n");
    }

    /* Reading in a string from the user */
    printf("\nWhat is your name? Enter your name here: ");  /* prompt the user */
    fgets(yourname, sizeof(yourname), stdin);               /* read user input */
    yourname[strlen(yourname)-1] = '\0';                    /* replace newline character with end of string character */
    printf("\nYou said your name is %s.\n", yourname);      /* print results   */

    /* Reading in a number from the user */
    printf("\nHow old are you? ");
    fgets(line, sizeof(line), stdin);                       /* read user input */
    sscanf(line, "%d", &age);                               /* convert to number. Note the '&' */
    printf("You are %d years old.\n", age);







    return(0);
}
