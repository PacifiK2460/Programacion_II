#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random1(int min, int max){
    return min + rand() % (max - min + 1);
}

typedef struct DLList{
    int data;
    struct DLList *next;
    struct DLList *prev;
}DLList;

int add_at(DLList **head, int data, int index){
    DLList *newNode = (DLList*)malloc(sizeof(DLList));
    if(newNode == NULL){
        return 0;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(index == 0){
        newNode->next = *head;
        if(*head != NULL){
            (*head)->prev = newNode;
        }
        *head = newNode;
        return 1;
    } else {
        DLList *temp = *head;
        int i = 0;
        while(temp != NULL && i < index - 1){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return 1;
    }

    return 1;
}

int main(){
    srand(time(0));

    DLList *head = NULL;

    printf("%d cantidad de elementos bi direccionados.\n", 10);
    for(int i = 0; i < 9; i++){
        int m = random1(1, 100);
        if( add_at(&head, m, 0) ){
            printf("Elemento %d (%d) agregado correctamente.\n", i + 1, m);
        }
    }

    add_at(&head,0,9);
   add_at(&head,0,0);

    printf("Data table:\n");
    for(int j = 0; j < 11; j++){
      if(head->prev != NULL)
      {
        printf("%4d(%p)\t <- ",head->prev->data, head->prev);
      } else {
        printf("NULL(NULL)\t <-");
      }
      if(head != NULL){
        printf("%4d(%p)\t -> ",head->data, head);
      } else {
        printf("NULL(NULL)\t ->");
      }
      if(head->next != NULL){
        printf("%4d(%p)\n",head->next->data, head->next);
      } else {
        printf("NULL(NULL)\n");
        
      }

        head = head->next;
    }
}