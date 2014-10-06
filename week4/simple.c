#include <stdio.h>

void test(int value);

int main (int argc, char** argv) {
	int data [1000000];
	test(5);
	printf("The end of main\n");
}

void test(int value) {
	if(value > 10){
		printf("Thats a big number\n");
	}
	
	for(int i = 0; i < 10; i++){
		printf("Hello from the loop\n");
	}
	printf("The end of the function\n");
}

