#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){

    vetor = (int*) malloc(n * sizeof(int));
    return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){

    free(vetor);
    vetor = NULL;
    return vetor;

}

void merge(int *v, int l, int m, int r,int *movimentos){
    
    int size_l;
    int size_r;
    int i,j,k;

    size_l = (m - l + 1);
    size_r = (r - m);

    int *vet_l = (int*) malloc (size_l * sizeof(int));
    int *vet_r = (int*) malloc (size_r * sizeof(int));

    for (i=0; i<size_l;i++){
        vet_l[i]=v[i+l];
    }

    for (j=0; j<size_r;j++){
        vet_r[j]=v[m+j+1];
    }
    

    i=0;
    j=0;

    for ( k = l; k <= r;  k++){
        
        if (i == size_l){
            v[k] = vet_r[j++];

        }
        else if(j == size_r){
            v[k] = vet_l[i++];
        }
        else if(vet_l[i] <= vet_r[j]){
            v[k] = vet_l[i++];
        }
        else {
            v[k] = vet_r[j++];
           *movimentos += (size_l - i);
          
        }
        
    }
    
    free(vet_l);
    free(vet_r);

} 


void mergesort(int *v, int l, int r, int *movimentos){
    int m;
    if (l<r){
        
        m = (l+r)/2;
        mergesort(v,l,m,movimentos);
        mergesort(v,m+1,r,movimentos);
        merge(v,l,m,r,movimentos);
        
    }
}



void ordenacao(int *vetor, int n, int *movimentos){
    mergesort(vetor, 0, n-1,movimentos);
}

