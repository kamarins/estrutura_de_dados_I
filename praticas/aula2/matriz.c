#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem){
    scanf("%i", ordem);
    getchar();
}
  
//manter como especificado
double **alocaMatriz(double **M, int ordem){
    M = (double **) malloc (ordem * sizeof(double *));

    for (int i=0; i <ordem; i++){
        M[i]= (double *) malloc (ordem * sizeof(double));

        if (M[i]== NULL){
            printf("Memoria Insuficiente.\n");
            exit(1);
        }

    }

    return M;
}

//manter como especificado
double **desalocaMatriz(double **M, int ordem){
    for (int i=0; i<ordem; i++)
        free(M[i]);
    free(M);

    return M;
}

//manter como especificado
void lerOperacao(char *operacao){
    scanf("%c", operacao);
  
}

void lerMatriz(double **M, int ordem){
    for (int i = 0; i < ordem; i++){
        for (int j=0; j< ordem; j++){
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double **M, int ordem){
    double soma=0.0;

    int limite = (ordem-1) ;
    for(int i=0; i <= ((ordem/2.0)-(2.0)) ; i++){
        for (int j=i+1; j<limite; j++){
            soma += M[i][j];
        }
        limite--;
    }

    return soma;
}

double media(double resultado, int ordem){
   double media=0.0;

   media = (resultado) / (((ordem*ordem)/4.0) - (ordem/2.0));
   return media;
}
 
void printResultado(double resultado){
    printf("%.1lf\n", resultado);
}
