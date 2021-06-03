#include "matriz.h"
#include<stdio.h> 

void lerOperacao(char *operacao){
    scanf("%s", operacao);
}

void lerMatriz(double M[][12]){
    for (int i = 0; i <= 11; i++){
        for (int j=0; j<= 11; j++){
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double M[][12]){
    double soma=0.0;
    int limite=11;
    for(int i=0; i<= 4 ; i++){
        for (int j=i+1;j<limite;j++){
            soma += M[i][j];
        }
        limite--;
    }
}

double media(double resultado){
    double media=0.0;
    media = resultado/ 30.0;
}

void printResultado(double resultado){
    printf("%.1lf\n", resultado);
}
