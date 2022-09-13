#include <stdio.h>
#include <math.h>

int main(){
    long X1, Y1, X2, Y2;
    scanf("%ld %ld %ld %ld", &X1, &Y1, &X2, &Y2);

    long deltaX = X2 - X1;
    long deltaY = Y2 - Y1;

    long distancia = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    if(distancia < 150)
        printf("insana");
    else 
        printf("sana");
}