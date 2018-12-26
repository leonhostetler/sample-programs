/**************************************************************
* array-structures.c -- A basic program illustrating the use of
*	arrays of structures.
*
* Author: Leon Hostetler, Jul 15, 2018
*
**************************************************************/
#include <stdio.h>

/* If a struct is passed to a function, the struct must be
defined before the function prototype. */

struct complex_struct {
    /* Define a complex number structure */
    double real;       /* the real part      */
    double imag;       /* the imaginary part */
};

/* Set the complex number structure as a new type */
typedef struct complex_struct complex;

struct su3array_struct {
    /* Define a 3x3 complex array structure */
    complex array[3][3];
};

/* Set the complex array structure as a new type */
typedef struct su3array_struct su3array;

/* Function Prototypes */
void cprint(complex num);

/* Main Program */
int main()
{

    /* Initialize an su3array with zeros */
    su3array myfirstsu3array = {};

    /* Print the su3array */
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            cprint(myfirstsu3array.array[i][j]);
        }
        printf("\n");
    }

    /* Add some values to the su3array */
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            myfirstsu3array.array[i][j].real = i;
            myfirstsu3array.array[i][j].imag = j;
        }
        printf("\n");
    }

    /* Print the su3array again*/
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            cprint(myfirstsu3array.array[i][j]);
        }
        printf("\n");
    }

    return(0);
}

/****************************************************************
cprint -- Prints a complex number in the form a + bi

****************************************************************/
void cprint(complex num)
{
    printf(" %f%+fi ", num.real, num.imag);
    return;
}
