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

int deleteList(PList list){
    if (list == NULL)
        return 1;

    PNode current = list->head;
    while (current != NULL)
    {
        PNode next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return 0;
}

void swapNodes(PList list, int index1, int index2){
    if(index1 >= list->size || index1 < 0 || index2 >= list->size || index2 < 0)
        return;

    PNode node1 = list->head;
    PNode node2 = list->head;

    for (int i = 0; i < index1; i++)
    {
        node1 = node1->next;
    }

    for (int i = 0; i < index2; i++)
    {
        node2 = node2->next;
    }

    void* temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}