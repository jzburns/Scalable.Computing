#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS     5

void *PrintHello(void *threadid);

void *PrintHello(void *threadid)
{
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];

   long t;

   for(t = 0; t < NUM_THREADS; t++){
      int rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
   }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
