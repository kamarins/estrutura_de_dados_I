#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n){
    heap = (TipoCaixa*) malloc (n * sizeof(TipoCaixa)) ;
    
    return heap;
}

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap){

    free(heap);
    heap = NULL;
    return heap;

}


//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n){
    int esquerda;

    esquerda = (n/2) - 1; // primeiro no antes do no folha do heap

    while(esquerda >= 0){
        Heap_Refaz(heap,esquerda, n-1);
        esquerda --;
    }
}

//Manter como especificado
void Heap_Refaz(TipoCaixa *heap, int esq, int dir){
    int i,j,aux;

    i =  esq;
    j = i * 2 + 1;
    aux = heap[i];

    while (j <= dir){
        if (j < dir && heap[j] < heap[j+1]){
            j = j + 1;
        }

        if (aux >= heap[j]){
            break;
        }

        heap[i] = heap[j];
        i = j;
        j = i*2 +1;

    }
    
    heap[i] = aux;

}
