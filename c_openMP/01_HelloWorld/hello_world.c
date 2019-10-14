/* 
A basic program that uses OpenMP parallelization.

Leon Hostetler, Oct. 14, 2019

USAGE:
(1) Compile with, e.g.
        gcc -g -Wall -fopenmp hello_world.c
(2) Then before running the program, set the number of threads using, e.g.
        export OMP_NUM_THREADS=4
(3) Run the program using
        ./a.out

*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void);       // The function to be run in parallel

int main(int argc, char* argv[])
{

# pragma omp parallel   // This is the most basic parallel directive
    Hello();            // Each of the parallel threads will run this function

    return 0;
}


void Hello(void)
/*
This function is called by parallel threads
The total number of threads is given by omp_get_num_threads()
The current thread is given by omp_get_thread_num()

Note that the output is non-deterministic, since we don't know
which thread will finish first.
*/
{
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    printf("Hello from thread %d of %d\n", my_rank, thread_count);
}
