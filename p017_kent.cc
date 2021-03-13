// Kent Templin, 
// CS4348.006 Project1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // 3 numbers we want from input.txt
    long nums[2];

    // reading input.txt and store in numbers[2]
    ifstream theFile("input.txt");
    long get_number;
    int i = 0;        // counter
    while(theFile >> get_number){
        //cout << get_number << endl;
        nums[i] = get_number;
        i++;
        if(i==3){break;}
    }

    // displaying variables that we read from input txt.
    printf("Thread amount:\t %ld\n",nums[0]);
    printf("Number 1:\t\t %ld\n",nums[1]);
    printf("Number 2:\t\t %ld\n",nums[2]);

    // displaying expected result
    long expected_result = nums[1] * nums[2];
    printf("Expected calculation: %ld * %ld = %ld\n\n", nums[1], nums[2], expected_result);

    // arrays that will store 256 digits of each num[1] and num[2]
    long number1[256];   //store digit numbers of num[1]
    long number2[256];   //store digit numbers of num[2]












    printf("Program complete.");






    return 0;
}


// make function that uses threads?


