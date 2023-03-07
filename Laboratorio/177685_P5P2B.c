#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<string.h>

#include "colors.h"

int main(){
    setlocale(LC_ALL, "es_MX.UTF-8");
    wprintf(BOLD L"Martinez Lara Santiago de la cruz"  RESET L" | " BOLD L"177685\n" RESET);
}