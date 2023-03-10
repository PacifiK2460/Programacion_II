#include "list.h"

List newList()
{
    List list = malloc(sizeof(List));
    if (list == NULL)
    {
        return NULL;
    }
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

int listAdd(List list, void *data)
{
    if (list == NULL)
    {
        return -1;
    }

    ListItem *node = malloc(sizeof(ListItem));
    if (node == NULL)
    {
        return -1;
    }
    node->data = data;
    node->next = NULL;
    if (list->first == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list->last->next = node;
        list->last = node;
    }
    list->size++;
    return 0;
}

void listFree(List list, void (*freeData)(void *))
{
    if (list == NULL)
    {
        return;
    }
    ListItem *node = list->first;
    while (node != NULL)
    {
        ListItem *next = node->next;
        if (freeData != NULL)
        {
            freeData(node->data);
        }
        free(node);
        node = next;
    }
    free(list);
}

int listAddAt(List list, void *data, int index)
{
    if (list == NULL)
    {
        return -1;
    }
    if (index > list->size)
    {
        return -1;
    }
    if (index == LIST_LAST)
    {
        return listAdd(list, data);
    }
    if (index == list->size || index == LIST_LAST)
    {
        return listAdd(list, data);
    }
    ListItem *node = malloc(sizeof(ListItem));
    if (node == NULL)
    {
        return -1;
    }
    node->data = data;
    if (index == 0)
    {
        node->next = list->first;
        list->first = node;
    }
    else
    {
        ListItem *prev = list->first;
        for (size_t i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }
    list->size++;
    return 0;
}

int listRemoveAt(List list, int index, void (*freeData)(void *))
{
    if (list == NULL)
    {
        return -1;
    }
    if (index >= list->size || index < -1)
    {
        return -2;
    }
    ListItem *node = list->first;
    if (index == LIST_FIRST)
    {
        list->first = node->next;
        if (freeData != NULL)
        {
            freeData(node->data);
        }
        free(node);
    }
    else if (index == LIST_LAST)
    {
        ListItem *prev = list->first;
        for (size_t i = 0; i < list->size - 2; i++)
        {
            prev = prev->next;
        }
        node = prev->next;
        prev->next = NULL;
        list->last = prev;
        if (freeData != NULL)
        {
            freeData(node->data);
        }
        free(node);
    }
    else
    {
        ListItem *prev = list->first;
        for (size_t i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        node = prev->next;
        prev->next = node->next;
        if (freeData != NULL)
        {
            freeData(node->data);
        }
        free(node);
    }
    list->size--;
    return 0;
}

void *listGet(List list, int index)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (index >= list->size || index < -1)
    {
        return NULL;
    }
    if (index == LIST_LAST)
    {
        return list->last->data;
    }

    ListItem *node = list->first;
    for (size_t i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node->data;
}
