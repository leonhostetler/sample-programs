/* 

This is a copy of the previous trapezoidal integration program, but
now we use a parallel for directive in the local_trap function instead
of a parallel directive in the main function

Leon Hostetler, Oct. 14, 2019

USAGE:
(1) Compile with, e.g.
        gcc -g -Wall -fopenmp trap.c
(2) Run the program using
        ./a.out

*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double trap(double a, double b, int N);
double f(double x);

int main(int argc, char* argv[])
{
    double a = 0.0;             // The left endpoint
    double b = 1.0;             // The right endpoint
    int N = 4096;               // The number of trapezoids to use
    int threads = 8;            // The number of threads to use

    double result;              // This is a global variable to store the total result

    // Integrate
    result = trap(a, b, N);

    printf("Result: %f\n", result);

    return 0;
} /* main() */


double trap(double a, double b, int N)
/*
    This function itself is now only running in a single thread
    Within this function, additional threads are created to do
    the for loop. Now the iterations are automatically distributed
    to the threads, so we can focus on the big picture.
*/
{
    int threads = omp_get_num_threads();  
    double h = (b-a)/N;
    double result = (f(a) + f(b))/2.0;

    // Parallelize the for loop
    #pragma omp parallel for num_threads(threads) reduction(+: result)
    for(int i=1; i<N; i++) {
        result += f(a + i*h);
    }
    result = result*h;

    return result;   

} /* local_trap() */


double f(double x)
/*
    In this case, f(x) = x^2
*/
{
    return x*x;
} /* f() */
