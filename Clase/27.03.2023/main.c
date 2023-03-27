#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AgendaEntry{
    char name[20];
    char surname[12];
} AgendaEntry, *PAgendaEntry;

typedef struct Node{
    PAgendaEntry data;
    struct Node *next;
    struct Node *prev;
} Node, *PNode;

typedef struct DoubleCircularList{
    PNode head;
    PNode tail;
    int size;
} DoubleCircularList, *PDoubleCircularList;

PDoubleCircularList list;

PAgendaEntry newEntry(){
    PAgendaEntry entry = (PAgendaEntry)calloc(1,sizeof(AgendaEntry));
    if(entry == NULL){
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    printf("Nombre: ");
    scanf("%s", entry->name);
    printf("Apellido: ");
    scanf("%s", entry->surname);
    return entry;
}

void agregarAlInicio(){
    PNode node = (PNode)calloc(1,sizeof(Node));
    if(node == NULL){
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    node->data = newEntry();

    if(list->head == NULL){
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    }else{
        node->next = list->head;
        node->prev = list->tail;
        list->head->prev = node;
        list->tail->next = node;
        list->head = node;
    }
    list->size++;
}

void agregarAlFinal(){
    PNode node = (PNode)calloc(1,sizeof(Node));
    if(node == NULL){
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    node->data = newEntry();

    if(list->head == NULL){
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    }else{
        node->next = list->head;
        node->prev = list->tail;
        list->head->prev = node;
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void insertarOrdenadamente(){
    PNode node = (PNode)calloc(1,sizeof(Node));
    if(node == NULL){
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    node->data = newEntry();

    if(list->head == NULL){
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    }else{
        PNode aux = list->head;
        while(aux != list->tail && strcmp(aux->data->surname, node->data->surname) < 0){
            aux = aux->next;
        }
        if(strcmp(aux->data->surname, node->data->surname) < 0){
            node->next = list->head;
            node->prev = list->tail;
            list->head->prev = node;
            list->tail->next = node;
            list->tail = node;
        }else{
            node->next = aux;
            node->prev = aux->prev;
            aux->prev->next = node;
            aux->prev = node;
            if(aux == list->head){
                list->head = node;
            }
        }
    }
    list->size++;
}

void recorrerDeInicioAFin(){
    PNode aux = list->head;
    while(aux != list->tail){
        printf("%s [%s]\n", aux->data->name, aux->data->surname);
        aux = aux->next;
    }
}

void recorrerDeFinAInicio(){
    PNode aux = list->tail;
    while(aux != list->head){
        printf("%s [%s]\n", aux->data->name, aux->data->surname);
        aux = aux->prev;
    }
}

int main(){
    int opcion = 1;
    do{
        printf(
            "1. Agregar al inicio\n"
            "2. Agregar al final\n"
            "3. Insertar Ordenadamente\n"
            "4. Eliminar al inicio\n"
            "5. Eliminar al final\n"
            "6. Eliminar por nombre\n"
            "7. Buscar\n"
            "8. Recorrer de inicio a fin\n"
            "9. Recorrer de fin a inicio\n"
            "0. Salir\n"
        );
        scanf(" %d", &opcion);
        switch(opcion){
            case 1:
                agregarAlInicio();
                break;
            case 2:
                agregarAlFinal();
                break;
            case 3:
                insertarOrdenadamente();
                break;
            case 8:
                recorrerDeInicioAFin();
                break;
            case 9:
                recorrerDeFinAInicio();
                break;
        }
    }while(opcion != 0);
}

