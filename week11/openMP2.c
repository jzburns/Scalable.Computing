#include <stdio.h>
#include <omp.h>

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

    #pragma omp parallel for 
    for(int j = 0; j < 10; j++) {
      int tid = omp_get_thread_num();
      printf("thread %d: i = %d\n", tid, j);
    }

    #pragma omp parallel firstprivate(q,t,r) 
    {
     printf("thread %d: q=%d, r=%d, t=%d\n", omp_get_thread_num(), q,t,r);
    }

    return 0;
}
