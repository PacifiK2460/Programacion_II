#include <stdio.h>

int main(){
    int ZONA = 0;
    double CANTIDAD = 0;
    scanf("%d,%lf\n", &ZONA, &CANTIDAD);
    switch (ZONA){
    case 12:
        CANTIDAD *= 2;
        break;
    case 15:
        CANTIDAD *= 2.2;
        break;
    case 18:
        CANTIDAD *= 4.5;
        break;
    case 19:
        CANTIDAD *= 3.5;
        break;
    case 23:
        CANTIDAD *= 6;
        break;
    case 25:
        CANTIDAD *= 6;
        break;
    case 29:
        CANTIDAD *= 5;
        break;
    }
    printf("%d", CANTIDAD);

    return 0;
}