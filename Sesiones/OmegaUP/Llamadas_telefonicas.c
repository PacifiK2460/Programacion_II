#include <stdio.h>

int main(){
    int ZONA = 0;
    double CANTIDAD = 0;
    while (1)
    {
        if(ZONA != 0)
            printf("\n");

        if(scanf("%d %lf", &ZONA, &CANTIDAD) == EOF)
            break;

        if(CANTIDAD < 0)
            CANTIDAD *= -1;

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
        default:
            CANTIDAD *= 0;
            break;
        }
        if(CANTIDAD == (int)CANTIDAD)
            printf("%d", (int)CANTIDAD);
        else
            printf("%.1lf", CANTIDAD);

    }
    

    return 0;
}