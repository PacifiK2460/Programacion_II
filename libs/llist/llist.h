#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

// Linked List
typedef struct LListNode {
    void *data;
    struct LListNode *next;
} LListNode;

typedef struct LList {
    LListNode *head;
    LListNode *tail;
    int size;
} LList;

LList *LList_new();
int LList_add(LList *list, void *data);
void *LList_get(LList *list, int index);
int LList_remove_at(LList *list, int index);
int LList_size(LList *list);
void LList_free(LList *list);

#endif //LLIST_H_INCLUDED