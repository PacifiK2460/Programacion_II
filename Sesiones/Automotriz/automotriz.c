#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../libs/io/io.h"
#include "../../libs/string/string.h"

typedef struct address{
    String* street;
    int number;
};

typedef struct vendedor{
    int id;
    String* nombre;
    String* apellido;
    String* correo;
    String* telefono;
    struct address direccion;
};

typedef struct automovil{
    int id;
    double precio;
    String* descripcion;
};

typedef struct registro{
    int id;
    struct vendedor* vendedor;
    struct automovil* vehiculo;
};

int main(){
    srand(time(0));
    struct automovil* Catalogo;
    struct vendedor* Vendedores;
    struct registro* RegistrosDeVentas;

    // Inicializado de 3 vehiculos en catalogo
    Catalogo = (struct automovil*) malloc(3 * sizeof(struct automovil));
    {
        Catalogo[0].id = rand()%100;
        Catalogo[0].precio = rand()%100000;
        Catalogo[0].descripcion = newFrom("Ford Fiesta");

        Catalogo[1].id = rand()%100;
        Catalogo[1].precio = rand()%100000;
        Catalogo[1].descripcion = newFrom("Ford Focus");

        Catalogo[2].id = rand()%100;
        Catalogo[2].precio = rand()%100000;
        Catalogo[2].descripcion = newFrom("Ford Fusion");
    }

    // Inicializado de 2 vendedores
    Vendedores = (struct vendedor*) malloc(2 * sizeof(struct vendedor));
    {
        Vendedores[0].id = rand()%100;
        Vendedores[0].nombre = newFrom("Juan");
        Vendedores[0].apellido = newFrom("Perez");

        Vendedores[1].id = rand()%100;
        Vendedores[1].nombre = newFrom("Maria");
        Vendedores[1].apellido = newFrom("Gomez");
    }

    // Inicializado de 2 registros de ventas + 1 vacio
    RegistrosDeVentas = (struct registro*) malloc(3 * sizeof(struct registro));
    {
        RegistrosDeVentas[0].id = rand()%100;
        RegistrosDeVentas[0].vendedor = &Vendedores[0];
        RegistrosDeVentas[0].vehiculo = &Catalogo[0];

        RegistrosDeVentas[1].id = rand()%100;
        RegistrosDeVentas[1].vendedor = &Vendedores[1];
        RegistrosDeVentas[1].vehiculo = &Catalogo[1];
    }

    // Monstrar registros antes de ordenar por precio
    {
        printf("Registros: \n");
        for(int i = 0; i < 2; i++){
            printf("\tRegistro %d\n", i + 1);
            printf("\tID: %d\n", RegistrosDeVentas[i].id);
            printf("\tVendedor: %s %s\n", RegistrosDeVentas[i].vendedor->nombre->str, RegistrosDeVentas[i].vendedor->apellido->str);
            printf("\tAutomovil: %s\n", RegistrosDeVentas[i].vehiculo->descripcion->str);
            printf("\tPrecio: %lf\n", RegistrosDeVentas[i].vehiculo->precio);
            printf("\n");
        }
        printf("Vehiculos: \n");
        for(int i = 0; i < 3; i++){
            printf("\tVehiculo %d\n", i + 1);
            printf("\tID: %d\n", Catalogo[i].id);
            printf("\tDescripcion: %s\n", Catalogo[i].descripcion->str);
            printf("\tPrecio: %lf\n", Catalogo[i].precio);
            printf("\n");
        }
    }

    // Registro agregado por el usuario
    {
        printf("Agrega 1 registro mas: \n");
        RegistrosDeVentas[2].id = rand()%100;

        int idVendedor;
        input("Ingrese el index del vendedor: ", evaluarInt(&idVendedor, stdin));

        int idAutomovil;
        input("Ingrese el index del automovil: ", evaluarInt(&idAutomovil, stdin));

        RegistrosDeVentas[2].vendedor = &Vendedores[idVendedor - 1];
        RegistrosDeVentas[2].vehiculo = &Catalogo[idAutomovil - 1];
    }

    // Ordenar registros por precio
    {
        struct registro aux;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(RegistrosDeVentas[i].vehiculo->precio < RegistrosDeVentas[j].vehiculo->precio){
                    aux = RegistrosDeVentas[i];
                    RegistrosDeVentas[i] = RegistrosDeVentas[j];
                    RegistrosDeVentas[j] = aux;
                }
            }
        }
    }

    // Monstrar registros despues de ordenar por precio
    {
        printf("Registros Ordenados Por Precio: \n");
        for(int i = 0; i < 3; i++){
            printf("\tRegistro %d\n", i + 1);
            printf("\tID: %d\n", RegistrosDeVentas[i].id);
            printf("\tVendedor: %s %s\n", RegistrosDeVentas[i].vendedor->nombre->str, RegistrosDeVentas[i].vendedor->apellido->str);
            printf("\tAutomovil: %s\n", RegistrosDeVentas[i].vehiculo->descripcion->str);
            printf("\tPrecio: %lf\n", RegistrosDeVentas[i].vehiculo->precio);
            printf("\n");
        }
    }

    // Liberar memoria
    {
        free(Catalogo);
        free(Vendedores);
        free(RegistrosDeVentas);
    }

}