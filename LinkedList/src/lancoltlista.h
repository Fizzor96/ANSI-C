#ifndef LANCOLTLISTA_H
#define LANCOLTLISTA_H

#include <malloc.h>
#include <stdio.h>

#define INTEGER 0
#define FLOATING 1
#define CHARACTER 2
#define STRING 3

struct Node
{
    void *data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    int typeflag;
};

struct LinkedList *CreateLinkedListWithData(void *nodedata, int typeflag);
struct LinkedList *CreateLinkedListWithNode(struct Node *node, int typeflag);
struct Node *CreateNodeWithData(void *data);
struct Node *CreateNodeWithDataAndNext(void *data, struct Node *next);
void PrintLinkedList(struct LinkedList *list);
void PrintList(struct Node *node, const int typeflag);

#endif