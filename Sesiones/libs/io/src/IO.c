#include "../IO.h"

//dummy funcs for testing
int evaluarInt(int* dest){
    char buff[1024];
    if(!fgets(buff,1024,stdin)){
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

int evaluarDouble(double* dest){
    char buff[1024];
    if(!fgets(buff,1024,stdin)){
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

int evaluarString(String* dest){
    if(!fgets(dest->str, 1024, stdin)){
        return -1;
    }
    dest->str[1024] = '\0';
    dest->str[strcspn(dest->str, "\r\n")] = 0;

    dest->len = strlen(dest->str);

    return 1;
}

int evaluarChar(char* Dest){
    if(!fgets(dest->str, 1, stdin)){
        return -1;
    }
    dest->str[1] = '\0';
    dest->str[strcspn(dest->str, "\r\n")] = 0;

    dest->len = strlen(dest->str);

    return 1;
}