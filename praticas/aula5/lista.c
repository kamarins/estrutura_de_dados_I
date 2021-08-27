#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {

    //aloca memoria para as duas celulas
    pLista->prim = (TCelula*) calloc(1,sizeof(TCelula));
    
    //o apontador prox da primeira celula aponta para a ultima
    pLista->prim->prox = NULL;

    //o apontador anterior da ultima celula aponta para a primeira
    pLista->ult = pLista->prim;

    pLista->tam = 0;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    //retorna 1 se a lista for vazia e 0 caso contrario
    return pLista->tam == 0;
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {

    pLista->ult->prox = (TCelula*)malloc(sizeof(TCelula));

    if (pLista->ult->prox == NULL){
        return 0;
    }

    pLista->ult = pLista->ult->prox;
    pLista->ult->item = x;
    pLista->ult->prox = NULL;
    pLista->tam++;

    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if(pLista->tam == 0)
        return 0;
    
    //definindo para onde cada ponteiro irá apontar
    TCelula *aux = pLista->prim->prox; 
    pLista->prim->prox = aux->prox;
    
    *pX = aux->item;

    free(aux);
    aux = NULL;

    pLista->tam--;

    return 1;

}

// Imprime os elementos da lista
// void TLista_Imprime(TLista *pLista) {
    
//     //o conteudo do endereço para o qual aux aponta recebe prox
//     TCelula *Aux = pLista->prim->prox;

//     while(Aux != NULL) {
       
//         printf("%s ", Aux->item.nome);
//         Aux = Aux->prox;

//     }

// }

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    //o conteudo do endereço para o qual aux aponta recebe prox
   TCelula *Aux = pLista->prim->prox;
   TCelula *prox;
    
    while(Aux != pLista->ult) {
        prox = Aux->prox;
        free(Aux);
        Aux = prox;
    }

    free(pLista->prim);
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
    
    if(TLista_EhVazia(pLista2) == 1){
       return ;
    }

    pLista1->ult->prox = pLista2->prim->prox;
    pLista1->ult = pLista2->ult;
    pLista1->tam += pLista2->tam;

    //lista2 vazia
    pLista2->prim->prox = NULL;
    pLista2->ult = pLista2->prim;
    pLista2->tam = 0;

}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){

    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    TCelula *Aux = pLista1->prim;

    while( Aux->prox != NULL){

        if (strcmp(Aux->prox->item.nome,str) == 0)
            break;

        Aux = Aux->prox;
    }

    pLista2->ult->prox = Aux->prox;
    Aux->prox = pLista2->prim->prox;

    pLista1->tam += pLista2->tam;

    //lista2 vazia
    pLista2->prim->prox = NULL;
    pLista2->ult = pLista2->prim;
    pLista2->tam = 0;

}
