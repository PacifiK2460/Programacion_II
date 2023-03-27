#pragma once
#include <string.h>
#include "list.h"

#define BUFFER_SIZE 1024

typedef enum UserType{
    ADMIN,
    USER
} UserType;

typedef struct User{
    char name[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    UserType type;
} User, *PUser;

int createUser(char* name, char* password, UserType type);
void deleteUser(PUser user);
PUser login(char* name, char* password);
