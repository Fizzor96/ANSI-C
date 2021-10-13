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
    if (wantCreate == (unsigned int)0)
        wantCreate = NOCREATE;

    if (wantCreate == NOCREATE)
    {
        if (IsFileExist(path))
        {
            FILE *fp = fopen(path, READ);
            char *str = (char *)malloc(sizeof(char) * GetNumberOfCharsFromFile(path));
            // stl fgets() eq. getline() gnu gcc (linux specific)
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
            printf("File does not exist!");
        }
    }
    else
    {
        if (IsFileExist(path))
        {
            FILE *fp = fopen(path, READ);
            char *str = (char *)malloc(sizeof(char) * GetNumberOfCharsFromFile(path));
            // stl fgets() eq. getline() gnu gcc (linux specific)
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
            FILE *fp = fopen(path, CREATEWRITE);
            fclose(fp);
            fp = fopen(path, READ);
            char *str = (char *)malloc(sizeof(char) * GetNumberOfCharsFromFile(path));
            while (fgets(str, GetNumberOfCharsFromFile(path), fp))
            {
                // printf("%s\n", str);
                printf("%s", str);
            }
            // free(str);
            fclose(fp);
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

void WriteToFile(const char *path, const char *data, char *mode)
{
    if (mode != READ)
    {
        FILE *fp = fopen(path, mode);
        fputs(data, fp);
        fclose(fp);
    }
}

void GetLines(const char *path, char **arr)
{
    for (size_t i = 0; i < GetNumberOfLinesFromFile(path); i++)
    {
        arr[i] = GetNthLine(path, (unsigned int)i);
    }
}

char *GetNthLine(const char *path, unsigned int n)
{
    if (IsFileExist(path))
    {
        FILE *fp = fopen(path, READ);
        char *line = (char *)malloc(sizeof(char) * GetCharNumOfLongestLineFromFile(path));
        int c;
        unsigned int counter = 0;
        unsigned int j = 0;
        for (unsigned int i = 0; i < GetNumberOfCharsFromFile(path); i++)
        {
            c = getc(fp);

            if (c == EOF)
            {
                line[j] = 0x00;
                break;
            }

            if (counter == n)
            {
                line[j] = c;
                j = j + 1;
                // 0x0a == \n
                if (c == 0x0a)
                {
                    counter = counter + 1;
                    line[j] = 0x00;
                    j = 0;
                }
            }
            else if (counter > n)
            {
                break;
            }
            else
            {
                // 0x0a == \n
                if (c == 0x0a)
                {
                    counter = counter + 1;
                    // line[j] = 0x0a;
                    j = 0;
                }
            }
        }

        return line;
    }
    return NULL;
}