#include <stdio.h>
#include <time.h>

int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

typedef struct{
    int Data;
    Node* prev;
    Node* next;
} Node;

typedef struct{
    Node* head;
    int size;
} List;

int insert_at(List base, int index, int data)

int main(){
    List lsita;
}