// Kent Templin, 
// CS4348.006 Project1

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //long num1 = 23958223;
    //long num2 = 5830;
    //long expected_result = num1 * num2;

    //read input.txt
    char num1[150];
    char num2[150];
    char num3[150];

    FILE * fPointer;
    fPointer = fopen("input.txt","r");

    fgets(num1,150,fPointer);
    fgets(num2,150,fPointer);
    fgets(num3,150,fPointer);
    printf("%s",num1);
    printf("%s",num2);
    printf("%s",num3);

    fclose(fPointer);


    //long input_num1 = 23958223;
    //long input_num2 = 5830;
    //long expected_result = input_num1 * input_num2;


    //printf("Hello World");
    //printf("Expected result is %ld", expected_result);


    return 0;
}


// make function that uses threads?


