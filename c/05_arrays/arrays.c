/**************************************************************
* arrays.c -- A basic program to learn how to deal with       *
*   various arrays in C.                                      *
*                                                             *  
* Author: Leon Hostetler, May 3, 2018                         *
*                                                             *
***************************************************************/
#include <stdio.h>

int myarray1[5];  /* My uninitialized 1D array of 5 integers */
int myarray2[5] = {1,2,3,4,5}; /* My initialized array of 5 integers */
int myarray3[5] = {};  /* My 1D array initialized with zeros */

int rows = 8;    /* Number of rows for 2D array */
int cols = 10;   /* Number of columns for 2D array */

/**************************************************************
*                      Arrays
*                      ^^^^^
*
* Array indexing in C starts with 0.
*
* C uses a weird way of accessing an element of a multi-dimensional
*     array---multiple brackets.
*
***************************************************************/

int main()
{

    /* Fill the array with various numbers */
    myarray1[0] = 12;
    myarray1[1] = -29;
    myarray1[2] = 48;
    myarray1[3] = 398;
    myarray1[4] = -238;

    /* Print all elements of the 1D array */
    for (int i = 0; i <= 4; ++i) {
        printf("%d   ",myarray1[i]);
    }
    printf("\n");

    /* Print all elements of the 1D array */
    for (int i = 0; i <= 4; ++i) {
        printf("%d   ",myarray2[i]);
    }
    printf("\n");

    /* Print all elements of the 1D array */
    for (int i = 0; i <= 4; ++i) {
        printf("%d   ",myarray3[i]);
    }
    printf("\n");

    int my2darray[rows][cols];  /* Declare a 2D array */

    /* Set all elements of the 2D array to zero */
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < cols; ++k) {
            my2darray[j][k] = 0;
        }
    }

    /* Change the elements of the 2D array */
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < cols; ++k) {
            my2darray[j][k] = j+k;
        }
    }

    /* Print a single element of the 2D array */
    printf("\n%d\n", my2darray[4][6]);

    /* Print all elements of the 2D array */
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < cols; ++k) {
            printf("%4d  ", my2darray[j][k]);
        }
        printf("\n");
    }

    return(0);
}
