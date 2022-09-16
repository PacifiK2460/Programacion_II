#include "llist.h"

void LList_new(LList* base) {
  base->head = 0;
  base->tail = 0;
  base->size = 0;
}

int LList_add(LList* list, void* data) {
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
    if(list->tail->next == 0) {
      return -1;
    }
    list->tail->next->data = data;
    list->tail->next->next = 0;
    list->tail = list->tail->next;
  }
  list->size++;
  return 1;
}

int LList_remove_at(LList* list, int index) {
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
  return 1;
}

void LList_free(LList* list) {
  LListNode* current = list->head;
  while (current != 0) {
    LListNode* next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int LList_size(LList* list) {
  return list->size;
}

void* LList_get(LList* list, int index) {
  if (index < 0 || index >= list->size) {
    return 0;
  }
  if(index == 0) {
    return list->head->data;
  }
  if(index == list->size - 1) {
    return list->tail->data;
  }
  LListNode* current = list->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current->data;
}

int Llist_add_at(LList* list, void* data, int index) {
  if (index < 0 || index > list->size) {
    return -2;
  }
  if (index == 0) {
    LListNode* new_node = malloc(sizeof(LListNode));
    if(new_node == 0) {
      return -1;
    }
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return 1;
  }
  if (index == list->size) {
    return LList_add(list, data);
  }
  LListNode* current = list->head;
  LListNode* previous = 0;
  for (int i = 0; i < index; i++) {
    previous = current;
    current = current->next;
  }
  LListNode* new_node = malloc(sizeof(LListNode));
  if(new_node == 0) {
    return -1;
  }
  new_node->data = data;
  new_node->next = current;
  previous->next = new_node;
  list->size++;
  return 1;
}