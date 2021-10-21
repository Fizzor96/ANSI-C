#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#include "lancoltlista.h"

int main(int argc, char **argv)
{
    srand(time(NULL));

    int d1 = 5;
    int d2 = 1;
    int d3 = 4;
    int d4 = 68;
    int d5 = 24;

    struct LinkedList *list = CreateLinkedListWithNode(CreateNodeWithDataAndNext(&d1, CreateNodeWithDataAndNext(&d2, CreateNodeWithDataAndNext(&d3, CreateNodeWithDataAndNext(&d4, CreateNodeWithData(&d5))))), INTEGER);

    PrintLinkedList(list);

    return 0;
}