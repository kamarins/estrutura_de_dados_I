#include <stdio.h>


double potencia(int b, int exp){
    if (exp == 0){
        return 1;
    } else if(exp>0){
        return (b * potencia(b,exp - 1));
    } else{
        return (1 / potencia(b,-exp));
    }
}

int main(){
    int b=2;
    int exp=5;
    double r;

    r = potencia(b,exp);

    printf("r = %lf.0", r);

    return 0;
}