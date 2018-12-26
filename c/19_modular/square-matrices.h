/**************************************************************
* square-matrices.h -- A simple modular program that uses my simple
* 	module for square matrices contained in square-matrices.c
* 
* NOTE: This is the header file for the square-matrices module.
*	It must be "included" in scripts that use square-matrices.c.
*       Basically, the header file contains the function prototypes,
*       their definitions, and structure definitions.
*
* Author: Leon Hostetler, Jul 16, 2018
*
**************************************************************/

/* Function Prototypes */

/***********************************************************
array_print -- A function that prints a square array.

parameters
  size -- the size of the array
  array -- the array to print
***********************************************************/
void sqarray_print(int size, double array[][size]);

/***********************************************************
array_add -- A function that adds two square arrays.

parameters
  size -- the size of the arrays
  arr1, arr2 -- the arrays to add
  arrsum -- the array to put the sum into
***********************************************************/
void sqarray_add(int size, double arr1[][size], double arr2[][size], double arrsum[][size]);

/***********************************************************
array_mult -- A function that multiplies two square arrays.

parameters
  size -- the size of the arrays
  arr1, arr2 -- the arrays to multiply
  arrprod -- the array to put the product into
***********************************************************/
void sqarray_mult(int size, double arr1[][size], double arr2[][size], double arrprod[][size]);
