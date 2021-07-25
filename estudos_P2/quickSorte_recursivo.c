#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *v, int n){

    for(int i=0; i<n; i++){
        printf("|%d| ", v[i]);
    }
    printf("\n");
}

int partition(int *v, int l, int r){
    int x,i,j,aux;

    x = v[r];
    i = l-1;

    for (j = l; j < r; j++){
        if (v[j] <= x){
            i = i+1;
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
        }
    }

    aux = v[i+1];
    v[i+1] = v[r];
    v[r] = aux;

    return i+1;
}


void quickSort(int *v, int l, int r){
    int q;

    if (l <r){
        q = partition(v,l,r);
        quickSort(v,l,q-1);
        quickSort(v,q+1,r);
    }
}

int main(){
    int v[7];

    v[0]=3;
    v[1]=4;
    v[2]=9;
    v[3]=2;
    v[4]=5;
    v[5]=1;
    v[6]=8;
    

    quickSort(v,0,6);
    printf("\nvetor ordenado: ");
    imprimeVetor(v,7);
    printf("\n");

    return 0;
}