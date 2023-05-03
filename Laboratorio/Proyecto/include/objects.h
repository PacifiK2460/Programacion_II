#pragma once

#include "constants.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _User{
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    int puntos;
} User, *PUser;


typedef struct _ListadoDeUsuarios{
    List usuarios;

    int (*serealizar)();
    int (*deserealizar)();
    PUser (*login)(char* username, char* password);
} ListadoDeUsuarios, *PListadoDeUsuarios;

int loadDatabase();