#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char** argv) {
/**
  #pragma omp parallel
  {
    //expect 4 threads to run
    printf("Tid is %d\n", omp_get_thread_num());
  }
  //parallel region ends here
  //barrier

  int n = 8;
  #pragma omp parallel for
  for(int i = 0; i < n; i++){
    printf("FOR Tid is %d\n", omp_get_thread_num());
  }
**/
  int sz = 1000000;
  int uppr = 0;
  int lwr = 0;
  int data[sz];

  for(int i = 0; i < sz; i++){
    int r = rand() % 100;	
    data[i] = r;
  }

  scanf("%d",&lwr);
  scanf("%d",&uppr);

  int cnt = 0;

  for(int i = 0; i < sz; i++){	
    if(data[i] >= lwr && data[i] <= uppr)
      cnt++;
  }

  printf("ST Found %d\n", cnt);

  /*
   * reduction problem:
   * (a) using a global var
   * (b) global is assigned a value in the for loop
   * (c) global is referenced after the for loop
   */
  cnt = 0;

  #pragma omp parallel for reduction (+:cnt)
  for(int i = 0; i < sz; i++){	
    if(data[i] >= lwr && data[i] <= uppr)
      cnt++;
  }

  printf("MT Found %d\n", cnt);

  return 0;
}
