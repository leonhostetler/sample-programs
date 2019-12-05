/*
    A basic CUDA demonstration. Two random vectors are added together
    in serial and using a GPU accelerator.

    To compile, use:
        make

    NOTE: CUDA must be installed/loaded before running make. Also, the
          Makefile will probably have to be customized for your system.

    To run, use for example:
        ./cuda_vecadd 100000000
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <cuda.h>


// Add two vectors in serial
void vecAdd(double *h_A, double *h_B, double *h_C, int n)
{
    for( int i = 0; i < n; i++ )
        h_C[i] = h_A[i] + h_B[i];
}


// The CUDA vector addition kernel
__global__
void cudaVecAddKernel( double* A, double* B, double* D, int n)
{
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if(i<n) D[i] = A[i] + B[i];
}


// Add two vectors in CUDA
void cuda_vecAdd(double *h_A, double *h_B, double *h_D, int n)
{
    int size = n * sizeof(double);
    double *d_A, *d_B, *d_D;
    cudaError_t err1 = cudaSuccess;
    cudaError_t err2 = cudaSuccess;
    cudaError_t err3 = cudaSuccess;

    // Allocate memory on the GPU
    err1 = cudaMalloc((void **) &d_A, size);
    err2 = cudaMalloc((void **) &d_B, size);
    err3 = cudaMalloc((void **) &d_D, size);

    if(err1 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err1), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(err2 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err2), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(err3 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err3), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // Copy the data to the GPU
    err1 = cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    err2 = cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    if(err1 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err1), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(err2 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err2), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // CUDA kernel
    int threads = 1024;                         // Threads per block
    int blocks = (n + threads - 1) / threads;   // Blocks per grid
    printf("\n  CUDA kernel was launched with %d blocks of %d threads...", blocks, threads);
    cudaVecAddKernel<<<blocks, threads>>>(d_A, d_B, d_D, n);

    err1 = cudaGetLastError();
    if(err1 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err1), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // Copy the results back to the host
    err1 = cudaMemcpy(h_D, d_D, size, cudaMemcpyDeviceToHost);

    if(err1 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err1), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // Deallocate memory on the GPU
    err1 = cudaFree(d_A);
    err2 = cudaFree(d_B);
    err3 = cudaFree(d_D);

    if(err1 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err1), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(err2 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err2), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(err3 != cudaSuccess) {
        printf("\n%s in %s at line %d\n", cudaGetErrorString(err3), __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
}


// Timer
double getTime()
{
    struct timeval TV;
    struct timezone TZ;

    const int RC = gettimeofday(&TV, &TZ);

    return( ((double)TV.tv_sec) + ((double)TV.tv_usec)*1.0e-6 );

}


// Main program
int main (int argc, char** argv)
{
    unsigned int n, i;
    double t0, t1, t2, t3;
    
    n = atoi(argv[1]);
    printf("\nn = %d", n);

    double * A = (double*) malloc( n * sizeof(double) );
    double * B = (double*) malloc( n * sizeof(double) );
    double * C = (double*) malloc( n * sizeof(double) );
    double * D = (double*) malloc( n * sizeof(double) );

    for (i = 0; i < n; ++i) {
        A[i] = ((double) rand()/RAND_MAX);
        B[i] = ((double) rand()/RAND_MAX);
    }

    // Add the two vectors in serial
    t0 = getTime();
    vecAdd(A, B, C, n);
    t1 = getTime();
    printf("\n  Serial addition: %f sec.", t1 - t0);

    // Add the two vectors using CUDA
    t2 = getTime();
    cuda_vecAdd(A, B, D, n);
    t3 = getTime();
    printf("\n  CUDA addition:   %f sec.\n\n", t3 - t2);

    // Verify that the two results are the same
    for (i = 0; i < n; ++i) {
        if( C[i] != D[i])
        {
            printf("\nERROR! Outputs do not match at index %d", i);
            break;
        }
    }

    // Free host memory
    free(A);
    free(B);
    free(C);
    free(D);

    return 0;
}
