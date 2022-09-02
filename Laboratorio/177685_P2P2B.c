#include "info/info.h"
#include <stdio.h>

int main(){
    printInfo();
    
    int a = 1, b = 2;
    int* ip;

    printf("%d %d\n", a, b);
    printf("%X %X\n", &a, &b);
    printf("%X\n", ip);
    
    ip = &a;
    printf("IP toma 1:  a (%X) = %d\n", &a, a);
    b = *ip;
    printf("b toma el valor de a, %d %d\n", a, b);

    int c = 2, d = 5, e[] = {1,10,30,44}, i, *pa, *pb, *pc;
    for(int i = 0; i < 4; i++){
        printf("[%X] = %d ",e+i e[i]);
    }
    printf("\n");

    pa = &a;
    printf("La dirección de PA es indepentiente (%X), su valor es el de a: %d", pa, *pa);

    b = *pa + 1;
    printf("\nEl valor de b es el de a + 1: %d", b);

    pc = c;
    printf("\nLa dirección de PC es independiente (%X), su valor es el del primer elemento de c[0]: %d", pc, *pc);

    b = *(pc + 1);
    printf("\nEl valor de b es el de c + 1 / c[1]: %d", b);

    pb = &b;
    printf("\nLa dirección de PB es independiente (%X), su valor es la dirección de b: %d y el puntero es %d", pb,&b, *pb);

    *pb = 0;
    *pb += 2;
    printf("\nEl valor de b es el de b + 2: (b) %d | (pb) %d", b, *pb);

    (*pb)--;
    printf("\nEl valor de b es el de b - 1: %d", b);
}