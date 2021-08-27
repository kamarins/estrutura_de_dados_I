#include "buscabinaria.h"
#include <stdlib.h>
#include <stdio.h>

long int *alocaTiras(long int *tiras, long int n){
    tiras = (long int*) malloc(n * sizeof(long int));

    if(tiras == NULL){
        exit(1);
    }

    return tiras;
}

long int *desalocaTira(long int *tiras){
    free(tiras);
    tiras = NULL;
    return tiras;
}

void merge(long int *v, int l, int m, int r){
    int size_l;
    int size_r;
    int i,j,k;

    size_l = (m - l + 1);
    size_r = (r - m);

    long int *vet_l = (long int*) malloc (size_l * sizeof(long int));
    long int *vet_r = (long int*) malloc (size_r * sizeof(long int));

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
            v[k]=vet_r[j++];
        }
        else if(j == size_r){
            v[k]= vet_l[i++];
        }
        else if(vet_l[i] < vet_r[j]){
            v[k]= vet_l[i++];

        }
        else {
            v[k]=vet_r[j++];

        }
    }

    free(vet_l);
    free(vet_r);

} 


void ordenar_vetor(long int *v, int l, int r){
    int m;
    if (l<r){
        m = (l+r)/2;

        ordenar_vetor(v,l,m);
        ordenar_vetor(v,m+1,r);
        merge(v,l,m,r);
    }
}

long int calculaArea(long int *tiras, long int n){
    long int area = 0;
    for(int i=0; i<n;i++){
        area += tiras[i];
    }

    return area;
}

double buscaBinaria(long int *tiras, long int a, long int n){
    double esquerda = tiras[0];
    double direita = tiras[n-1];
    double corte_h, soma_areas;

    do
    {
        soma_areas = 0;
        corte_h = (double) (esquerda + direita) / 2;

        for(int i=0; i<n; i++){
            if(tiras[i] > corte_h) //verifica quais tiras ultrapassam o tamanho do corte inicial
                soma_areas += tiras[i] - corte_h; //pega a area de cada tira
        }

        if(soma_areas > a){ //se a area procurada for menor que a soma ate o momento, vou para a esquerda 
            esquerda = corte_h + decimais;
        } else if(soma_areas < a){ //se nao vou para a direita
            direita = corte_h - decimais;
        }


    } while (esquerda <= direita && a != soma_areas);

   
    return corte_h;
}

int verifica(long int a, long int *tiras, long int n){
    long int area = calculaArea(tiras,n);

    if (area < a){
        return 0;
    } else if(area == a){
        return 1;
    } 

    return -1;
}