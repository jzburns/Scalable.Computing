#include <stdio.h>
#include <omp.h>
#include <time.h>

#define N 10

int main (void)
{
    int q = 7;
    int t = 9;
    int r = 5;

    #pragma omp parallel 
    if (omp_get_thread_num() == 0 ) {
      int nthreads = omp_get_num_threads();
      printf("There are %d threads\n",nthreads);
    }

    clock_t tic = clock();

    //this is your work
    #pragma omp parallel for 
    for(int j = 0; j < N; j++) {
      int tid = omp_get_thread_num();
      printf("thread %d: j = %d\n", tid, j);
    }

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", 
      (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}
