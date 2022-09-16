#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    long X1, Y1, X2, Y2;
    scanf("%ld %ld %ld %ld", &X1, &Y1, &X2, &Y2);

    if(X1 > X2){
        long aux = X1;
        X1 = X2;
        X2 = aux;
    }

    if(Y1 > Y2){
        long aux = Y1;
        Y1 = Y2;
        Y2 = aux;
    }

    long deltaX, deltaY, result;
    // absoute difference
    deltaX = abs(X2 - X1);
    deltaY = abs(Y2 - Y1);

    result = (deltaX*deltaX) + (deltaY*deltaY);
    if(result >= (150*150)){
        printf("sana\n");
    } else {
        printf("insana\n");
    }
}