#include "../automotriz.h"

typedef struct _address {
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

typedef struct{
    int id;
    double precio;
    String descripcion;
} auto;

typedef struct {
    int id;
    *venta vendedor;
    *auto auto;
} registro;