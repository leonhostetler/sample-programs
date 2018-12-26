/**************************************************************
* math.c -- A basic program to learn how to use basic math 
*     operations in C.
*
* Author: Leon Hostetler, May 3, 2018
*
* Note: Compile with
*     gcc math.c -lm
*
*               Math Operators
*               ^^^^ ^^^^^^^^^
*
* Include math.h to access common math operators. All the functions
*     in this library take doubles.
*
*
**************************************************************/
#include <stdio.h>
#include <math.h>

double num1 = 5.0;  /* test numbers */
double num2 = 6.8;

int main()
{

    /*
    Instead of using something like num1 = num1 * 2, can use
    num1 *= 2. This works for the other operators as well.
    */
    printf("num1 = %lf, num2 = %lf\n", num1, num2);
    num1 += num2;
    printf("%lf\n", num1);
    num1 /= num2;
    printf("%lf\n", num1);

    /* Some example math.h function results */
    num1 = 2.0;
    num2 = 3.0;
    printf("\nnum1 = %lf, num2 = %lf\n", num1, num2);
    printf("cos(num1) = %lf\n", cos(num1));
    printf("exp(num1) = %lf\n", exp(num1));
    printf("sqrt(num1) = %lf\n", sqrt(num1));
    printf("log(num1) = %lf\n", log(num1));
    printf("sinh(num1) = %lf\n", sinh(num1));
    printf("num1^num2 = %lf\n", pow(num1,num2));

    return(0);
}
