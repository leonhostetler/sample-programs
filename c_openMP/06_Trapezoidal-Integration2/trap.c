/* 

This is a copy of the previous trapezoidal integration program, but
now we use a better way of combing the local results than using
pointers

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

double local_trap(double a, double b, int N);
double f(double x);

int main(int argc, char* argv[])
{
    double a = 0.0;             // The left endpoint
    double b = 1.0;             // The right endpoint
    int N = 4096;               // The number of trapezoids to use
    int threads = 8;            // The number of threads to use

    double result = 0.0;        // This is a global variable to store the total result

    // Now, we run the local_trap() routine in parallel threads
    #pragma omp parallel num_threads(threads)
    {
        double my_result = 0.0;
        my_result += local_trap(a, b, N);
        
        // Notice that we are using the atomic directive instead of critical
        // The atomic directive is preferred when it can be used
        #pragma omp atomic
        result += my_result;
    }

    printf("Result: %f\n", result);

    return 0;
} /* main() */


double local_trap(double a, double b, int N)
/*
    Keep in mind that this function is running in parallel threads
    The idea is to first break the total integration region into chunks--
    one for each thread. Each thread then integrates its own chunk
    using the trapezoid method.
*/
{
    // Which thread am I?
    int my_rank = omp_get_thread_num();
    int threads = omp_get_num_threads();   

    // My (local) variables
    double my_a = my_rank*(b-a)/threads;
    double my_b = my_a + (b-a)/threads;
    int my_N = N/threads;

    // Integrate over my assigned chunk using the trapezoid method
    double x;
    double h = (b-a)/N;
    double my_result = (f(my_a) + f(my_b))/2.0;
    for(int i=1; i<my_N; i++) {
        x = my_a + i*h;
        my_result += f(x);
    }
    my_result = my_result*h;

    // Now instead of updating a global variable via a pointer
    // we simply return our local result
    return my_result;   

} /* local_trap() */


double f(double x)
/*
    In this case, f(x) = x^2
*/
{
    return x*x;
} /* f() */
