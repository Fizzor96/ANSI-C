#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#define INTEGER 0
#define FLOATING 1
#define STRING 2

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

struct LinkedList *CreateLinkedList(struct Node *node, const int typeflag);
struct Node *CreateNodeWithData(void *data);
struct Node *CreateNodeWithDataAndNext(void *data, struct Node *nextnode);
void PrintLinkedList(struct LinkedList *list);

#endif