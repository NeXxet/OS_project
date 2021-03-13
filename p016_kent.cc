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
    long numbers[2];

    // reading input.txt and store in numbers[2]
    ifstream theFile("input.txt");
    long get_number;
    int i = 0;        // counter
    while(theFile >> get_number){
        //cout << get_number << endl;
        numbers[i] = get_number;
        i++;
        if(i==3){break;}
    }

    printf("Thread amount:\t %ld\n",numbers[0]);
    printf("Number 1:\t\t %ld\n",numbers[1]);
    printf("Number 2:\t\t %ld\n",numbers[2]);

    // displaying expected result
    long expected_result = numbers[1] * numbers[2];
    printf("Expected calculation: %ld * %ld = %ld\n", numbers[1], numbers[2], expected_result);




    printf("Program complete.");





    /*
    //read input.txt
    
    printf("Thread amount:\t %ld\n", num_1);
    printf("Number 1:\t\t %ld\n", num_2);
    printf("Number 2:\t\t %ld\n", num_3);

    // displaying expected result
    long expected_result = num_2 * num_3;
    printf("Expected calculation: %ld * %ld = %ld\n", num_2, num_3, expected_result);








    */
    return 0;
}


// make function that uses threads?


