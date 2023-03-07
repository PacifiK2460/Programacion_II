#include<stdlib.h>
#include<stdio.h>

#include "include/menu.h"

int main(){
    Menu* menu = newMenu(L"Title", L"Subtitle");
    if(menu == NULL){
        printf("Error: Could not allocate memory for menu");
        return -1;
    }

    if(addOption(menu, L"Option 1", L"Subtitle 1", NULL, NULL) == -1){
        printf("Error: Could not allocate memory for option 1");
        return -1;
    }

    if(addOption(menu, L"Option 2", L"Subtitle 2", NULL, NULL) == -1){
        printf("Error: Could not allocate memory for option 2");
        return -1;
    }

    drawMenu(menu);
}