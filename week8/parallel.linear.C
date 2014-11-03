/*
 * parallel.linear.C
 * compile with
 * gcc parallel.linear.C -lpthread -lstdc++ -ggdb
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int search_key = 0;
int num_threads = 1;
int* search_array;

int search_size;

void* linearSearch(void *threadid);

void* linearSearch(void *threadid)
{
  long tid = (long) threadid;
  printf("My thread ID is [%lu]\n", tid);

  /*
   * compute the thread workload size
   */
  int thread_work_sz = search_size / num_threads;

  int pos_found = -1;

  for(int i = 0; i < thread_work_sz; i++) {
    int pos = thread_work_sz * tid + i;
    if(search_array[pos] == search_key){
      printf("Key was found at position [%d] by thread [%lu]\n", pos, tid);
      pthread_exit((void*) threadid);
    } 
  }
  pthread_exit((void*) threadid);
}

int main (int argc, char *argv[])
{
   pthread_t threads[100];

   printf("Enter the search key >> ");
   scanf("%d", &search_key);

   printf("Enter the num threads >> ");
   scanf("%d", &num_threads);

   printf("Enter the search size >> ");
   scanf("%d", &search_size);

   search_array = (int *) malloc(sizeof(int)*search_size);

   for(int j = 0; j < search_size; j++) {
     search_array[j] = rand() % search_size;
   }

   /*
    * call the search function
    */

   for(long t = 0; t < num_threads; t++){
      int rc = pthread_create(&threads[t], NULL, linearSearch, (void *)t);
   }

   pthread_exit(NULL);

   return 0;
}
