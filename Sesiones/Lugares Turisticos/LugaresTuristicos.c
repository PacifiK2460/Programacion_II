#include <stdio.h>

#include "string/string.h"
#include "io/io.h"
#include "project/zona.h"

int main()
{
  // Creamos el listado de las zonas
  Zonas zonas = malloc(sizeof(Zonas));
  if(zonas == 0){
    printf("Error al crear el listado de zonas\n");
    return -1;
  }

  // Cargamos las zonas en memoria
  switch (loadZonas(zonas))
  {
  case -1:
    printf("Error al cargar las zonas\n");
    return -1;
    break;
  case 0:
    printf("Sin zonas por cargar\n");
    return 0;
    break;
  default:
    printf("Se han cargado %i zonas\n", cantidadZonas(zonas));
    break;
  }

  imprimirZonas(zonas);
  int opcion = 0;
  while (1)
  {
    input("Selecciona el ID de la zona a mostrar, -1 para reimprimir las zonas: \n $> ",evaluarInt(&opcion, stdin));
    if (opcion == -1)
    {
      imprimirZonas(zonas);
    }
    else
    {
      if (opcion >= 0 && opcion < cantidadZonas(zonas))
      {
        Zona *z = getZona(zonas, opcion);
        printf("\tNombre: %s\n", z->nombre.str);
        printf("\tCosto: %i\n", z->costo);
      }
      else
      {
        printf("La opcion no es valida\n");
      }
    }
  }
}