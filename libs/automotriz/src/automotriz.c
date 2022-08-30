#include "../automotriz.h"

typedef struct address{
    String street;
    int number;
} address;

struct vendedor{
    int id;
    String nombre;
    String apellido;
    String correo;
    String telefono;
    address direccion;
};

struct automovil{
    int id;
    double precio;
    String descripcion;
};

struct registro{
    int id;
    *venta vendedor;
    *auto vehiculo;
};