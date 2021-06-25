#include <stdio.h>

int procuraValor(int *vet, int k, int i){
    int aux;
   
    if( vet[i]==k ){
        return i ;
    }
    else 
        return  procuraValor(vet, k, i-1)   ;

    return -1;
}

int main(){
    int vet[5];
    vet[0]=2;
    vet[1]=3;
    vet[2]=4;
    vet[3]=5;
    vet[4]=9;

    int k=9;
    int i=5;

    int r=procuraValor(vet,k,i);

    if (r != -1){
        printf("k estava na posicao: %d\n", r);
    }

    return 0;
}