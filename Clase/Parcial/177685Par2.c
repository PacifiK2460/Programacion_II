#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 5

int rangedrand(int min, int max){
    return rand() % (max - min + 1) + min;
}

typedef struct Node{
    int data;
    struct Node *next;
}Node, *PNode;

typedef struct List{
    PNode head;
} List, *PList;

void add(PList list, int data){
    PNode node = (PNode)calloc(1,sizeof(Node));
    if (node == NULL){
        printf("No se pudo reservar memoria");
        return;
    }

    node->data = data;
    if (list->head == NULL){
        list->head = node;
    }else {
        node->next = list->head;
        list->head = node;
    }
}

int main(){
    srand(time(NULL));
    printf("Santiago de la cruz Martinez Lara | 177685\n");

    PList list = (PList)calloc(1,sizeof(List));
    if (list == NULL){
        printf("No se pudo reservar memoria");
        return 1;
    }

    for(int i = 0; i < ITEMS; i++){
        int n = rangedrand(10,30);
        printf("%d ", n);
        add(list, n);
    }
    printf("\n");
    
    for(PNode node = list->head; node != NULL; node = node->next){
        printf("%d ", node->data);
    }
    printf("\n");

    int to_search = rangedrand(10,30);
    printf("Buscando %d\n", to_search);

    for(PNode node = list->head; node != NULL; node = node->next){
        if (node->data == to_search){
            printf("Se encontro el elemento en la direccion %p\n", node);
            return 0;
        }
    }
    printf("No se encontro el elemento\n");
    system("pause");
    return 0;

}