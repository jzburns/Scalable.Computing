#include <stdio.h>
#include <omp.h>

int main (void)
{
    int q = 7;
    int t = 9;
    int r = 5;

    #pragma omp parallel for 
    for(int j = 0; j < 10; j++) {
      printf("thread %d: i = %d\n", omp_get_thread_num(), j);
    }

    #pragma omp parallel firstprivate(q,t,r) 
    {
     printf("thread %d: q=%d, r=%d, t=%d\n", omp_get_thread_num(), q,t,r);
    }

    return 0;
}
