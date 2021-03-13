// Kent Templin, 
// CS4348.006 Project1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long num_1;
    long num_2;
    long num_3;


    ifstream theFile("input.txt");

    long number;
    long numbers[2];
    int i = 0;  // counter

    while(theFile >> number){
        //cout << number << endl;
        numbers[i] = number;
        i++;
        if(i==3){break;}
    }

    printf("%ld\n",numbers[0]);
    printf("%ld\n",numbers[1]);
    printf("%ld\n",numbers[2]);


    printf("Program complete.");

    /*
    char file_name[50];      //filename variable
    ifstream text_file;     //text file variable 
    cin.getline(file_name, 50);
    text_file.open(file_name);

    if(!text_file.is_open()){
        exit(EXIT_FAILURE);
    }

    char word[50];
    text_file >> word;
    */




    /*
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








    */
    return 0;
}


// make function that uses threads?


