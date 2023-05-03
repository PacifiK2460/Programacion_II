#pragma once

#include <stdlib.h>

typedef struct Node
{
    void* data;
    struct Node* last;
    struct Node* next;
} Node, *PNode;

typedef struct List
{
    Node* head;
    Node* tail;
    int size;
} List, *PList;

int addNode(PList list,void* data);
int deleteNode(PList list, void* data);
int deleteList(PList list);

void* getNode(PList list, int index);

void swapNodes(PList list, int index1, int index2);


