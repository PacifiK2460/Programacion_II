#include <stdio.h>

int main(){
    int X = 0;
    scanf("%d", &X);

    double result = (((X+(X*X))/(5*X+3)) + X) * (((X+(X*X))/(5*X+3))/(((X+(X*X))/(5*X+3)) + (2*X)));
    printf("%d", result);
}