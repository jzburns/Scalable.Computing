#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int SZ = 10;

double calcAvg(int*);

int main (int argc, char** argv) {
	srand(time(NULL));

	int vals[SZ];

	for(int i = 0; i < SZ; i++){
		int r = rand() % 100;	
		vals[i] = r;
	}
	printf("Average is %f \n", calcAvg(vals));
}

double calcAvg(int* vals) {
	double d = 0.0;
	for(int i = 0; i < SZ; i++) {
		d += *vals++;
	}
	return d / SZ;
}
