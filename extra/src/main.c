#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filehandle.h"

int main(int argc, char **argv)
{
    PrintFileData("test.txt", CREATE);
    return 0;
}