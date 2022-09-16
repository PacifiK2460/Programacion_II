#include "io.h"

//dummy funcs for testing
int evaluarInt(int* dest, FILE* stream) {
    long a;
    char buff[1024];
    if(!fgets(buff,1024,stream)) {
        return -1;
    }

    char *endptr;
    errno = 0;
    a = strtol(buff, &endptr, 10);

    if (errno == ERANGE)
    {
        // out of range for a long
        return 0;
    }
    if (endptr == buff)
    {
        // no character was read
        return 0;
    }
    if (*endptr && *endptr != '\n')
    {
        // *endptr is neither end of string nor newline,
        // so we didn't convert the *whole* input
        return 0;
    }
    if (a > 2147483647 || a < (-2147483647 - 1)) {
        return 0;
    }

    *dest = a;

    return 1;
}

int evaluarDouble(double* dest, FILE* stream) {
    double a;
    char buff[1024];
    if(!fgets(buff,1024,stream)){
        return -1;
    }

    char *endptr;
    errno = 0;
    a = strtof(buff, &endptr);

    if (errno == ERANGE)
    {
        // out of range for a long
        return 0;
    }
    if (endptr == buff)
    {
        // no character was read
        return 0;
    }
    if (*endptr && *endptr != '\n')
    {
        // *endptr is neither end of string nor newline,
        // so we didn't convert the *whole* input
        return 0;
    }
    if (a > 340282346638528859811704183484516925440.0000000000000000 || a < -340282346638528859811704183484516925440.0000000000000000) {
        return 0;
    }

    *dest = a;

    return 1;
}

int evaluarString(char* dest, FILE* stream) {
    if(dest != 0){
        free(dest);
    }
    
    dest = malloc(1024 * sizeof(char));

    if(!fgets(dest, 1024, stream)){
        return -1;
    }

    return 1;
}

int evaluarChar(char* Dest, FILE* stream) {
    if(!fgets(Dest, 1, stream)){
        return -1;
    }
    return 1;
}