#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "filehandle.h"

void Sep();

int main(int argc, char *argv[])
{

    // for (size_t i = 0; i < argc; i++)
    // {
    //     printf("argv %i: %s\n", (int)i, argv[i]);
    // }
    printf("ARGC = %i\n", argc);

    int run = 0;

    for (size_t i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "-H") || argc == 1)
        {
            printf("%s\n", LoadFromFile("../usage.txt"));
            return 0;
        }
        if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "-R"))
        {
            run = 1;
        }
    }

    if (run)
    {
        const char *path = "test.txt";

        // Paragraphs
        char *paragraph1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam. Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis ipsum. Praesent mauris. Fusce nec tellus sed augue semper porta. Mauris massa. Vestibulum lacinia arcu eget nulla. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Curabitur sodales ligula in libero.\n";
        char *paragraph2 = "Sed dignissim lacinia nunc. Curabitur tortor. Pellentesque nibh. Aenean quam. In scelerisque sem at dolor. Maecenas mattis. Sed convallis tristique sem. Proin ut ligula vel nunc egestas porttitor. Morbi lectus risus, iaculis vel, suscipit quis, luctus non, massa. Fusce ac turpis quis ligula lacinia aliquet. Mauris ipsum.\n";
        char *paragraph3 = "Nulla metus metus, ullamcorper vel, tincidunt sed, euismod in, nibh. Quisque volutpat condimentum velit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Nam nec ante. Sed lacinia, urna non tincidunt mattis, tortor neque adipiscing diam, a cursus ipsum ante quis turpis. Nulla facilisi. Ut fringilla. Suspendisse potenti. Nunc feugiat mi a tellus consequat imperdiet. Vestibulum sapien. Proin quam.\n";

        // Reading/Creating
        Sep();
        printf("Reading/Creating\n");
        Sep();
        PrintFileData(path, NOCREATE);
        printf("\n");
        Sep();

        // Writing
        printf("Writing\n");
        Sep();
        printf("Look at the code...\n");
        WriteToFile(path, paragraph1, CREATEWRITETRUNC);
        WriteToFile(path, paragraph2, CREATEAPPEND);
        WriteToFile(path, paragraph3, CREATEAPPEND);
        WriteToFile(path, paragraph1, CREATEAPPEND);
        WriteToFile(path, paragraph2, CREATEAPPEND);
        WriteToFile(path, paragraph3, CREATEAPPEND);
        // WriteToFile(path, paragraph4, CREATEAPPEND);
        Sep();

        // Info
        printf("Info\n");
        Sep();
        printf("Total number of chars: %i\n", GetNumberOfCharsFromFile(path));
        printf("Total number of lines: %i\n", GetNumberOfLinesFromFile(path));
        printf("Longest line charcount: %i\n", GetCharNumOfLongestLineFromFile(path));
        Sep();

        // Printing
        printf("Printing\n");
        Sep();
        char *data = LoadFromFile(path);
        if (data != NULL)
            printf("%s\n", data);
        free(data);
        Sep();

        // Getting Nth line from file
        printf("Getting 4th line from file\n");
        Sep();
        char *nthline = GetNthLine(path, 4);
        printf("%s", nthline);

        Sep();

        // GOOD LUCK HAVE FUN part of the code! :)
        // Storing cstringliterals in a cstringliteral array then printing it to the standard output.
        // Everything is Dynamically Allocated (NO CONST BUFFERS)!!!
        printf("Dark Magic! :)\n");
        Sep();
        char **arr = (char **)malloc(sizeof(char) * GetNumberOfLinesFromFile(path) * GetCharNumOfLongestLineFromFile(path));
        GetLines(path, arr);
        // Iterate from 0 to NumOfLines -1 to fix the problem and every sting must finish with '\n'
        for (size_t i = 0; i < GetNumberOfLinesFromFile(path); i++)
        {
            printf("Line: %i\n%s\n", (int)i, arr[i]);
        }
        free(arr);
        Sep();
    }

    return 0;
}

void Sep()
{
    printf("****************************************************************\n");
}