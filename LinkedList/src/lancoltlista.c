#include "lancoltlista.h"

struct LinkedList *CreateLinkedListWithData(void *nodedata, int typeflag)
{
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = malloc(sizeof(struct Node));
    list->head->data = nodedata;
    list->head->next = NULL;
    list->typeflag = typeflag;
    return list;
}

struct LinkedList *CreateLinkedListWithNode(struct Node *node, int typeflag)
{
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = node;
    list->typeflag = typeflag;
    return list;
}

struct Node *CreateNodeWithData(void *data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    return node;
}

struct Node *CreateNodeWithDataAndNext(void *data, struct Node *next)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = next;
    return node;
}

void PrintData(struct Node *node, const int typeflag)
{
    switch (typeflag)
    {
    case 0:
        printf("%i\n", *(int *)node->data);
        break;
    case 1:
        printf("%f\n", *(float *)node->data);
        break;
    case 2:
        printf("%c\n", *(char *)node->data);
        break;
    case 3:
        printf("%s\n", (char *)node->data);
        break;
    default:
        printf("Invalid type flag!\n");
        break;
    }
}

void PrintList(struct Node *node, const int typeflag)
{
    if (node->next != NULL)
    {
        PrintData(node, typeflag);
        PrintList(node->next, typeflag);
    }
    else
    {
        PrintData(node, typeflag);
    }
}

void PrintLinkedList(struct LinkedList *list)
{
    PrintList(list->head, list->typeflag);
}