/* 

Oct. 14, 2019

USAGE:
(1) Compile with, e.g.
        gcc -g -Wall -fopenmp cmd_line.c
(2) Run the program using e.g.
        ./a.out 11

For best performance, the number of threads should typically be
equal to the number of processor cores.

*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void);

int main(int argc, char* argv[])
{

// Get the number of threads to use from the command line
int threads = strtol(argv[1],NULL, 10);

// Create a parallel block with this number of threads
# pragma omp parallel num_threads(threads)
    Hello();

    return 0;
}


void Hello(void)
{
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    printf("Hello from thread %d of %d\n", my_rank, thread_count);
}
