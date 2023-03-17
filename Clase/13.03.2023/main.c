#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLinkedListNode
{
    int data;
    struct DoubleLinkedListNode *next;
    struct DoubleLinkedListNode *prev;
} DoubleLinkedListNode;

typedef struct DoubleLinkedList
{
    DoubleLinkedListNode *head;
    DoubleLinkedListNode *tail;
    int size;
} DoubleLinkedList;

DoubleLinkedList *createDoubleLinkedList()
{
    DoubleLinkedList *list = calloc(1,sizeof(DoubleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int addAt(DoubleLinkedList *list, int data, int index)
{
    if (index < 0 || index > list->size)
    {
        return -1;
    }

    DoubleLinkedListNode *newNode = calloc(1,sizeof(DoubleLinkedListNode));
    newNode->data = data;

    if (list->size == 0)
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else if (index == 0)
    {
        list->head->prev = newNode;
        newNode->next = list->head;
        newNode->prev = NULL;
        list->head = newNode;
    }
    else if (index == list->size)
    {
        newNode->next = NULL;
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    else
    {
        DoubleLinkedListNode *current = list->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    list->size++;
    return 0;
}

int addFirst(DoubleLinkedList *list, int data)
{
    return addAt(list, data, 0);
}

int addLast(DoubleLinkedList *list, int data)
{
    return addAt(list, data, list->size);
}

int deleteAt(DoubleLinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return -1;
    }

    DoubleLinkedListNode *current = list->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    if (list->size == 1)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else if (index == 0)
    {
        list->head = current->next;
        list->head->prev = NULL;
    }
    else if (index == list->size - 1)
    {
        list->tail = current->prev;
        list->tail->next = NULL;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
    list->size--;
    return 0;
}

int deleteFirst(DoubleLinkedList *list)
{
    return deleteAt(list, 0);
}

int deleteLast(DoubleLinkedList *list)
{
    return deleteAt(list, list->size - 1);
}

void insertarAlInicio(DoubleLinkedList *list)
{
    int data;
    printf("Ingrese el dato: ");
    scanf("%d", &data);
    if(addFirst(list, data) == 0)
        printf("Dato insertado correctamente\n");
    else
        printf("Error al insertar el dato\n");
}

void insertarAlFinal(DoubleLinkedList *list)
{
    int data;
    printf("Ingrese el dato: ");
    scanf("%d", &data);
    if(addLast(list, data) == 0)
        printf("Dato insertado correctamente\n");
    else
        printf("Error al insertar el dato\n");
}

void insertarOrdenadamente(DoubleLinkedList *list)
{
    int data;
    printf("Ingrese el dato: ");
    scanf("%d", &data);
    if(list->size == 0){
        addFirst(list, data);
    }else{
        DoubleLinkedListNode *current = list->head;
        int index = 0;
        while(current != NULL && current->data < data){
            current = current->next;
            index++;
        }
        if(addAt(list, data, index) == 0)
            printf("Dato insertado correctamente\n");
        else
            printf("Error al insertar el dato\n");
    }
}

void eliminarAlInicio(DoubleLinkedList *list)
{
    if(deleteFirst(list) == 0)
        printf("Dato eliminado correctamente\n");
    else
        printf("Error al eliminar el dato\n");
}

void eliminarAlFinal(DoubleLinkedList *list)
{
    if(deleteLast(list) == 0)
        printf("Dato eliminado correctamente\n");
    else
        printf("Error al eliminar el dato\n");
}

void eliminarUnElemento(DoubleLinkedList *list)
{
    int data;
    printf("Ingrese el dato: ");
    scanf("%d", &data);
    DoubleLinkedListNode *current = list->head;
    int index = 0;
    while(current != NULL && current->data != data){
        current = current->next;
        index++;
    }
    if(current != NULL){
        if( deleteAt(list, index) == 0)
            printf("Dato eliminado correctamente\n");
        else
            printf("Se encontro el dato, pero no se pudo eliminar\n");
    }else{
        printf("Dato no encontrado\n");
    }
}

void buscarUnElemento(DoubleLinkedList *list)
{
    int data;
    printf("Ingrese el dato: ");
    scanf("%d", &data);
    DoubleLinkedListNode *current = list->head;
    int index = NULL;
    while(current != NULL && current->data != data){
        current = current->next;
        index++;
    }

    if(current != NULL)
        printf("El dato se encuentra en la posicion %d\n", index);
    else
        printf("El dato no se encuentra en la lista\n");
}

void imprimirListaDeInicioAFin(DoubleLinkedList *list)
{
    DoubleLinkedListNode *current = list->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
 }

void imprimirListaDeFinAInicio(DoubleLinkedList *list){
    DoubleLinkedListNode *current = list->tail;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main(){
    int opcion = 0;
    DoubleLinkedList *list = createDoubleLinkedList();
    while(1){
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar ordenadamente\n");
        printf("4. Eliminar al inicio\n");
        printf("5. Eliminar al final\n");
        printf("6. Eliminar un elemento\n");
        printf("7. Buscar un elemento\n");
        printf("8. Imprimir lista de inicio a fin\n");
        printf("9. Imprimir lista de fin a inicio\n");
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
                imprimirListaDeInicioAFin(list);
                break;
            case 9:
                imprimirListaDeFinAInicio(list);
                break;
            case 0:
                return 0;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }
}