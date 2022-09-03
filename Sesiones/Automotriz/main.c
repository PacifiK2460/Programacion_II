#include <stdio.h>
#include <stdlib.h>
#include "../../libs/io/io.h"
#include "../../libs/automotriz/automotriz.h"

int main(){

    automovil* Catalogo;
    vendedor* Vendedores;

    // Inicializado de 3 vehiculos en catalogo
    Catalogo = (automovil*) malloc(3 * automovilSize());
    {
        setAutomovil(&Catalogo[0], 1, 10000, newFrom("Ford Fiesta"));
        setAutomovil(&Catalogo[1], 2, 20000, newFrom("Ford Focus"));
        setAutomovil(&Catalogo[2], 3, 30000, newFrom("Ford Fusion"));
    }

    // Inicializado de 2 vendedores
    Vendedores = (vendedor*) malloc(2 * sizeof(vendedor));
    {
        setVendedor(&Vendedores[0], 1, newFrom("Juan"), newFrom("Perez"), newFrom("juanperez@hotmail.com"), newFrom("123456789"), 0);

        setVendedor(&Vendedores[1], 2, newFrom("Maria"), newFrom("Gomez"), newFrom("mariagomez@hotmail.com"), newFrom("987654321"), 0);
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