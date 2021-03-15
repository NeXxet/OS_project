// OS Project
// Kent, Andrew, Andres

#include <cstdio>
#include <iostream>
#include <fstream>
#include <pthread.h>

using namespace std;


// global variables
int global_c = 0;   // global counter 
long number1[256];   // store digit numbers of first number
long number2[256];   // store digit numbers of second number

void *
//int
multiply(void *){
    printf("multiply function working.\n");
    printf("global_c = %d\n", global_c);
    //printf("global_number1[%d]=%ld\n", global_counter, global_number1[global_counter]);

    // 10 ^ x = digit multiplication.

    //global_answer = global_number1[globalcounter]*global_number2[globalcounter];

    global_c ++;
    return NULL;
}












// method will probably need to be updated when we incorporate multi-threading
long multiplyLongs(long num1, long num2) {
    return num1 * num2;
}

// struct for parameters
// struct is needed when parameter amount is > 1
struct argStruct {
    int arg1;   // pthread counter
    long arg2;  // number 1 from file
    long arg3;  // number 2 from file
};

// test method to test thread creation
void* threadTest(void* arguments) {
    auto* args = static_cast<argStruct*>(arguments);
    args -> arg1++;
    printf("Thread %d is starting\n", args -> arg1);
    printf("Number 1: %ld\n", args -> arg2);
    printf("Number 2: %ld\n", args -> arg3);
    printf("Thread %d is ending\n\n", args -> arg1);
}


int main() {

    // store the 3 numbers from the file
    int threadCount;
    long num1, num2;

    // moved these variables to global variables
        // arrays that will store 256 digits of each number
        //long number1[256];   // store digit numbers of first number
        //long number2[256];   // store digit numbers of second number

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
    struct argStruct args;
    args.arg1 = 0;
    args.arg2 = num1;
    args.arg3 = num2;
    /*
    for (int i = 0; i < threadCount; i++) {
        pthread_create(&threads[i], nullptr, threadTest, (void *) &args);
        pthread_join(threads[i], nullptr);
    }
    */

    // starting at the last index to have the number be in the correct order
    // num1Math & num2Math will hold the original respective values so they do not get altered
    int index = to_string(num1).length() - 1;
    long num1Math = num1;
    long num2Math = num2;

    // loop to extract the individual digits of num1 and place them in the array number1
    while (num1Math > 0) {
        number1[index] = num1Math % 10;
        num1Math /= 10;
        index--;
    }

    // reset index
    index = to_string(num2).length() - 1;

    // loop to extract the individual digits of num2 and place them in the array number2
    while (num2Math > 0) {
        number2[index] = num2Math % 10;
        num2Math /= 10;
        index--;
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



    // printf("Index: 8 = %ld\n", number1[8]);

    // error message on this one
    // printf("Index: 8 = %ld\n", number2[8]);





    // figure out which number has less digits. (To know maximum digits to calc.)
    printf("Number 1:\t\t %ld\n", num1);
    printf("Number 2:\t\t %ld\n", num2);

    if (num1>=num2){
        printf("num1 is greater or equal to num2.\n");
    }
    else{
        printf("num2 is bigger.\n");
    }



    cout << endl;




    // each thread executes function "multiply"
    for(int i=0; i<threadCount; i++){
        pthread_create(&threads[i], NULL, multiply, (void *) i);
    }


	for(int i = 0; i<threadCount; i++) {
		pthread_join( threads[i], NULL );
    }










    printf("Program complete.");


    return 0;
}