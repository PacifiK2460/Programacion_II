#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "constants.h"

typedef struct User{
    int id;
    char name[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    int type;
} User, *PUser;

typedef enum UserType{
    ADMIN,
    USER
} UserType;
typedef struct ListaDeUsuarios{
    List usuarios; // Tipo User

    int (*createUser)(char* name, char* password, int type);
    void (*deleteUser)(char *name);
    int (*addUser)(PUser user);

    PUser (*login)(char* name, char* password);
    int (*serialize)();
    int (*deserialize)();
} ListaDeUsuarios, *PListaDeUsuarios;

void CrearListaDeUsuarios();