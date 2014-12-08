#include <stdio.h>
#include <unistd.h>
#include <omp.h>

static long num_rects = 100000;

int main(int argc, char **argv)
{
	double sum = 0.0;
	double width, pi;
	width = 1.0/(double) num_rects;

  #pragma omp parallel for reduction(+:sum)

	for (int i = 0; i < num_rects; i++){
		double mid = (i + 0.5) * width;
		double height = 4.0/(1.0 + mid * mid);
		sum += height;
	}

	pi = width * sum;

	printf("Pi = %f\n", pi);

}

