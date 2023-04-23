#include "list.h"

int addNode(PList list, void* data)
{
    PNode node = (PNode)malloc(sizeof(Node));
    if (node == NULL)
        return 1;
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

int deleteNode(PList list, void* data){
    PNode node = list->head;

    while (node != NULL)
    {
        if (node->data == data)
        {
            if (node->last != NULL)
            {
                node->last->next = node->next;
            }
            else
            {
                list->head = node->next;
            }

            if (node->next != NULL)
            {
                node->next->last = node->last;
            }
            else
            {
                list->tail = node->last;
            }

            free(node);

            list->size--;

            return 0;
        }

        node = node->next;
    }

    return 1;
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