#pragma once

#include<stdlib.h>

typedef struct ListItem {
    struct ListItem *next;
    struct ListItem *prev;
    void *data;
} ListItem;

typedef struct _List {
    ListItem *first;
    ListItem *last;
    int size;
} *List;

typedef enum ListIndexes {
    LIST_FIRST = 0,
    LIST_LAST = -1
} ListIndexes;

List newList();
int listAdd(List list, void *data);
void listFree(List list, void (*freeData)(void *));
int listAddAt(List list, void *data, int index);
int listRemoveAt(List list, int index, void (*freeData)(void *));
void *listGet(List list, int index);