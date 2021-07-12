#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da pilha
void Pilha_Inicia(Pilha *pilha) {
    //aloca uma nova celula(item) na pilha 
    pilha->cabeca = (Celula *) malloc(sizeof(Celula));
    //o prox da nova celula aponta para null
    pilha->cabeca->prox = NULL;
}

//Retorna se a pilha esta vazia
int Pilha_EhVazia(Pilha *pilha) {
    //se a pilha for vazia, retorn 1, caso contrario retorna 0
    if (pilha->cabeca->prox == NULL)
        return 1;
    return 0;
}

// Insere um item no topo da pilha
int Pilha_Push(Pilha *pilha, Item item) {
    //aloca-se espaço de memoria para o item a ser inserido
    Celula *celula = (Celula *)malloc(sizeof(Celula));

    if(celula == NULL){
        return 0;
    }

    //insere o novo item no espaco reservado a ele
    celula->item = item;

    //faz com que a nova celula aponte para o prox da cabeca
    celula->prox = pilha->cabeca->prox;
    
    //o prox da cabeca aponta para a nova celula
    pilha->cabeca->prox = celula;

    return 1;
}

// Retira o item do topo da pilha
int Pilha_Pop(Pilha *pilha, Item *item) {

    //verifica se a pilha e vazia
    if(Pilha_EhVazia(pilha) == 1){
        return 0;
    }

    //cria-se um apontador para nao perder a referencia o prox
    Celula *aux = pilha->cabeca->prox;

    //a cabeca aponta para o elemento apos o primeiro
    pilha->cabeca->prox = aux->prox;

    //atualiza-se o item
    (*item) = aux->item;

    //libera-se o auxiliar
    free(aux);

    return 1;
}

//Remove cada elemento de uma pilha e libera a memória
void Pilha_Esvazia(Pilha *pilha) {
    //apontador para a cabeca
    Celula *celula = pilha->cabeca;

    //auxiliar para nao perder a referencia
    Celula *aux;

    while(celula != NULL){
        Pilha_Pop(pilha, &pilha->cabeca->item);
        aux = celula->prox;
        free(celula);
        celula = aux;
    }
}
