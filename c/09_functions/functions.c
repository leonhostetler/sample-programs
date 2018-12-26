/**************************************************************
* functions.c -- A basic program to practice working with
*       functions in C.
*
* Author: Leon Hostetler, May 4, 2018
*
* Notes: If you want to store your functions at the end (after
* main), you must include 'function prototypes' in the beginning.
* 
**************************************************************/
#include <stdio.h>

/* Global Variables */
int x, y, z;                                                /* three components of a vector */
char line[200];                                             /* character array to store user input */

/* Function Prototypes */
void print_vector(int vector[]);
int dot_product(int vectorA[], int vectorB[]);

/* Main Program */
int main()
{

    /* Read in a 3D vector from the user */
    printf("\nEnter your first vector.\n");
    printf("Enter a vector as three integers separated by spaces: ");
    fgets(line, sizeof(line), stdin);                       /* read user input */
    sscanf(line, "%d %d %d", &x, &y, &z);                   /* convert to numbers */
    int vector1[] = {x, y, z};                              /* assign user inputs to vector 1 */
    printf("\nYou entered the vector:\n");
    print_vector(vector1); 

    /* Read in a 3D vector from the user */
    printf("\nEnter your second vector: ");
    fgets(line, sizeof(line), stdin);                       /* read user input */
    x = 0;                                                  /* set variables back to zero */
    y = 0;
    z = 0;
    sscanf(line, "%d %d %d", &x, &y, &z);                   /* convert to numbers */
    int vector2[] = {x, y, z};                              /* assign user inputs to vector 2 */
    printf("\nYou entered the vector:\n");
    print_vector(vector2); 

    /* Give the user the dot product of the two vectors */
    printf("\nThe dot product of your vectors is %d.\n", dot_product(vector1, vector2));

    return(0);
}

/********************************************************* 
* This function prints the 3D vector that is sent to it.
* This is an example of a function that returns nothing.
* Notice the "void".
**********************************************************/
void print_vector(int vector[3])
{
    printf("<%d, %d, %d>\n", vector[0], vector[1], vector[2]);
    return;
}

/********************************************************* 
* dotproduct -- returns the dot product of a pair of 3D
* integer vectors.
*
* parameters
*      -- the first vector
*      -- the second vector
*
* returns
*      -- the dot product of the two vectors
**********************************************************/
int dot_product(int vectorA[3], int vectorB[3])
{
    int dotproduct = vectorA[0]*vectorB[0] + vectorA[1]*vectorB[1] + vectorA[2]*vectorB[2];
    return (dotproduct);
}
