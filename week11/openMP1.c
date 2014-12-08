#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main (int argc, char *argv[]) 
{
  int r = 5;
  int t = 11;
  int array[N];

  /*
   * workload partitioning across threads (in a for loop) is very 
   * common in a parallel program. 
   * OpenMP calls this a 'parallel for'
   */
  #pragma omp parallel for
  for (int i = 0; i < N; i++){
    array[i] = i;
    /*
     * each openMP thread gets an ID
     */
    printf("My thread ID is %d\n", omp_get_thread_num()); 
  }
  /* implicit thread barrier here */

  printf("Outside parallel section:r=%d t=%d\n", r,t);
  return 1;
}


