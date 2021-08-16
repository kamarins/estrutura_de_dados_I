//Karine Isabelle Marins - 20.1.4057
#include "e11.h"
#include <stdlib.h>


typedef struct {
    int info;
} TItem;

typedef struct celula {
    TItem item;
    struct celula *prox;
} TCelula;

typedef struct {
    TCelula *prim;
    int tam;
} TLista;

typedef struct{
    TLista lista;
}TPilha;

//TLista implementa: 
//void TLista_Inicia ( TLista * pLista );
// void Lista_Insere ( TLista * pLista , TItem * pItem , int pos );
// int Lista_Retira ( TLista * pLista , TItem * pItem , int pos ) ;
// int Lista_Tamanho ( Tlista * lista ) ;


//implementar utilizando Tlista
void TPilha_Inicia ( TPilha *pilha){
   TLista_Inicia(&pilha->lista);
}
  
int TPilha_EhVazia (TPilha *pilha){
    if (pilha->lista.prim == NULL) 
        return 1;
    return 0;
}

int TPilha_Push ( TPilha *pilha , TItem *x){
    //insere o item na posicao 0
    if (Lista_Insere(pilha->lista,x,0))
        return 1;
    return 0;
}

int TPilha_Pop ( TPilha *pilha, TItem *x){
    //retira do inicio, considerando a posicao 0 como a primeira
    if (Lista_Retira(pilha->lista, x,0))
        return 1;
    return 0;
}

/*RESPOSTA*/
//A implementação é eficiente pois do modo implementado o custo é constante.