#ifndef PROCEDURAL_FILEHANDLE_H
#define PROCEDURAL_FILEHANDLE_H

#define CREATE 1
#define NOCREATE 0

// Opens an existing text file for reading purpose.
#define READ (char *)"r"

// Opens a text file for writing. If it does not exist, then a new file is created. Here your program will start writing content from the beginning of the file.
#define CREATEWRITE (char *)"w"

// Opens a text file for both reading and writing. It first truncates the file to zero length if it exists, otherwise creates a file if it does not exist.
#define CREATEWRITETRUNC (char *)"w+"

// Opens a text file for both reading and writing. It creates the file if it does not exist. The reading will start from the beginning but writing can only be appended.
#define APPEND (char *)"a+"

// Opens a text file for writing in appending mode. If it does not exist, then a new file is created. Here your program will start appending content in the existing file content.
#define CREATEAPPEND (char *)"a"

/*  path = filename, wnatCreate = CREATE / NOCREATE.
*   CREATE, NOCREATE are defined macro directives!
*   Look up definition for more info!
 */
void PrintFileData(const char *path, unsigned int wantCreate);
void WriteToFile(const char *path, const char *data, unsigned int wantCreate);

#endif //PROCEDURAL_FILEHANDLE_H
