#include "../automotriz.h"

typedef struct address{
    String street;
    int number;
} address;

typedef struct vendedor{
    int id;
    String nombre;
    String apellido;
    String correo;
    String telefono;
    address direccion;
} vendedor;

typedef struct auto{
    int id;
    double precio;
    String descripcion;
} auto;

typedef struct registro{
    int id;
    *venta vendedor;
    *auto auto;
} registro;