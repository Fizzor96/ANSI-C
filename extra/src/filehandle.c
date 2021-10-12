#include "filehandle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wformat-zero-length"
void PrintFileData(const char *path, unsigned int wantCreate)
{
    // Check if the file is exist
    if (access(path, F_OK) == 0)
    {
        printf("File exist!\n");
        FILE *fp = fopen(path, READ);

        unsigned int numOfCharsInFile = 0;
        for (char c = getc(fp); c != EOF; c = getc(fp))
        {
            numOfCharsInFile = numOfCharsInFile + 1;
        }
        printf("%i\n", numOfCharsInFile);
        // printf("%s\n", buffer);

        char *line;
        ssize_t read;
        size_t len = 0;
        char *buffer = (char *)malloc(sizeof(char) * numOfCharsInFile);
        while ((read = getline(&line, &len, fp)) != -1)
        {
            printf("Retrieved line of length %zu:\n", read);
            printf("%s", line);
        }
        free(buffer);
        fclose(fp);
    }
    else
    {
        printf("File is NOT exist!\n");
        if (wantCreate == CREATE)
        {
            FILE *fp = fopen(path, CREATEWRITE);
            fclose(fp);
            printf("File have been created!\n");
            fp = fopen(path, READ);
            // Impl
            fclose(fp);
        }
        else
        {
            printf("No actions have been commited!\n");
        }
    }

    // FILE *fp;
    // fp = fopen(path, CREATEWRITE);
    // fprintf(fp, "This is testing...\n");
    // char buffer[255];
    // fscanf(fp, "%s", buffer);
    // fgets(buffer, 255, fp);
    // printf("Read Buffer: %s\n", buffer);
    // fclose(fp);
    // free(buffer);
}
#pragma GCC diagnostic warning "-Wformat-zero-length"