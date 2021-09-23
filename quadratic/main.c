#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <alloca.h>
#include "quadratic.h"

void Prnt(const char *str);
void Log(void (*func)(const char *), const char *str);
char *IntToStr(int num);
char *FloatingToStr(double num);

int main(int argc, char **argv)
{
    Prnt("-----------VARS---------------");
    int myNum1 = 5;
    int myNum2 = {5};

    int *myNum3 = (int *)malloc(sizeof(int));
    *myNum3 = 5;
    free(myNum3);

    Prnt("---------ARRAYS---------------");

    int myNums1[] = {1, 2, 3};
    int *myNums2 = (int *)malloc(sizeof(int) * 3);
    *myNums2 = 1;
    *(myNums2 + 1) = 2;
    *(myNums2 + 2) = 3;

    for (size_t i = 0; i < 3; i++)
    {
        printf("%i\n", *(myNums2 + i));
    }

    Prnt("---------FNCPTR---------------");

    Log(Prnt, "Hello World!");

    Prnt("---------STROPS---------------");

    double x1, x2;
    int resp = solve(1, 4, 4, &x1, &x2);

    char textBuffer[1];

    strcat(textBuffer, "Response: ");
    char respTxt[4];
    sprintf(respTxt, "%d", resp);
    strcat(textBuffer, respTxt);
    strcat(textBuffer, ", (");
    char x1Txt[8];
    sprintf(x1Txt, "%f", x1);
    strcat(textBuffer, x1Txt);
    strcat(textBuffer, ",");
    // char x2Txt[8];
    // sprintf(x2Txt, "%f", x2);
    strcat(textBuffer, FloatingToStr(x2));
    strcat(textBuffer, ")");

    Log(Prnt, textBuffer);

    // printf("Response: %d, (%lf,%lf)\n", resp, x1, x2);

    Log(Prnt, "----------STRUCTS------------");

    struct QuadraticSolution *solution = solve_struct(1, 4, 4);

    printf("Response: %d, (%lf,%lf)\n", solution->status, solution->x1, solution->x2);

    return 0;
}

void Prnt(const char *str)
{
    char *temp = (char *)malloc(strlen(str) + 1);
    strcat(temp, str);
    strcat(temp, "\n");
    printf(temp);
    free(temp);
}

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