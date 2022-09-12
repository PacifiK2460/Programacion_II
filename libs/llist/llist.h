#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

// Linked List
struct LList;
typedef struct LList LList;

void LList_new(LList *base);
int LList_add(LList *list, void *data);
void *LList_get(LList *list, int index);
int LList_remove_at(LList *list, int index);
int LList_size(LList *list);
void LList_free(LList *list);

#endif //LLIST_H_INCLUDED