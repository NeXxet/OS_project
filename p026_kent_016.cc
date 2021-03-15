// OS Project
// Kent, Andrew, Andres

#include <cstdio>
#include <iostream>
#include <fstream>
#include <pthread.h>

using namespace std;


// global variables
int global_c = 0;   // global counter 
int max_digit_to_calc = 0;
long number1[256];   // store digit numbers of first number
long number2[256];   // store digit numbers of second number
long product[512];   // store digit numbers of second number
long big_number;     // a bigger number. Ex. 23958233
bool is_number1_bigger; // a flag that indicates if number1 is a bigger number.


void *
//int
multiply(void *){
    printf("multiply function working.\n");
    printf("global_c = %d\n", global_c);
    
    printf("Bigger num = %ld\n", big_number);
    //printf("Digit num = %ld\n", big_number);

    if(is_number1_bigger == true){
        printf("number1 is bigger\n");
    }
    else{
        printf("number2 is bigger\n");
    }



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
    ifstream theFile("input2.txt");
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





    // Figure out the # of maximum digits to calc.
    // (and store data to global variables to be able to perform multi-threading.)
    printf("Number 1:\t\t%ld\n", num1);
    printf("Number 2:\t\t%ld\n", num2);
    if (num1>=num2){
        printf("num1 is greater or equal to num2.\n");
        is_number1_bigger = true;                       // need this in multi-threading
        printf("Digit # of num2:\t%d\n", (to_string(num2).length()));
        max_digit_to_calc = (to_string(num2).length());     // store in global variable
        big_number = num1;              // store bigger number in global variable
        printf("Max digit # to calc:\t%d\n", max_digit_to_calc);
    }
    else{
        printf("num2 is bigger.\n");
        is_number1_bigger = false;                      // need this in multi-threading
        printf("Digit # of num1:\t%d\n", (to_string(num1).length()));
        max_digit_to_calc = (to_string(num1).length());     // store in global variable
        big_number = num2;              // store bigger number in global variable
        printf("Max digit # to calc:\t%d\n", max_digit_to_calc);
    }
    cout << endl;









    // Figure out if there enough thread #s for each digit #s. ???MAYBE?




    




    // each thread executes function "multiply"
    for(int i=0; i< max_digit_to_calc; i++){
        pthread_create(&threads[i], NULL, multiply, (void *) i);
    }


	for(int i = 0; i< max_digit_to_calc; i++) {
		pthread_join( threads[i], NULL );
    }










    printf("Program complete.");


    return 0;
}