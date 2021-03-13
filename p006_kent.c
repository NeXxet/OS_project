// Kent Templin, 
// CS4348.006 Project1

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //read input.txt
    FILE *myFile;
    myFile = fopen("input.txt", "r");       // change directory if you need to.
    int numberArray[3];
    fscanf(myFile, "%d", &numberArray[0]);
    fscanf(myFile, "%d", &numberArray[1]);
    fscanf(myFile, "%d", &numberArray[2]);
    
    // converting from an int array to long vaiables
    long num_1;
    long num_2;
    long num_3;
    num_1 = (long) numberArray[0];
    num_2 = (long) numberArray[1];
    num_3 = (long) numberArray[2];
    printf("Thread amount:\t %ld\n", num_1);
    printf("Number 1:\t\t %ld\n", num_2);
    printf("Number 2:\t\t %ld\n", num_3);

    // displaying expected result
    long expected_result = num_2 * num_3;
    printf("Expected calculation: %ld * %ld = %ld\n", num_2, num_3, expected_result);









    return 0;
}


// make function that uses threads?


