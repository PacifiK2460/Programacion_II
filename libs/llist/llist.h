#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

// Linked List
typedef struct LListNode{
    void *data;
    struct LListNode *next;
}LListNode;

typedef struct LList{
    LListNode *head;
    LListNode *tail;
    int size;
} LList;

void LList_new(LList *base);
int LList_add(LList *list, void *data);
int Llist_add_at(LList *list, void *data, int index);
int LList_remove_at(LList *list, int index);
void *LList_get(LList *list, int index);
int LList_size(LList *list);
void LList_free(LList *list);

#endif //LLIST_H_INCLUDED