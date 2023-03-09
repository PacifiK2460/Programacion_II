#include<stdlib.h>
#include<stdio.h>
#include<wchar.h>
#include<locale.h>

#include "include/menu.h"

int main(){
    // set locale to universal
    setlocale(LC_ALL, " ");

    Menu* menu = newMenu(L"Title", L"Subtitle");
    if(menu == NULL){
        printf("Error: Could not allocate memory for menu");
        return -1;
    }

    if(addOption(menu, L"Option 1", L"Subtitle 1") == -1){
        printf("Error: Could not allocate memory for option 1");
        return -1;
    }

    if(addOption(menu, L"Option 2", L"Subtitle 2") == -1){
        printf("Error: Could not allocate memory for option 2");
        return -1;
    }

    int result = displayMenu(menu);

    if(result == 0){
        wprintf(BOLD GREEN L"Success: "RESET L"Menu cerrado correctamente" );
    }
    else if(result == -1){
        wprintf(BOLD RED L"Error: "RESET L"No se pudo inicializar el menú" );
        return -1;
    } else if(result == -2){
        wprintf(BOLD YELLOW L"Warn: "RESET L"Salida temprana no manejada" );
        return -1;
    } else {
        wprintf(L"Codigo de salida no manejado: %d", result);
    }
}