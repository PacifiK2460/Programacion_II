#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "list.h"

// struct PPersonal;

typedef enum FoodType
{
    HAMBURGUESAS,
    PAPAS
} FoodType;
typedef struct Producto
{
    union {
        int id;
        struct _Producto* IDptr;
    };
    FoodType tipo;
    char nombre[BUFFER_SIZE];
    float precio;
} Producto, *PProducto;

typedef enum Cargo
{
    COCINERO,
    VENDEDOR
} Cargo;

typedef struct Cocinero
{
    int tiempo_cocinando[2];
    List PedidosAtendidos;
    int tiempo_restante;
} Cocinero, *PCocinero;

typedef struct Vendedor
{
    struct ReporteDeVentas (*generarReporte)(void* vendedor);
} Vendedor, *PVendedor;

typedef struct ReporteDeVentas
{
    union {
        PVendedor vendedor;
        int vendedorID;
    };
    float total;
    int tiempo;
} ReporteDeVentas, *PReporteDeVentas;

typedef enum UserType
{
    ADMIN,
    USER
} UserType;

typedef struct _Personal
{
    // int id;
    union {
        int id;
        struct _Personal* IDptr;
    };
    Cargo cargo;
    UserType tipo;
    char nombre[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    union
    {
        Cocinero cocinero;
        Vendedor vendedor;
    };
} _Personal, *PPersonal;

typedef struct Encargo
{
    union {
        PProducto producto;
        int productoID;
    };
    int cantidad;
} Encargo, *PEncargo;

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;
} Fecha, *PFecha;
typedef struct Pedido
{
    union {
        int id;
        struct _Pedido* IDptr;
    };
    Fecha fecha;
    union {
        PPersonal vendedor;
        int vendedorID;
    };
    union {
        PPersonal cocinero;
        int cocineroID;
    };
    List productos; // Tipo Encargo
} Pedido, *PPedido;

typedef struct _ListadoDePersonal
{
    List personal;
    int (*serialize)();
    int (*deserialize)();

    int (*createUser)(char *name, char *password, int type);
    void (*deleteUser)(char *name);
    int (*addUser)(PPersonal user);
    PPersonal (*login)(char *name, char *password);
} ListadoDePersonal, *PListadoDePersonal;

typedef struct _ListadoDeProductos
{
    List productos;
    int (*serialize)();
    int (*deserialize)();

    int (*addProducto)(PProducto producto);
} ListadoDeProductos, *PListadoDeProductos;

typedef struct _ListadoDePedidos
{
    List pedidos;
    int (*serialize)();
    int (*deserialize)();
} ListadoDePedidos, *PListadoDePedidos;

void CrearListaDePersonal();
void CrearListaDeProductos();
void CrearListaDePedidos();
