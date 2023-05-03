#include <conio.h>
#include <stdio.h>
#include <windows.h>

#include "../../include/menu.h"
#include "../../include/colors.h"


void holdScreen(){
    printf(RESET BOLD "Presiona cualquier tecla para continuar..." RESET);
    getch();
}

int main( void )
{
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
    }

    PMenu menu = newMenu(BOLD "⚡ BlackBoard RUSH" RESET, "Selecciona alguna de las siguientes opciones");

    {
        if(menu == NULL){
            printf(RESET RED "Error al crear el menu" RESET);
            holdScreen();
            return 1;
        }

        if(addOption(menu, "Iniciar Sesión", "Inicia sesión para jugar")){
            printf(RESET RED"Error al agregar la opcion" RESET);
            holdScreen();
            return 1;
        }
        if(addOption(menu, "Registrarse", "Registrate para jugar")){
            printf(RESET RED"Error al agregar la opcion" RESET);
            holdScreen();
            return 1;
        }
        if(addOption(menu, "Mostrar Puntajes", "Muestra los puntajes de los jugadores")){
            printf(RESET RED"Error al agregar la opcion" RESET);
            holdScreen();
            return 1;
        }
        if(addOption(menu, "Salir", "Salir del juego")){
            printf(RESET RED"Error al agregar la opcion" RESET);
            holdScreen();
            return 1;
        }
    }

    displayMenu(menu);

   /* Display message until key is pressed. */
   while( !_kbhit() )
      _cputs( "Hit me!! " );

   /* Use _getch to throw key away. */
   printf( "\nKey struck was '%c'\n", _getch() );
   system("pause");
}