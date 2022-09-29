#include "llist.h"

LList *LList_new()
{
  LList *base = malloc(sizeof(LList));
  base->head = 0;
  base->tail = 0;
  base->size = 0;

  return base;
}

int LList_add(LList *list, void *data)
{
  if (list->size == 0)
  {
    list->head = malloc(sizeof(LListNode));
    if (list->head == 0)
    {
      return -1;
    }
    list->head->data = data;
    list->head->next = 0;
    list->tail = list->head;
  }
  else
  {
    list->tail->next = malloc(sizeof(LListNode));
    if (list->tail->next == 0)
    {
      return -1;
    }
    list->tail->next->data = data;
    list->tail->next->next = 0;
    list->tail = list->tail->next;
  }
  list->size++;
  return 1;
}

// FIX: Remove last element
void* LList_remove_at(LList *list, int index)
{
  // Check if index is valid
  if (index < 0 || index >= list->size)
  {
    return -2;
  }
  // Check if it's going to remove the first element
  if (index == 0){
    LListNode* node = list->head;
    list->head = list->head->next;
    list->size--;
    free(node);
    return node->data;
  }
  // Check if it's going to remove the last element
  if (index == list->size - 1){
    LListNode* temp = list->head;
    LListNode* to_return = list->tail;
    while(temp->next != list->tail){
      temp = temp->next;
    }
    temp->next = 0;
    list->tail = temp;
    list->size--;
    free(to_return);
    return to_return->data;
  }
  
  LListNode *current = list->head;
  LListNode *previous = 0;
  for (int i = 0; i < index; i++)
  {
    previous = current;
    current = current->next;
  }
  LListNode* temp = current;
  previous->next = current->next;
  list->size--;
  free(temp);
  return temp->data;
}

void LList_free(LList *list)
{
  LListNode *current = list->head;
  while (current != 0)
  {
    LListNode *next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int LList_size(LList *list)
{
  return list->size;
}

void *LList_get(LList *list, int index)
{
  if (index < 0 || index >= list->size)
  {
    return 0;
  }
  if (index == 0)
  {
    return list->head->data;
  }
  if (index == list->size - 1)
  {
    return list->tail->data;
  }
  LListNode *current = list->head;
  for (int i = 0; i < index; i++)
  {
    current = current->next;
  }
  return current->data;
}
/*
 Agrega la informacion en el index especificado
*/
int Llist_add_at(LList *list, void *data, int index)
{
  // Si el index esta fuera de rango, regresamos un error
  if (index < 0 || index > list->size)
  {
    return -2;
  }
  // Si el index es 0, vamos a agregar al inicio, 
  // recorriendo la demas información
  if (index == 0)
  {
    // Creamos un nuevo nodo...
    LListNode *new_node = malloc(sizeof(LListNode));
    // Si hubo un error al momento de crear el nodo, regresamos un error
    if (new_node == 0)
    {
      return -1;
    }
    // Asingamos la informacion al nodo
    new_node->data = data;
    /* 
      Del nuevo nodo, hacemos que apunte a la cabeza de la lista
      y hacemos que la cabeza de la lista apunte al nuevo nodo

      recorriendo la informacion
    */
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return 1;
  }
  // Si el index es el tamaño de la lista, vamos a agregar al final
  if (index == list->size)
  {
    // Como se supone que tenemos una funcion que ya lo hace,
    // vamos a usarla
    return LList_add(list, data);
  }

  // Sino, vamos a agregar en el index especificado:
  // recorremos la lista hasta llegar al index
  LListNode *current = list->head;
  LListNode *previous = 0;
  for (int i = 0; i < index; i++)
  {
    previous = current;
    current = current->next;
  }
  // Creamos un nuevo nodo
  LListNode *new_node = malloc(sizeof(LListNode));
  if (new_node == 0)
  {
    return -1;
  }
  // Asignamos la informacion al nodo
  new_node->data = data;
  // Hacemos que el nodo anterior apunte al nuevo nodo
  new_node->next = current;
  previous->next = new_node;
  list->size++;
  return 1;
}