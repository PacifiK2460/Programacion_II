#include "../Llist.h"

LList* new_llist() {
  LList* list = malloc(sizeof(LList));
  list->head = 0;
  list->tail = 0;
  list->size = 0;
  return list;
}

int llist_add(LList* list, void* data) {
  if (list->size == 0) {
    list->head = malloc(sizeof(LListNode));
    if(list->head == 0) {
      return -1;
    }
    list->head->data = data;
    list->head->next = 0;
    list->tail = list->head;
  } else {
    list->tail->next = malloc(sizeof(LListNode));
    list->tail->next->data = data;
    list->tail->next->next = 0;
    list->tail = list->tail->next;
  }
  list->size++;
}


int Llist_remove_at(LList* list, int index) {
  if (index < 0 || index >= list->size) {
    return -2;
  }
  LListNode* current = list->head;
  LListNode* previous = 0;
  for (int i = 0; i < index; i++) {
    previous = current;
    current = current->next;
  }
  if (previous == 0) {
    list->head = current->next;
  } else {
    previous->next = current->next;
  }
  free(current);
  list->size--;
}

void Llist_free(LList* list) {
  LListNode* current = list->head;
  while (current != 0) {
    LListNode* next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int llist_size(LList* list) {
  return list->size;
}

void* llist_get(LList* list, int index) {
  if (index < 0 || index >= list->size) {
    return 0;
  }
  LListNode* current = list->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current->data;
}