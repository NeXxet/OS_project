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


    // calculate number of digits
    long count = 0;     // counter
    long n = nums[1];

    while (n != 0){
        n /= 10;
        count++;
        printf("n=%ld    ",n);
        printf("c=%ld\n",count);
    }

    
    long numberArray1[count];

    if(count!=0){

        count = 0;    
        n = nums[1];

        while (n != 0){
            numberArray1[count] = n % 10;
            n /= 10;
            count++;
        }
    }

    printf("index 0= %ld\n", numberArray1[0]);
    printf("index 1= %ld\n", numberArray1[1]);
    printf("index 2= %ld\n", numberArray1[2]);
    printf("index 3= %ld\n", numberArray1[3]);
    printf("index 4= %ld\n", numberArray1[4]);
    printf("index 5= %ld\n", numberArray1[5]);
    printf("index 6= %ld\n", numberArray1[6]);
    printf("index 7= %ld\n", numberArray1[7]);

    





















    printf("Program complete.");






    return 0;
}


// make function that uses threads?


