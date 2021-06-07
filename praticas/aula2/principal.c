#include "matriz.h"
#include<stdio.h>

int main()
{
    double **M = NULL, resultado;
    int ordem;
    char operacao; 

    lerOrdem(&ordem);
    lerOperacao(&operacao);

    M = alocaMatriz(M, ordem);
    if (M == NULL){
        printf("Memoria Insuficiente.\n");
        return(1);
    }

    lerMatriz(M, ordem);
    resultado = somaMatriz(M, ordem);
    if(operacao == 'M')
      resultado = media(resultado, ordem);
    printResultado(resultado);
    M = desalocaMatriz(M, ordem);

    
    return 0;//nao remova
}
