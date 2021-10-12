#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <alloca.h>
#include "quadratic.h"

// Function declarations
void Prnt(const char *str);
void Log(void (*func)(const char *), const char *str);
char *IntToStr(int num);
char *FloatingToStr(double num);

int main(int argc, char **argv)
{
    Prnt("-----------VARS---------------");
    // Declaring and defining variables
    int myNum1 = 5;
    myNum1++;
    int myNum2 = {5};
    myNum2++;

    int *myNum3 = (int *)malloc(sizeof(int));
    *myNum3 = 5;
    free(myNum3);

    Prnt("---------ARRAYS---------------");

    // Declaring and defining arrays
    // Declaring array with [] means, we can't change it's size at runtime
    int myNums1[] = {1, 2, 3};
    myNums1[0] = 1;

    // Declaring array with allocator (Dynamic Memory Allocation) allow us to change it's size at runtime
    // If we want to, we need to create another array, have to calculate it's size (Reallocation), copy content from the first and change the untouched parth of the array
    int *myNums2 = (int *)malloc(sizeof(int) * 3);
    *myNums2 = 69;
    *(myNums2 + 1) = 4;
    *(myNums2 + 2) = 22;

    // Iterating through the array
    for (size_t i = 0; i < 3; i++)
    {
        printf("%i\n", *(myNums2 + i));
    }

    Prnt("---------FNCPTR---------------");

    // Pass method as argument with argument(s) (functionpointer)
    Log(Prnt, "Hello World!");

    // "String" operations
    Prnt("---------STROPS---------------");

    double x1, x2;
    int resp = solve(1, 4, 4, &x1, &x2);

#pragma region Casting

    // Creating textbuffer
    char *textBuffer = malloc(sizeof(char) + 100);

    // Concat "string"
    strcat(textBuffer, "Response: ");

    // Creating buffer
    // 5 bytes == 1 int + 1 char
    char respTxt[5];

    // Sprintf <- casting any numeric val to a given "string" format
    sprintf(respTxt, "%d", resp);

    strcat(textBuffer, respTxt);
    strcat(textBuffer, ", (");

    // 9 bytes == 1 double + 1 char
    // x1 is a double!!!
    char x1Txt[9];
    sprintf(x1Txt, "%f", x1);
    strcat(textBuffer, x1Txt);
    strcat(textBuffer, ",");
    // char x2Txt[8];
    // sprintf(x2Txt, "%f", x2);
    strcat(textBuffer, FloatingToStr(x2));
    strcat(textBuffer, ")");
#pragma endregion

    printf("Response: %d, (%lf,%lf)\n", resp, x1, x2);

    // Printing the concatenated "stringbuffer"
    // Same as the statement above this
    Log(Prnt, textBuffer);

    Log(Prnt, "----------STRUCTS------------");

    // Creating a QuadraticSolution pointer (solve_struct return value is a " QuadraticSolution* " !!!)
    struct QuadraticSolution *solution = solve_struct(1, 4, 4);
    (*solution).x1;

    printf("Response: %d, (%lf,%lf)\n", solution->status, solution->x1, solution->x2);

    return 0;
}

void Prnt(const char *str)
{
    // Assume str is a string literal and we are lazy to write "new line character" every time we want to print a text out to the standart output -> we have to concat!

    // Creating buffer for our "text"
    char *temp = malloc(strlen(str));

    // Copy str to temp
    strcpy(temp, str);

    // Concat here
    strcat(temp, "\n");

    // Printing to the standard output
    printf("%s", temp);

    // Memory leak happens here cuz we used Dynamic Allocator but we didn't free the allocated memory!
    // Always free the allocated memory!!!
    free(temp);
}

// Function definitions
void Log(void (*func)(const char *), const char *str)
{
    func(str);
}

char *IntToStr(int num)
{
    char *temp = (char *)malloc(sizeof(int));
    sprintf(temp, "%d", num);
    return temp;
}

char *FloatingToStr(double num)
{
    char *temp = (char *)malloc(sizeof(double));
    sprintf(temp, "%f", num);
    return temp;
}