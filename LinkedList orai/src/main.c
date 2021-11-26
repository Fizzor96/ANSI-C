#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "linkedlist.h"

int main(int argc, char **argv)
{
    int num1 = 5;
    int num2 = 7;
    int num3 = 18;
    int num4 = 99;
    int num5 = 66;
    struct LinkedList *list = CreateLinkedList(CreateNodeWithDataAndNext(&num1, CreateNodeWithDataAndNext(&num2, CreateNodeWithDataAndNext(&num3, CreateNodeWithDataAndNext(&num4, CreateNodeWithData(&num5))))), INTEGER);
    PrintLinkedList(list);
    free(list);
    return 0;
}