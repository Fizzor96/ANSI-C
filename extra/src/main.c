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

    // Paragraphs
    const char *paragraph1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam. Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis ipsum. Praesent mauris. Fusce nec tellus sed augue semper porta. Mauris massa. Vestibulum lacinia arcu eget nulla. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Curabitur sodales ligula in libero.\n";
    const char *paragraph2 = "Sed dignissim lacinia nunc. Curabitur tortor. Pellentesque nibh. Aenean quam. In scelerisque sem at dolor. Maecenas mattis. Sed convallis tristique sem. Proin ut ligula vel nunc egestas porttitor. Morbi lectus risus, iaculis vel, suscipit quis, luctus non, massa. Fusce ac turpis quis ligula lacinia aliquet. Mauris ipsum.\n";
    const char *paragraph3 = "Nulla metus metus, ullamcorper vel, tincidunt sed, euismod in, nibh. Quisque volutpat condimentum velit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Nam nec ante. Sed lacinia, urna non tincidunt mattis, tortor neque adipiscing diam, a cursus ipsum ante quis turpis. Nulla facilisi. Ut fringilla. Suspendisse potenti. Nunc feugiat mi a tellus consequat imperdiet. Vestibulum sapien. Proin quam.";

    // Writing
    WriteToFile("test.txt", paragraph1, CREATEWRITETRUNC);
    WriteToFile("test.txt", paragraph2, CREATEAPPEND);
    WriteToFile("test.txt", paragraph3, CREATEAPPEND);

    // Printing
    // PrintFileData("test.txt", CREATE);
    char *data = LoadFromFile("test.txt");
    if (data != NULL)
        printf("%s\n", data);
    free(data);

    // Info
    printf("\nTotal number of chars: %i\n", GetNumberOfCharsFromFile("test.txt"));
    printf("Total number of lines: %i\n", GetNumberOfLinesFromFile("test.txt"));
    printf("Longest line charcount: %i\n", GetCharNumOfLongestLineFromFile("test.txt"));

    // GOOD LUCK HAVE FUN part of the code! :)
    // Storing cstringliterals in a cstringliteral array then printing it to the standard output.
    // Everything is Dynamically Allocated (NO CONST BUFFERS)!!!
    char **arr = GetLines("test.txt");
    if (arr != NULL)
    {
        for (size_t i = 0; i < GetNumberOfLinesFromFile("test.txt"); i++)
        {
            printf("%s", arr[i]);
        }
    }
    free(arr);

    return 0;
}