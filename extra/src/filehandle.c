#include "filehandle.h"

unsigned int IsFileExist(const char *path)
{
    // Macros for access() param declared in unistd.h eg. F_OK = 0
    if (access(path, F_OK) == 0)
    {
        // File exist
        return 1;
    }
    // File does not exist
    return 0;
}

unsigned int BonyiMatek(const char *path)
{
    if (IsFileExist(path))
    {
        unsigned int sum = 0;
        sum = GetNumberOfCharsFromFile(path);
        // IMPORTANT: 2 * GetNumberOfLinesFromFile(path)
        // Reason: nulltermination char or newline char!!!
        sum = sum + 2 * GetNumberOfLinesFromFile(path);
        return sum;
    }
    return 0;
}

unsigned int GetNumberOfCharsFromFile(const char *path)
{
    if (IsFileExist(path))
    {
        FILE *fp = fopen(path, READ);
        unsigned int count = 0;
        for (char c = getc(fp); c != EOF; c = getc(fp))
        {
            count = count + 1;
        }
        fclose(fp);
        return count;
    }
    return 0;
}

unsigned int GetNumberOfLinesFromFile(const char *path)
{
    if (IsFileExist(path))
    {
        FILE *fp = fopen(path, READ);
        unsigned int count = 0;
        for (char c = getc(fp); c != EOF; c = getc(fp))
        {
            if (c == '\n')
            {
                count = count + 1;
            }
        }
        fclose(fp);
        return count + 1;
    }
    return 0;
}

unsigned int GetCharNumOfLongestLineFromFile(const char *path)
{
    if (IsFileExist(path))
    {
        FILE *fp = fopen(path, READ);
        unsigned int count = 0;
        char *str = (char *)malloc(sizeof(char) * GetNumberOfCharsFromFile(path));
        while (fgets(str, GetNumberOfCharsFromFile(path), fp))
        {
            if ((unsigned int)strlen(str) > count)
            {
                count = strlen(str);
            }
        }
        free(str);
        fclose(fp);
        return count;
    }
    return 0;
}

void PrintFileData(const char *path, unsigned int wantCreate)
{
    // Check if the file exist
    if (IsFileExist(path))
    {
        FILE *fp = fopen(path, READ);
        char *str = (char *)malloc(sizeof(char) * GetNumberOfCharsFromFile(path));
        while (fgets(str, GetNumberOfCharsFromFile(path), fp))
        {
            // printf("%s\n", str);
            printf("%s", str);
        }
        free(str);
        fclose(fp);
    }
    else
    {
        if (wantCreate == CREATE)
        {
            FILE *fp = fopen(path, CREATEWRITE);
            fclose(fp);
            fp = fopen(path, READ);
            char *str = (char *)malloc(sizeof(char) * GetNumberOfCharsFromFile(path));
            while (fgets(str, GetNumberOfCharsFromFile(path), fp))
            {
                // printf("%s\n", str);
                printf("%s", str);
            }
            free(str);
            fclose(fp);
        }
        else
        {
            printf("No actions have been commited!\n");
        }
    }
}

char *LoadFromFile(const char *path)
{
    if (IsFileExist(path))
    {
        FILE *fp = fopen(path, READ);
        char *storage = (char *)malloc(sizeof(char) * BonyiMatek(path));
        int c;
        for (unsigned int i = 0; i < GetNumberOfCharsFromFile(path); ++i)
        {
            c = getc(fp);

            // If 'c' is End of File => break!
            if (c == EOF)
            {
                storage[i] = 0x00;
                break;
            }

            storage[i] = c;
        }

        return storage;
    }
    return NULL;
}

void WriteToFile(const char *path, const char *data, unsigned int mode)
{
    if (IsFileExist(path))
    {
        /* code */
    }
}