// OS Project
// Kent, Andrew, Andres

#include <cstdio>
#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

// method will probably need to be updated when we incorporate multi-threading
long multiplyLongs(long num1, long num2) {
    cout << "Printed from thread! Result: " << num1 * num2 << endl << endl;
    return num1 * num2;
}

// method for multi-threading?

int main() {

    // store the 3 numbers from the file
    int threadCount;
    long num1, num2;

    // arrays that will store 256 digits of each number
    long number1[256];   //store digit numbers of first number
    long number2[256];   //store digit numbers of second number

    // reading the file and storing the 3 numbers variables
    ifstream theFile("input.txt");
    theFile >> threadCount >> num1 >> num2;


    // displaying variables that we read from input txt.
    printf("Thread amount:\t %d\n", threadCount);
    printf("Number 1:\t\t %ld\n", num1);
    printf("Number 2:\t\t %ld\n\n" ,num2);

    // creating thread 1
    // th1.join() - waiting for thread 1 (th1) to finish before moving on
    thread th1 (multiplyLongs, num1, num2);
    th1.join();


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
        printf("Index: %d = %ld\n", i, number1[i]);
    }

    cout << endl;

    // Prints the values of array number2
    for (int i = 0; i < to_string(num2).length(); i++) {
        printf("Index: %d = %ld\n", i, number2[i]);
    }


















    printf("Program complete.");


    return 0;
}
