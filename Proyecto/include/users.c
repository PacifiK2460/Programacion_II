#include "users.h"

int createUser(char* name, char* password, int type){
    PUser user = (PUser)calloc(1, sizeof(User));
    if(user == NULL)
        return 0;

    strcpy(user->name, name);
    strcpy(user->password, password);

    addNode(&Usuarios.usuarios, user);
    Usuarios.serialize();
}

void deleteUser(char* name){
    PUser user;

    for(int i = 0; i < Usuarios.usuarios.size; i++){
        user = (PUser)getNode(&Usuarios.usuarios, i);

        if(strcmp(user->name, name) == 0){
            deleteNode(&Usuarios.usuarios, user);
            Usuarios.serialize();
            return;
        }
    }
}

PUser login(char* name, char* password){    
    PUser user;

    for(int i = 0; i < Usuarios.usuarios.size; i++){
        user = (PUser)getNode(&Usuarios.usuarios, i);

        if(strcmp(user->name, name) == 0 && strcmp(user->password, password) == 0){
            return user;
        }
    }

    return NULL;
}

int AddUser(PUser user){
    if(user == NULL)
        return -1;

    addNode(&Usuarios.usuarios, user);
    Usuarios.serialize();
}

int serialize(){
    // Abrir el archivo
    FILE* file = fopen("users.bin", "w+");
    if(file == NULL)
        return 0;

    // Escribir el numero de usuarios
    fprintf(file, "%d\n", Usuarios.usuarios.size);

    // Escribir los usuarios
    int contador = 0;
    for(PUser usuario = getNode(&Usuarios.usuarios, 0); usuario != NULL ; usuario = getNode(&Usuarios.usuarios, ++contador)){
        fprintf(file, "%d %s %s %d\n", usuario->id, usuario->name, usuario->password, usuario->type);
    }

    fclose(file);

    return 1;
}

int deserialize(){
    // Abrir el archivo
    FILE* file = fopen("users.bin", "r+");
    if(file == NULL)
        return 0;

    // Leer el numero de usuarios
    int size;
    fscanf(file, "%d", &size);

    // Leer los usuarios
    for(int i = 0; i < size; i++){
        PUser user = (PUser)calloc(1, sizeof(User));
        if(user == NULL)
            return 0;

        if(fscanf(file, "%d %s %s %d", &user->id, user->name, user->password, &user->type) != 4){
            free(user);
            return 0;
        }
        addNode(&Usuarios.usuarios, user);
    }

    fclose(file);

    return 1;
}

void CrearListaDeUsuarios(){
    Usuarios.createUser = createUser;
    Usuarios.deleteUser = deleteUser;
    Usuarios.login = login;
    Usuarios.serialize = serialize;
    Usuarios.deserialize = deserialize;
}