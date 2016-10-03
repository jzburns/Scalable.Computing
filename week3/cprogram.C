/*
 * to compile this file: gcc cprogram.C -o cprogram
 * to run this file:  ./cprogram
 */
#include <stdio.h>
#include <stdlib.h>

//declare one of our own functions so the compiler will understand the references below
void printsomething (int , const char* );

//declare an constant integer called arraysz of size 1000
const int arraysz = 1000;

int main (int argc, char** argv) {

  // this is a single line comment

  /*
   * this is a multiline comment
   */

  //integer variable of size 5
  int r = 5;

  //this is an integer array of size arraysz
  int intarray[arraysz];

  printf("The variable r has the value %d", r);

  for (int t = 0; t < 10; t++) {
    printf("t is  %d\n", t);
  }

  if (r > 5) {
      printf("r is greater than 5!\n");
  }

  /* declar a string - use the word const if it will never change */
  const char* name = "Bob";

  //call the function by using its name and giving it correct parameters
  printsomething(6, name);

  return 1;

}

// this is the implementation of the function declared above
void printsomething (int numtimes, const char* something) {
  for (int t = 0; t < numtimes; t++) {
    printf("%s\n", something);
  }
}


