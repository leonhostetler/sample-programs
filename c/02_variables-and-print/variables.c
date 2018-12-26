/**************************************************************
* variables.c -- A basic program to learn how to declare and
*   print variables
*
* Author: Leon Hostetler, May 2, 2018
*
*
*               Variable Declarations
*               ^^^^^^^^ ^^^^^^^^^^^^
* - Variables cannot begin with a number, a special character
*       or contain spaces. Remember, c is case-sensitive!!
*
* int: Integers are from -32768 to 32768 on Windows machines
*      and about -2^31 to 2^31 on Unix machines. Beware that 
*      integer division (i.e. division of one integer by
*      another will result in a rounded answer with no decimal
*      part.
*
* float: Decimals should always include a decimal point (e.g.
*      write 0.0 instead of 0). Make sure to use %f when printing
*      decimals.
*
* double: Double precision floats. Print using %lf (long float)
* 
* char: Characters take single quotes and strings take double 
*       quotes. Use %c when printing them.
*
**************************************************************/
#include <stdio.h>

int myinteger;                      /* declare test integer */
float myfloat;                      /* declare test float   */
float avogadro;                     /* to test large float  */
const float PI = 3.14159;           /* Use the const type for all constants */
int myint1, myint2, myint3;         /* Can declare multiple variables per line */
char char1, char2;                  /* declare test characters */

int main()
{

    /* Assign values to the integers and print them */
    myinteger = 657;  /* Assign a value to the integer */
    printf("My integer is %d!\n", myinteger);
    printf("Twice %d is %d!\n", myinteger, 2*myinteger);

    /* Be careful that you have the right number of 
    expressions. In this case, I will print that 
    2 + 3 = garbage because I forgot to add myint3
    to the string of expressions when printing. */
    myint1 = 2;
    myint2 = 3;
    myint3 = myint1 + myint2;
    printf("\n%d + %d = %d\n", myint1,myint2);

    /* Assign values to the floats and print them */
    myfloat = 87883.88;
    avogadro = 6.022e23;
    printf("\nmyfloat is %f, and Avogadro's number is %f.\n", myfloat, avogadro);
    printf("\nPi is about %f\n", PI);

    /* Assign values to characters and print them */
    char1 = 'A';
    char2 = 'B';
    printf("\nMy characters are %c and %c\n.", char1, char2);

    return(0);
}




