#include "aula11_pont.h"
#include <stdlib.h>

void Pilha_Inicia(Pilha *pilha){

    pilha->cabeca = (Celula *) malloc(sizeof(Celula));
    pilha->cabeca->prox = NULL;
}

int Pilha_Eh_Vazia(Pilha *pilha){
    if (pilha->cabeca->prox == NULL)
        return 1;
    return 0;
}   

//inserir
int Pilha_Push(Pilha *pilha, Item item){
    //alocar espaço de menoria pro item
    Celula *celula = (Celula *)malloc(sizeof(Celula));

    if(celula == NULL){
        return 0;
    }

    celula->item = item;
    celula->prox = pilha->cabeca->prox;
    pilha->cabeca->prox = celula;

    return 1;

}

//remove elemento
int Pilha_Pop(Pilha *pilha, Item *item){
    if(Pilha_Eh_Vazia(pilha)){
        return 0;
    }

    Celula *celula = pilha->cabeca->prox;
    pilha->cabeca->prox = celula->prox;
    (*item) = celula->item;
    free(celula);

    return 1;
}

void Pilha_Tamanho(Pilha *pilha){
    Celula *aux = pilha->cabeca->prox;

    int tamanho = 0;

    while(aux != NULL){
        tamanho++;
        aux = aux->prox;
    }

    return tamanho;
}

//ou cria um tamanho dentro da struct
// void Pilha_Tamanho(Pilha *pilha){
//     return pilha->tam;
// }

void Pilha_Libera(Pilha *pilha){
    Celula *celula = pilha->cabeca;
    Celula *aux;

    while(celula != NULL){
        aux = celula->prox;
        free(celula);
        celula = aux;

    }
}