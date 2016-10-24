/*
 * comple with g++ -fopenmp week5.C
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

const int SZ = 1000000;

double calcAvg(int*);

int main (int argc, char** argv) {
	srand(time(NULL));

	int vals[SZ];
	int val1 = 67;
	int val2 = 99;

	for(int i = 0; i < SZ; i++){
		int r = rand() % 100;	
		vals[i] = r;
	}

	int cntr = 0;
	for(int i = 0; i < SZ; i++){
		if(vals[i] >= val1 && vals[i] <= val2) {
			cntr++;
		}
	}

	printf("ST result: %d\n", cntr);	

	cntr = 0;

	//nested
	omp_set_nested(1);

	#pragma omp parallel num_threads(2)
	{
		printf("thread id: %d\n", omp_get_thread_num());  
		#pragma omp parallel for 
		for(int i = 0; i < 4; i++){
			printf("FOR thread id: %d\n", omp_get_thread_num());  
		}
	}

	#pragma omp parallel for reduction (+:cntr)
	for(int i = 0; i < SZ; i++){
		if(vals[i] >= val1 && vals[i] <= val2) {
			cntr++;
		}
	}

	printf("MT result: %d\n", cntr);	
	
}

