#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filehandle.h"

int main(int argc, char **argv)
{
    // for (size_t i = 0; i < argc; i++)
    // {
    //     printf("argv %i: %s\n", (int)i, argv[i]);
    // }

    // PrintFileData("test.txt", CREATE);
    printf("\n");
    printf("Total number of chars: %i\n", GetNumberOfCharsFromFile("test.txt"));
    printf("Total number of lines: %i\n", GetNumberOfLinesFromFile("test.txt"));
    printf("Longest line charcount: %i\n", GetCharNumOfLongestLineFromFile("test.txt"));
    char *asdasd = LoadFromFile("test.txt");
    printf("%s\n", asdasd);
    free(asdasd);

    return 0;
}