// CS4348.006
// OS Project1
// Kent Templin, Andrew N, Andres F

#include <cstdio>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <math.h> 
using namespace std;

// global variables
int max_digit_to_calc = 0;
long number1[256];      // store digit numbers of first number
long number2[256];      // store digit numbers of second number
long product[512];      // store product numbers from each thread calculations.
long big_number;        // a bigger number. Ex. 23958233
bool is_number1_bigger; // a flag that indicates if number1 is a bigger number.

// multiply function 
void *
multiply(void *arg) {

  // initialiing own thread id #
  int tid = (long)arg;

  // Calculate product.
  // Run this when number1 is bigger.
  if (is_number1_bigger == true) {
    // calculate product and store it to an array.
    long x = number2[tid] * (pow(10, tid));
    product[tid] = big_number * x;

    // display result
    printf("T%d: %ld * %ld \n", tid, big_number, x);
    printf("T%d: product[%d] = %ld\n", tid, tid, product[tid]);

  }
  // Run this when number2 is bigger.
  else {
    // calculate product and store it to an array.
    int x = number1[tid] * (pow(10, tid));
    product[tid] = x * big_number;

    // display result
    printf("T%d: %ld * %ld \n", tid, big_number, x);
    printf("T%d: product[%d] = %ld\n", tid, tid, product[tid]);

  }
  cout << endl;


  return NULL;
}



// method to get a product.
long multiplyLongs(long num1, long num2) {
  return num1 * num2;
}


int main() {
  // store the 3 numbers from the file
  int threadCount;
  long num1, num2;

  // reading the file and storing the 3 numbers variables
  ifstream theFile("input.txt");
  theFile >> threadCount >> num1 >> num2;

  // displaying variables that we read from input txt.
  printf("Thread amount:\t %d\n", threadCount);
  printf("Number 1:\t\t %ld\n", num1);
  printf("Number 2:\t\t %ld\n", num2);
  printf("Product:\t\t %ld\n\n", multiplyLongs(num1, num2));

  // pthread
  // array of pthreads
  pthread_t threads[threadCount];

  //
  int index = 0;
  long num1Math = num1;
  long num2Math = num2;

  // loop to extract the individual digits of num1 and place them in the array number1
  while (num1Math > 0) {
    number1[index] = num1Math % 10;
    num1Math /= 10;
    index++;
  }

  // reset index
  index = 0;

  // loop to extract the individual digits of num2 and place them in the array number2
  while (num2Math > 0) {
    number2[index] = num2Math % 10;
    num2Math /= 10;
    index++;
  }

  // Prints the values of array number1
  for (int i = 0; i < to_string(num1).length(); i++) {
    printf("number1 index: %d = %ld\n", i, number1[i]);
  }
  cout << endl;

  // Prints the values of array number2
  for (int i = 0; i < to_string(num2).length(); i++) {
    printf("number2 index: %d = %ld\n", i, number2[i]);
  }
  cout << endl;

  // error message on this one
  // printf("Index: 8 = %ld\n", number2[8]);


  // Figure out the # of maximum digits to calc.
  // (and store data to global variables to be able to perform multi-threading.)
  printf("Number 1:\t\t%ld\n", num1);
  printf("Number 2:\t\t%ld\n", num2);
  if (num1 >= num2) {
    printf("num1 is greater or equal to num2.\n");
    is_number1_bigger = true;                       // need this in multi-threading
    printf("Digit # of num2:\t%d\n", (to_string(num2).length()));
    max_digit_to_calc = (to_string(num2).length());     // store in global variable
    big_number = num1;              // store bigger number in global variable
    printf("Max digit # to calc:\t%d\n", max_digit_to_calc);
  }
  else {
    printf("num2 is bigger.\n");
    is_number1_bigger = false;                      // need this in multi-threading
    printf("Digit # of num1:\t%d\n", (to_string(num1).length()));
    max_digit_to_calc = (to_string(num1).length());     // store in global variable
    big_number = num2;              // store bigger number in global variable
    printf("Max digit # to calc:\t%d\n", max_digit_to_calc);
  }
  cout << endl;


  // Figure out if there are enough threads to calculate for each digit #s.
  if (threadCount >= max_digit_to_calc) {
    printf("Enough thread. Good to proceed.\n");
  }
  else {
    printf("Not enough thread. Please increase # of threads to execute program.\n");
    printf("(Ex. 10 threads >= 10 digits ) \n");
    return EXIT_FAILURE;
  }
  cout << endl;


  // Multi-threading. Each thread executes function "multiply"
  for (int i = 0; i < max_digit_to_calc; i++) {
    pthread_create(&threads[i], NULL, multiply, (void *)i);
  }

  for (int i = 0; i < max_digit_to_calc; i++) {
    pthread_join(threads[i], NULL);
  }


  // calculate sum of all arrays elements.
  long sum = 0;
  for (int i = 0; i < max_digit_to_calc; i++) {
    sum = sum + product[i];
  }


  // display sum
  printf("sum:\t%ld\n\n", sum);

  ofstream ofile("output.txt");
  ofile << "Product Result: " << sum;
  ofile.close();

  printf("Program complete.\n");
  return 0;
}
