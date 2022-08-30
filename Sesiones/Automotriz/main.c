#include <stdio.h>
#include <stdlib.h>
#include "io/io.h"
#include "automotriz/automotriz.h"

int main(){

    automovil* Catalogo;
    vendedor* Vendedores;

    // Inicializado de 3 vehiculos en catalogo
    Catalogo = (automovil*) malloc(3 * sizeof(automovil));
    {
        Catalogo[0].id = 1;
        Catalogo[0].precio = 500000;
        setStringFromChar(Catalogo[0].descripcion, "Ford F-550");

        Catalogo[1].id = 2;
        Catalogo[1].precio = 1000000;
        setStringFromChar(Catalogo[1].descripcion, "Chevrolet Silverado");

        Catalogo[2].id = 3;
        Catalogo[2].precio = 1500000;
        setStringFromChar(Catalogo[2].descripcion, "Dodge Ram");
    }

    // Inicializado de 2 vendedores
    Vendedores = (vendedor*) malloc(2 * sizeof(vendedor));
    {
        Vendedores[0].id = 1;
        setStringFromChar(Vendedores[0].nombre, "Juan");
        setStringFromChar(Vendedores[0].apellido, "Perez");
        setStringFromChar(Vendedores[0].correo, "juanperez@hotmail.com");
        setStringFromChar(Vendedores[0].telefono = "1234567890");
        setStringFromChar(Vendedores[0].direccion.street = "Calle X");
        Vendedores[0].direccion.number = 123;

        Vendedores[1].id = 2;
        setStringFromChar(Vendedores[1].nombre, "Maria");
        setStringFromChar(Vendedores[1].apellido, "Gomez");
        setStringFromChar(Vendedores[1].correo, "mariagomez@hotmail.com");
        setStringFromChar(Vendedores[1].telefono = "0987654321");
        setStringFromChar(Vendedores[1].direccion.street = "Calle Y");
        Vendedores[1].direccion.number = 456;
    }

    registro* RegistrosDeVentas;
    // Registramos 2 ventas
    RegistrosDeVentas = (registro*) malloc(2 * sizeof(registro));
    {
        RegistrosDeVentas[0].id = 1;
        RegistrosDeVentas[0].vendedor = Vendedores[0];
        RegistrosDeVentas[0].vehiculo = Catalogo[0];

        RegistrosDeVentas[1].id = 2;
        RegistrosDeVentas[1].vendedor = Vendedores[1];
        RegistrosDeVentas[1].vehiculo = Catalogo[1];
    }

    printf("Crea 1 sola venta más.\n");
    printf("Vehiculos disponibles: ");
    for(int i = 0; i < 3; i++){
        printf("[%d] %s $%d\n",i, Catalogo[i].descripcion, Catalogo[i].precio);
    }
    printf("Vendedores disponibles: ");
    for(int i = 0; i < 2; i++){
        printf("[%d] %s %s\n",i, Vendedores[i].nombre, Vendedores[i].apellido);
    }

    // Agregamos una venta más
    int idVehiculo, idVendedor;
    inputInt("Ingrese el id del vehiculo: ", &idVehiculo);
    inputInt("Ingrese el id del vendedor: ", &idVendedor);
    RegistrosDeVentas[2].id = 3;
    RegistrosDeVentas[2].vendedor = Vendedores[idVendedor];
    RegistrosDeVentas[2].vehiculo = Catalogo[idVehiculo];

    print("Info recolectada:\n");
    printf("Vehiculo: %s $%d", RegistrosDeVentas[2].vehiculo.descripcion, RegistrosDeVentas[2].vehiculo.precio);
    printf("Vendedor: %s %s", RegistrosDeVentas[2].vendedor.nombre, RegistrosDeVentas[2].vendedor.apellido);
    
    return 1;
}