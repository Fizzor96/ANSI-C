#ifndef PROCEDURAL_FILEHANDLE_H
#define PROCEDURAL_FILEHANDLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CREATE 1
#define NOCREATE 0

// Opens an existing text file for reading purpose.
#define READ (char *)"r"

#pragma region MODES

// Opens a text file for writing. If it does not exist, then a new file is created. Here your program will start writing content from the beginning of the file.
#define CREATEWRITE (char *)"w"

// Opens a text file for both reading and writing. It first truncates the file to zero length if it exists, otherwise creates a file if it does not exist.
#define CREATEWRITETRUNC (char *)"w+"

// Opens a text file for both reading and writing. It creates the file if it does not exist. The reading will start from the beginning but writing can only be appended.
#define APPEND (char *)"a+"

// Opens a text file for writing in appending mode. If it does not exist, then a new file is created. Here your program will start appending content in the existing file content.
#define CREATEAPPEND (char *)"a"

#pragma endregion

/*
* Return 1 if the given file exist, 0 if not.
*/
unsigned int IsFileExist(const char *path);

/* 
* Calculation of allocated size in bytes for loading data into memory
*/
unsigned int BonyiMatek(const char *path);

/* 
* Getting total amount of chars from file if exist.
*/
unsigned int GetNumberOfCharsFromFile(const char *path);

/* 
* Getting total amount of lines from file if exist.
*/
unsigned int GetNumberOfLinesFromFile(const char *path);

/* 
* Getting number of character of longest line from file if exist.
*/
unsigned int GetCharNumOfLongestLineFromFile(const char *path);

/*  path = filename, wantCreate = CREATE / NOCREATE.
*   CREATE, NOCREATE are defined macro directives!
*   If file does not exist and the use of NOCREATE macro basically does nothing...
*   Look up definition for more info!
 */
void PrintFileData(const char *path, unsigned int wantCreate);
/* 
* Load the whole file into memory (byte by byte).
*/
char *LoadFromFile(const char *path);

// TODO: impl
void WriteToFile(const char *path, const char *data, unsigned int mode);

#endif //PROCEDURAL_FILEHANDLE_H