/**************************************************************
* square-matrices.c -- This is a sample module containing
* 	functions to work with square matrices.
*
* Routines
*
*     squarray_print -- Prints the array
*     squarray_add   -- Adds two arrays
*     squarray_mult  -- Multiplies two arrays
* 
* Author: Leon Hostetler, Jul 16, 2018
*
**************************************************************/
#include <stdio.h>

/***********************************************************
array_print -- A function that prints a square array.

parameters
  size -- the size of the array
  array -- the array to print
***********************************************************/
void sqarray_print(int size, double array[][size])
{
    int i, j;
    for(i=0; i<size; ++i) {
        for(j=0; j<size; ++j) {
            printf(" %lf ", array[i][j]);
        }
        printf("\n");
    }
}

/***********************************************************
array_add -- A function that adds two square arrays.

parameters
  size -- the size of the arrays
  arr1, arr2 -- the arrays to add
  arrsum -- the array to put the sum into
***********************************************************/
void sqarray_add(int size, double arr1[][size], double arr2[][size], double arrsum[][size])
{

    /* Add the elements */
    int i, j;
    for(i=0; i<size; ++i) {
        for(j=0; j<size; ++j) {
            arrsum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}


/***********************************************************
array_mult -- A function that multiplies two square arrays.

parameters
  size -- the size of the arrays
  arr1, arr2 -- the arrays to multiply
  arrprod -- the array to put the product into
***********************************************************/
void sqarray_mult(int size, double arr1[][size], double arr2[][size], double arrprod[][size])
{

    double sum;
    int i,j,k;

    /* Multiply the elements */
    for(i=0; i<size; ++i) {
        for(j=0; j<size; ++j) {
            sum = 0.0;
            for(k=0; k<size; ++k) {
                sum += arr1[i][k]*arr2[k][j];
            }
            arrprod[i][j] = sum;
        }
    }
}
