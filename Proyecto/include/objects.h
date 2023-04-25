#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "constants.h"
#include "list.h"

struct PPersonal;

typedef enum FoodType{
    HAMBURGUESAS,
    PAPAS
} FoodType;
typedef struct Producto{
    int id;
    FoodType tipo;
    char nombre[BUFFER_SIZE];
    float precio;
} Producto, *PProducto;


typedef struct ReporteDeVentas{
    void* vendedor;
    float total;
    int tiempo;
} ReporteDeVentas, *PReporteDeVentas;

typedef enum Cargo{
    COCINERO,
    VENDEDOR
} Cargo;

typedef struct Cocinero{
    int tiempo_cocinando[2];
    List PedidosAtendidos;
    int tiempo_restante;
} Cocinero, *PCocinero;

typedef struct Vendedor{
    ReporteDeVentas (*generarReporte)(struct PPersonal vendedor);
} Vendedor, *PVendedor;

typedef struct _Personal{
    int id;
    Cargo cargo;
    char nombre[BUFFER_SIZE];
    union{
        Cocinero cocinero;
        Vendedor vendedor;
    };

    int (*serialize)();
    int (*deserialize)();
} _Personal, *PPersonal;

typedef struct Encargo{
    PProducto producto;
    int cantidad;
} Encargo, *PEncargo;

typedef struct Fecha{
    int dia;
    int mes;
    int anio;
} Fecha, *PFecha;
typedef struct Pedido{
    int id;
    Fecha fecha;
    PPersonal vendedor;
    PPersonal cocinero;
    List productos; // Tipo Encargo
} Pedido, *PPedido;

typedef struct _ListadoDePersonal{
    List personal;
    int (*serialize)();
    int (*deserialize)();

    int (*addPersonal)(PPersonal personal);
} ListadoDePersonal, *PListadoDePersonal;

typedef struct _ListadoDeProductos{
    List productos;
    int (*serialize)();
    int (*deserialize)();

    int (*addProducto)(PProducto producto);
} ListadoDeProductos, *PListadoDeProductos;

typedef struct _ListadoDePedidos{
    List pedidos;
    int (*serialize)();
    int (*deserialize)();
} ListadoDePedidos, *PListadoDePedidos;

void CrearListaDePersonal();
void CrearListaDeProductos();
void CrearListaDePedidos();

