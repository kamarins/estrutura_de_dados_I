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

    esquerda = (n/2) - 1; // primeiro noh antes do noh folha do heap

    while(esquerda >= 0){
        Heap_Refaz(heap,esquerda, n-1);
        esquerda --;
    }
}

//Manter como especificado
void Heap_Refaz(TipoCaixa *heap, int esq, int dir){

    int i,j;
    TipoCaixa aux;

    i =  esq;
    j = i * 2 + 1; //primeiro filho de i
    aux = heap[i]; 

    while (j <= dir){
        if (j < dir){

            if (heap[j].tempo_atendimento > heap[j+1].tempo_atendimento) // verifica se o pai e menor que o filho
                j++;

            else if(heap[j].tempo_atendimento == heap[j+1].tempo_atendimento && heap[j].identificacao > heap[j+1].identificacao)
                    j++;

        } 
        
        if (aux.tempo_atendimento < heap[j].tempo_atendimento)
            break;

        else if(aux.tempo_atendimento == heap[j].tempo_atendimento && aux.identificacao < heap[j].identificacao)
                break;
                    
        
        heap[i] = heap[j];
        i = j;
        j = i*2 +1; //j e o primeiro filho de i

    }
    
    heap[i] = aux;

}
