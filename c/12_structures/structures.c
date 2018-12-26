/**************************************************************
* structures.c -- A basic program illustrating the use of
*	structures in c
*
* Author: Leon Hostetler, Jul 15, 2018
*
**************************************************************/
#include <stdio.h> 					/* this is a standard header file */

/* Main Program */
int main()
{

    struct complex_struct {
	/* Define a complex number */
        double real;       /* the real part */
        double imag;  /* the imaginary part */
    };

    /* Initialize a pair of complex number */
    struct complex_struct mynum1 = {1.0,2.0};
    struct complex_struct mynum2 = {3.0,2.0};

    /* The nice thing about structures is how easy it is to access their elements */
    printf("\nThe complex number is %f + %fi\n", mynum1.real, mynum1.imag);
    printf("The real part is %f\n", mynum1.real);
    printf("The imaginary part is %f\n", mynum1.imag);

    /* Change the imaginary part on one of them*/
    mynum2.imag = 4383.01;

    printf("\nThe complex number is %f + %fi\n", mynum2.real, mynum2.imag);
    printf("The real part is %f\n", mynum2.real);
    printf("The imaginary part is %f\n", mynum2.imag);

    /* It is often useful to define a structure as a new 'type'
       Here, we will create a new type called "complex" using
       the structure defined above.
    */
    typedef struct complex_struct complex;

    /* Now I define a complex variable as */
    complex mycomplex = {223.2, -32};
    printf("\nThe complex number is %f + %fi\n", mycomplex.real, mycomplex.imag);
    printf("The real part is %f\n", mycomplex.real);
    printf("The imaginary part is %f\n", mycomplex.imag);
   
    return(0);
}
