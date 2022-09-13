#include <stdio.h>

int main(){
    long X1, Y1, X2, Y2;
    scanf("%ld %ld %ld %ld", &X1, &Y1, &X2, &Y2);
    long distancia = (X2-X1)*(X2-X1) + (Y2-Y1)*(Y2-Y1);
    if(distancia <= 150*150){
        printf("Sana");
    }else{
        printf("Insana");
    }
}