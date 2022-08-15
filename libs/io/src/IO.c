#include "../io.h"

//dummy funcs for testing
int evaluarInt(int* dest, FILE* stream) {
    char buff[1024];
    if(!fgets(buff,1024,stream)) {
        return -1;
    }

    char *endptr;
    errno = 0;
    *dest = strtol(buff, &endptr, 10);

    if(errno == ERANGE || endptr == buff || (*endptr && *endptr != '\n')){
        *dest = 0;
    }

    return 1;
}

int evaluarDouble(double* dest, FILE* stream) {
    char buff[1024];
    if(!fgets(buff,1024,stream)){
        return -1;
    }

    char *endptr;
    errno = 0;
    *dest = strtof(buff, &endptr);

    if(errno == ERANGE || endptr == buff || (*endptr && *endptr != '\n')){
        *dest = 0;
    }

    return 1;
}

int evaluarString(String* dest, FILE* stream) {
    if(dest->str != 0){
        free(dest->str);
    }
    
    dest->str = calloc(1024 * sizeof(char));

    if(!fgets(dest->str, 1024, stream)){
        return -1;
    }


    dest->str[1024] = '\0';
    dest->str[strcspn(dest->str, "\r\n")] = 0;

    dest->len = strlen(dest->str);

    return 1;
}

int evaluarChar(char* Dest, FILE* stream) {
    if(!fgets(Dest, 1, stream)){
        return -1;
    }
    return 1;
}