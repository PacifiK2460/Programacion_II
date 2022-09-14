#include <stdio.h>

int main(){
    double X = 0;
    scanf("%lf", &X);

    double result = (((X+(X*X))/(5*X+3)) + X) * (((X+(X*X))/(5*X+3))/(((X+(X*X))/(5*X+3)) + (2*X)));
    printf("%lf", result);
}