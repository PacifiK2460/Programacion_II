#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AgendaEntry
{
    char name[20];
    char phone_number[12];
} AgendaEntry, *PAgendaEntry;

typedef struct Node
{
    PAgendaEntry data;
    struct Node *next;
    struct Node *prev;
} Node, *PNode;

typedef struct DoubleCircularList
{
    PNode head;
    PNode tail;
    int size;
} DoubleCircularList, *PDoubleCircularList;

PDoubleCircularList list;

PAgendaEntry newEntry()
{
    PAgendaEntry entry = (PAgendaEntry)calloc(1, sizeof(AgendaEntry));
    if (entry == NULL)
    {
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    printf("Nombre: ");
    scanf(" %s", entry->name);
    printf("Telefono: ");
    scanf(" %s", entry->phone_number);
    return entry;
}

void agregarAlInicio()
{
    PNode node = (PNode)calloc(1, sizeof(Node));
    if (node == NULL)
    {
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    node->data = newEntry();

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    }
    else
    {
        node->next = list->head;
        node->prev = list->tail;
        list->head->prev = node;
        list->tail->next = node;
        list->head = node;
    }
    list->size++;
}

void agregarAlFinal()
{
    PNode node = (PNode)calloc(1, sizeof(Node));
    if (node == NULL)
    {
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    node->data = newEntry();

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    }
    else
    {
        node->next = list->head;
        node->prev = list->tail;
        list->head->prev = node;
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void insertarOrdenadamente()
{
    PNode node = (PNode)calloc(1, sizeof(Node));
    if (node == NULL)
    {
        printf("No hay memoria disponible");
        system("pause");
        exit(1);
    }
    node->data = newEntry();

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        node->next = node;
        node->prev = node;
    }
    else
    {
        PNode aux = list->head;
        while (aux != list->tail && strcmp(aux->data->phone_number, node->data->phone_number) < 0)
        {
            aux = aux->next;
        }
        if (strcmp(aux->data->phone_number, node->data->phone_number) < 0)
        {
            node->next = list->head;
            node->prev = list->tail;
            list->head->prev = node;
            list->tail->next = node;
            list->tail = node;
        }
        else
        {
            node->next = aux;
            node->prev = aux->prev;
            aux->prev->next = node;
            aux->prev = node;
            if (aux == list->head)
            {
                list->head = node;
            }
        }
    }
    list->size++;
}

void recorrerDeInicioAFin()
{
    PNode aux = list->head;
    {
        int i = 0;
        for (i = 0; i < list->size; i++)
        {
            printf("%s: %s\n", aux->data->name, aux->data->phone_number);
            aux = aux->next;
        }
    }
}

void recorrerDeFinAInicio()
{
    PNode aux = list->tail;
    {
        int i;
        for (i = 0; i < list->size; i++)
        {
            printf("%s: %s\n", aux->data->name, aux->data->phone_number);
            aux = aux->prev;
        }
    }
}

void eliminarAlInicio()
{
    if (list->head == NULL)
    {
        printf("La lista esta vacia");
        return;
    }
    PNode temp = list->head;
    list->head = list->head->next;
    list->head->prev = list->tail;
    list->tail->next = list->head;
    free(temp->data);
    free(temp);
    list->size--;
}

void eliminarAlFinal()
{
    if (list->head == NULL)
    {
        printf("La lista esta vacia");
        return;
    }
    PNode temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    free(temp->data);
    free(temp);
    list->size--;
}

void eliminarPorNombre()
{
    if (list->head == NULL)
    {
        printf("La lista esta vacia");
        return;
    }
    char name[20];
    printf("Nombre: ");
    scanf(" %s", name);
    PNode aux = list->head;
    while (aux != list->tail && strcmp(aux->data->name, name) != 0)
    {
        aux = aux->next;
    }
    if (strcmp(aux->data->name, name) == 0)
    {
        if (aux == list->head)
        {
            eliminarAlInicio();
        }
        else if (aux == list->tail)
        {
            eliminarAlFinal();
        }
        else
        {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux->data);
            free(aux);
            list->size--;
        }
    }
    else
    {
        printf("No se encontro el nombre");
    }
}

void buscar()
{
    if (list->head == NULL)
    {
        printf("La lista esta vacia");
        return;
    }
    char name[20];
    printf("Nombre: ");
    scanf(" %s", name);
    PNode aux = list->head;
    while (aux != list->tail && strcmp(aux->data->name, name) != 0)
    {
        aux = aux->next;
    }
    if (strcmp(aux->data->name, name) == 0)
    {
        printf("%s: %s\n", aux->data->name, aux->data->phone_number);
    }
    else
    {
        printf("No se encontro el nombre");
    }
}

int main()
{
    list = (PDoubleCircularList)calloc(1, sizeof(DoubleCircularList));

    int opcion = 1;
    do
    {
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
            "0. Salir\n");
        scanf(" %d", &opcion);
        switch (opcion)
        {
        case 1:
            agregarAlInicio();
            break;
        case 2:
            agregarAlFinal();
            break;
        case 3:
            insertarOrdenadamente();
            break;
        case 4:
            eliminarAlInicio();
            break;
        case 5:
            eliminarAlFinal();
            break;
        case 6:
            eliminarPorNombre();
            break;
        case 7:
            buscar();
            break;
        case 8:
            recorrerDeInicioAFin();
            break;
        case 9:
            recorrerDeFinAInicio();
            break;
        default:
            break;
        }
    } while (opcion != 0);

    {
        PNode aux = list->head;
        int i;
        for (i = 0; i < list->size; i++)
        {
            PNode temp = aux;
            aux = aux->next;
            free(temp->data);
            free(temp);
        }
    }
}
