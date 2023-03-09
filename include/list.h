#pragma once

#include<stdlib.h>

typedef struct ListItem {
    struct ListItem *next;
    struct ListItem *prev;
    void *data;
} ListItem;

typedef struct List {
    ListItem *first;
    ListItem *last;
    size_t size;
} *List;

typedef enum ListIndexes {
    LIST_FIRST = 0,
    LIST_LAST = -1
} ListIndexes;

List newList();
int listAdd(List list, void *data);
void listFree(List list, void (*freeData)(void *));
int listAddAt(List list, void *data, size_t index);
int listRemoveAt(List list, size_t index, void (*freeData)(void *));
void *listGet(List list, size_t index);