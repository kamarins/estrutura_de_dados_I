#include "buscabinaria.h"
#include <stdlib.h>
#include <stdio.h>

double *alocaTiras(double *tiras, long int n){
    tiras = (double*) malloc(n * sizeof(double));

    if(tiras == NULL){
        exit(1);
    }

    return tiras;
}

double *desalocaTira(double *tiras){
    free(tiras);
    tiras = NULL;
    return tiras;
}

void merge(double *v, int l, int m, int r){
    int size_l;
    int size_r;
    int i,j,k;

    size_l = (m - l + 1);
    size_r = (r - m);

    double *vet_l = (double*) malloc (size_l * sizeof(double));
    double *vet_r = (double*) malloc (size_r * sizeof(double));

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


void ordenar_vetor(double *v, int l, int r){
    int m;
    if (l<r){
        m = (l+r)/2;

        ordenar_vetor(v,l,m);
        ordenar_vetor(v,m+1,r);
        merge(v,l,m,r);
    }
}

double calculaArea(double *tiras, long int n){
    double area = 0;
    for(int i=0; i<n;i++){
        area += tiras[i];
    }

    return area;
}

double buscaBinaria(double *tiras, long int a, long int n){
    double esquerda = tiras[0];
    double direita = tiras[n-1];
    double corte_h, soma_areas;

    do
    {
        soma_areas = 0;
        corte_h = (esquerda + direita) / 2;

        for(int i=0; i<n; i++){
            if(tiras[i] > corte_h)
                soma_areas += tiras[i] - corte_h;
        }

        if(soma_areas > a){
            esquerda = corte_h + M;
        } else if(soma_areas < a){
            direita = corte_h - M;
        }


    } while (esquerda <= direita);
    
   
    return corte_h;
}

int verifica(long int a, double *tiras, long int n){
    double area = calculaArea(tiras,n);

    if (area < a){
        return 0;
    } else if(area == a){
        return 1;
    } 

    return -1;
}