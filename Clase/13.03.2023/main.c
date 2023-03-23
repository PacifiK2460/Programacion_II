#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct circularLinkedList{
    int data;
    struct node *head;
    struct node *tail;
} CircularLinkedList;

CircularLinkedList *createCircularLinkedList(){
    CircularLinkedList *list = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void imprimir(CircularLinkedList *list){
    Node *temp = list->head;
    
    if(temp == NULL){
        printf("Lista vacia\n");
        return;
    }

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != list->head);
    printf("\n");
}

void insertarAlInicio(CircularLinkedList *list){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Ingrese un numero: ");
    scanf(" %d", &newNode->data);
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    }else{
        newNode->next = list->head;
        list->head = newNode;
        list->tail->next = newNode;
    }
}

void insertarAlFinal(CircularLinkedList *list){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Ingrese un numero: ");
    scanf(" %d", &newNode->data);
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    }else{
        list->tail->next = newNode;
        list->tail = newNode;
        list->tail->next = list->head;
    }
}

void eliminarAlInicio(CircularLinkedList *list){
    if(list->head == NULL){
        printf("Lista vacia\n");
        return;
    }

    Node *temp = list->head;
    list->head = list->head->next;
    list->tail->next = list->head;
    free(temp);
}

void eliminarAlFinal(CircularLinkedList *list){
    if(list->head == NULL){
        printf("Lista vacia\n");
        return;
    }

    Node *temp = list->head;
    while(temp->next != list->tail){
        temp = temp->next;
    }
    list->tail = temp;
    list->tail->next = list->head;
    free(temp->next);
}

void buscarUnElemento(CircularLinkedList *list){
    if(list->head == NULL){
        printf("Lista vacia\n");
        return;
    }

    int num = 0;
    printf("Ingrese un numero: ");
    scanf(" %d", &num);

    Node *temp = list->head;
    do{
        if(temp->data == num){
            printf("El numero %d se encuentra en la lista\n", num);
            return;
        }
        temp = temp->next;
    }while(temp != list->head);
    printf("El numero %d no se encuentra en la lista\n", num);
}

void insertarOrdenadamente(CircularLinkedList *list){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Ingrese un numero: ");
    scanf(" %d", &newNode->data);
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    }else{
        Node *temp = list->head;
        if(newNode->data < temp->data){
            newNode->next = list->head;
            list->head = newNode;
            list->tail->next = newNode;
        }else{
            while(temp->next != list->head && temp->next->data < newNode->data){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void eliminarUnElemento(CircularLinkedList *list){
    if(list->head == NULL){
        printf("Lista vacia\n");
        return;
    }

    int num = 0;
    printf("Ingrese un numero: ");
    scanf(" %d", &num);

    Node *temp = list->head;
    if(temp->data == num){
        list->head = list->head->next;
        list->tail->next = list->head;
        free(temp);
    }else{
        while(temp->next != list->head && temp->next->data != num){
            temp = temp->next;
        }
        if(temp->next == list->head){
            printf("El numero %d no se encuentra en la lista\n", num);
        }else{
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
        }
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    int opcion = 0;
    CircularLinkedList *list = createCircularLinkedList();
    while(1){
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar ordenadamente\n");  
        printf("4. Eliminar al inicio\n");
        printf("5. Eliminar al final\n");
        printf("6. Eliminar un elemento\n");
        printf("7. Buscar un elemento\n");
        printf("8. Imprimir lista\n");
        printf("0. Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                insertarAlInicio(list);
                break;
            case 2:
                insertarAlFinal(list);
                break;
            case 3:
                insertarOrdenadamente(list);
                break;
            case 4:
                eliminarAlInicio(list);
                break;
            case 5:
                eliminarAlFinal(list);
                break;
            case 6:
                eliminarUnElemento(list);
                break;
            case 7:
                buscarUnElemento(list);
                break;
            case 8:
                imprimir(list);
                break;
            case 0:
                return 0;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }
}