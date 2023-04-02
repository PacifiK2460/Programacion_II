#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "constants.h"

typedef enum UserType{
    ADMIN,
    USER
} UserType;

typedef struct User{
    int id;
    char name[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    UserType type;
    List ordenes; // Tipo producto
    int timepo_de_preparacion;
} User, *PUser;

int createUser(char* name, char* password, UserType type);
void deleteUser(PUser user);
PUser login(char* name, char* password);

int addUser(PUser user);