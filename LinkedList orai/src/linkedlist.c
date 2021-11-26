#include "linkedlist.h"

struct LinkedList *CreateLinkedList(struct Node *node, const int typeflag)
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->head = node;
    list->typeflag = typeflag;
    return list;
}

struct Node *CreateNodeWithData(void *data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node *CreateNodeWithDataAndNext(void *data, struct Node *nextnode)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = nextnode;
    return node;
}

void PrintLinkedList(struct LinkedList *list)
{
    PrintData(list->head, list->typeflag);
}

void PrintData(struct Node *node, const int typeflag)
{
    if (node->next == NULL)
    {
        Print(node->data, typeflag);
    }
    else
    {
        Print(node->data, typeflag);
        PrintData(node->next, typeflag);
    }
}

void Print(void *data, const int typeflag)
{
    switch (typeflag)
    {
    case 0:
        printf("%i\n", *(int *)data);
        break;

    case 1:
        printf("%f\n", *(float *)data);
        break;

    case 2:
        printf("%s\n", *(char *)data);
        break;
    }
}