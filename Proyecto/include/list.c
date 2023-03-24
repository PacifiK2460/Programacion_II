#include "LIST.h"

int addNode(PList list, void* data)
{
    PNode node = (PNode)malloc(sizeof(Node));
    node->data = data;
    node->last = NULL;
    node->next = NULL;

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->last = list->tail;
        list->tail = node;
    }

    list->size++;

    return 0;
}

void* getNode(PList list, int index)
{
    if(index >= list->size || index < 0)
        return NULL;

    PNode node = list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node->data;
}