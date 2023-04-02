#pragma once

#include <stdlib.h>

#include "constants.h"
#include "list.h"

typedef struct Product {
    int id;
    char name[BUFFER_SIZE];
    float price;
} Product;

typedef enum Mes{
    ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE 
}Mes;

typedef struct Date{
    int day;
    Mes month;
    int año;
}Date;

typedef enum State{
    TERMINADO, PENDIENTE, EN_PROCESO
}State;

typedef struct Pedidos{
    Product* producto;
    int cantidad;
    State estado;
    Date fecha;
}Pedidos;