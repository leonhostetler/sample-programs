/**************************************************************
* main-program.c -- A simple modular program that uses my simple
* 	module for square matrices contained in square-matrices.c
* 
* Author: Leon Hostetler, Jul 16, 2018
*
**************************************************************/
#include <stdio.h>
#include "square-matrices.h"

/* Main Program */
int main()
{

    /* Declare a couple arrays to play with */
    double array1[3][3];
    double array2[3][3];

    /* Add some elements to the arrays */
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            array1[i][j] = i+j;    
            array2[i][j] = i+j;
        }
    }    

    /* Print the arrays */
    sqarray_print(3,array1);
    printf("\n");   
    sqarray_print(3,array2);
    
    /*
      Add the arrays by declaring a sum array here and 
      instructing the function to add stuff to it.
    */
    double array_sum[3][3];    
    sqarray_add(3, array1, array2, array_sum);

    /* Print the result */
    printf("\n");
    sqarray_print(3,array_sum);


    /* Multiply the arrays by declaring a product array here
       and instructing the function to add stuff to it. */
    double array_product[3][3];
    sqarray_mult(3, array1, array_sum, array_product);

    /* Print the result */
    printf("\n");
    sqarray_print(3,array_product);

    return(0);
}

