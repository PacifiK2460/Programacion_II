#include "objects.h"

ListadoDeUsuarios Usuarios;

int serialize(){
    //Serialize the users file
    FILE *file = fopen("users.txt", "w");
    if(file == NULL){
        return 0;
    }

    fprintf(file, "%d\n", Usuarios.usuarios.size);

    int i = 0;
    for(PUser user = (PUser)getNode(&Usuarios.usuarios, i); user != NULL; i++ ){
        fprintf(file, "%s %s %d\n", user->username, user->password, user->puntos);
    }    

    fclose(file);

    return 1;
}

int deserialize(){
    //Deserialize the users file
    FILE *file = fopen("users.txt", "r");
    if(file == NULL){
        //If non-existent, create it and print 0 users
        file = fopen("users.txt", "w+");
        if(file == NULL){
            return 0;
        }

        fprintf(file, "%d\n", 0);
        fclose(file);

        file = fopen("users.txt", "r");
        if(file == NULL){
            return 0;
        }
    }

    int size;
    fscanf(file, "%d\n", &size);

    for(int i = 0; i < size; i++){
        PUser user = (PUser)malloc(sizeof(User));
        fscanf(file, "%s %s %d\n", user->username, user->password, &user->puntos);
        if(addNode(&Usuarios.usuarios, user) == 0){
            return 0;
        }
    }

    fclose(file);

    return 1;
}

PUser login(char* username, char* password){
    for(int i = 0; i < Usuarios.usuarios.size; i++){
        PUser user = (PUser)getNode(&Usuarios.usuarios, i);
        if(strcmp(user->username, username) == 0 && strcmp(user->password, password) == 0){
            return user;
        }
    }

    return NULL;
}

int laodDatabase(){
    Usuarios.deserealizar = deserialize;
    Usuarios.serealizar = serialize;
    Usuarios.login = login;

    if(Usuarios.deserealizar() == 0){
        return 0;
    }

    return 1;
}