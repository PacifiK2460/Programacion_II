#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rangedrandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

typedef struct Node{
    int Data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    int size;
} CircularList;

int insert_at(CircularList* base, int index, int data){
    if(index < 0 || index > base->size) return 0;
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->Data = data;
    if(index == 0){
        if(base->size == 0){
            new_node->next = new_node;
            new_node->prev = new_node;
            base->head = new_node;
        }else{
            new_node->next = base->head;
            new_node->prev = base->head->prev;
            base->head->prev->next = new_node;
            base->head->prev = new_node;
            base->head = new_node;
        }
    }else{
        Node* temp = base->head;
        for(int i = 0; i < index; i++) temp = temp->next;
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
    }
    base->size++;
    return 1;
}

int insert_at(List base, int index, int data){
    if(index > base.size || index < 0){
        return -1;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == 0){
        return -2;
    }
    new_node->Data = data;

    if(base.size == 0){
        base.head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else if(index == 0){
        new_node->next = base.head;
        new_node->prev = base.head->prev;
        base.head->prev = new_node;
        base.head = new_node;
    }else{
        Node* current = base.head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
    }
    base.size++;
    return 0;
}

int delete_at(List base, int index){
    if(index > base.size || index < 0){
        return -1;
    }
    if(index == 0){
        base.head->next->prev = base.head->prev;
        base.head->prev->next = base.head->next;
        base.head = base.head->next;
    }else{
        Node* current = base.head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    base.size--;
    return 0;
}

int append(List base, int data){
    return insert_at(base, base.size, data);
}

int main(){
    CircularList lsita = {0};
    for(int i = 0; i < 10; i++){
        append(&lsita, rangedrandom(5, 100));
    }

    insert_at(&lsita, 0, 0);
    insert_at(&lsita, lsita.size / 2, 1);
    insert_at(&lsita, lsita.size, 2);
  
    printf("Prev \t\t<-\t\t Current \t\t->\t\t Next\n");
    for(int i = 0; i < 13; i++){
        printf("%3d (%p) <- %3d (%p) -> %3d (%p)\n", lsita.head->prev->Data, lsita.head->prev, lsita.head->Data, lsita.head, lsita.head->next->Data, lsita.head->next);
        lsita.head = lsita.head->next;
    }
}