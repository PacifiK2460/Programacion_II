#include "users.h"

List users;

int createUser(char* name, char* password, UserType type){
    PUser user = (PUser)calloc(1, sizeof(User));
    if(user == NULL)
        return 0;

    strcpy(user->name, name);
    strcpy(user->password, password);

    addNode(&users, user);
}

void deleteUser(PUser user){
    deleteNode(&users, user);
}

PUser login(char* name, char* password){
    
    // Read users from file
    /*
        POR HACER:
            Leer los usuarios del archivo y agregarlos a la lista de usuarios

             !!!!!!! addNode(&users, xx);

        --- 

            NOTA:
                NO HAY NINGUN USUARIO

                abrir archivo, en caso de que no haya crearlo
                if(archivo vacio){
                    escribir que hay 0 usuarios
                }
            
                for(i=0;i<cant_nodos; i++){
                    leer nodo en la lista de usuarios
                }
                
    */
    {
        FILE* file = fopen("users.dat", "r+");
        if(file == NULL){
            file = fopen("users.dat", "w+");
            if(file == NULL)
                return NULL;

            fprintf(file, "0\n");
        }
        
        int number_of_users = 0;
        fscanf(file, "%d\n", &number_of_users);

        for(int i = 0; i < number_of_users; i++){
            PUser user = (PUser)calloc(1, sizeof(User));
            if(user == NULL){
                fclose(file);
                return NULL;
            }

            fscanf(file, " %s %s %d", user->name, user->password, &user->type);
            addNode(&users, user);
        }
        fclose(file);
    }
    
    PUser user;

    for(int i = 0; i < users.size; i++){
        user = (PUser)getNode(&users, i);

        if(strcmp(user->name, name) == 0 && strcmp(user->password, password) == 0){
            return user;
        }
    }

    return NULL;
}

int AddUser(PUser user){
    if(user == NULL)
        return -1;

    addNode(&users, user);

    // Write users to file
    {
        FILE* file = fopen("users.dat", "w+");
        if(file == NULL)
            return -1;

        fprintf(file, "%d\n", users.size);

        for(int i = 0; i < users.size; i++){
            user = (PUser)getNode(&users, i);
            fprintf(file, "%s %s %d\n", user->name, user->password, user->type);
        }
        fclose(file);
    }
}