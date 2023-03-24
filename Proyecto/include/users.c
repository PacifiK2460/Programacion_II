#include "users.h"

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
    PUser user;

    for(int i = 0; i < users.size; i++){
        user = (PUser)getNode(&users, i);

        if(strcmp(user->name, name) == 0 && strcmp(user->password, password) == 0){
            return user;
        }
    }

    return NULL;
}