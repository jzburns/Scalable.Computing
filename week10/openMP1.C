#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
  /* your code goes here */

  #pragma omp parallel
  printf("Hello World!\n");


  /* no code after this comment */
  return 1;
}


