/* 
This is a copy of the basic hello world application, but made safe for
compilers that don't support OpenMP. If there is no OpenMP support, this
program is run sequentially. I.e. without parallelization. This is 
accomplished by wrapping OpenMP stuff in ifdef statements.

Leon Hostetler, Oct. 14, 2019

USAGE (SEQUENTIAL):
(1) Compile with, e.g.
        gcc -g -Wall seq_safe.c
(2) Run the program using
        ./a.out

USAGE (PARALLEL):
(1) Compile with, e.g.
        gcc -g -Wall -fopenmp seq_safe.c
(2) Then before running the program, set the number of threads using, e.g.
        export OMP_NUM_THREADS=4
(3) Run the program using
        ./a.out

*/

#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#endif

void Hello(void);       // The function to be run in parallel

int main(int argc, char* argv[])
{

# pragma omp parallel   // This is the most basic parallel directive
                        // This pragma is ignored when compiled sequentially
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
    #ifdef _OPENMP
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    printf("Hello from thread %d of %d\n", my_rank, thread_count);
    #else
    printf("Hello from the only thread\n");
    #endif
}
