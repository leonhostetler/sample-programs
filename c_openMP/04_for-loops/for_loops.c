/* 

Leon Hostetler, Oct. 14, 2019

Here we compare two different approaches to parallelizing a for loop:
    (1) If we have N threads, we can truncate the loop to 1/N of its original
        length and then repeat the loop N times using the "parallel" directive
    (2) We can leave the for loop as it is and use the "parallel for" directive
        which automatically distributes the loop iterations among the N threads

In this script, we do both approaches as well as the sequential approach with
no parallelization, and we compare the time it takes for each of the three approaches.
We also calculate the speedup of the two parallelization approaches. Since the work
is split among the N threads, the maximum and ideal speedup is equal to N.

USAGE:
(1) Compile with (note the -O1 to turn off any vectorization for this test)
        gcc -g -Wall -O1 -fopenmp for_loops.c 
(2) Run the program using e.g.
        ./a.out

When parallizing for loops, special care must be taken. The system is not
smart enough to know when one loop iteration depends on another, so for loops
like that cannot be immediately parallelized.

*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>

// Retrieves current time.
void get_walltime(double* wcTime) {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}

int main(int argc, char* argv[])
{

    double start_time, stop_time, loop1, loop2, loop3;
    int tmp;
    int loop_size = 1073741824;
    int N = 8;  // Number of threads

// No parallelization
    get_walltime( &start_time );
    for(int i=1; i<=loop_size; ++i) {
        tmp = 1;
    }
    get_walltime( &stop_time );
    loop1 = stop_time - start_time;

// Simple parallelization accomplished by reducing the number
// of loop iterations but running the loop in parallel threads
// such that the total loop iterations remains the same
    int end = loop_size/N;
    get_walltime( &start_time );
    # pragma omp parallel num_threads(N)
    for(int i=1; i<=end; ++i) {
        tmp = 1;
    }
    get_walltime( &stop_time );
    loop2 = stop_time - start_time;

// Parallelization using a "parallel for" directive
// The loop iterations are automatically distributed
// to the number of specified threads
    get_walltime( &start_time );
    # pragma omp parallel for num_threads(N)
    for(int i=1; i<=loop_size; ++i) {
        tmp = 1;
    }
    get_walltime( &stop_time );
    loop3 = stop_time - start_time;

// Print timing information
    printf("Times loop1, loop2, loop3: %f %f %f\n", loop1, loop2, loop3);
    printf("Speedup1, speedup2: %f %f\n", loop1/loop2, loop1/loop3);

    return 0;
}
