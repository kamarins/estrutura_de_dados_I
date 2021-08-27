#include "hash.h"
#include <stdlib.h>
#include <stdio.h>

//Manter como especificado
void TLista_Inicia(TLista *pLista){

    pLista->pPrimeiro = (TCelula*) calloc(1,sizeof(TCelula));
    pLista->pPrimeiro->pProx = NULL;
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->tamanho = 0;
} 

//Manter como especificado
int TLista_EhVazia(TLista *pLista){
    return pLista->tamanho == 0;
}

//Manter como especificado
int TLista_Insere(TLista *pLista , TItem x){
    pLista->pUltimo->pProx = (TCelula*)malloc(sizeof(TCelula));

    if (pLista->pUltimo->pProx == NULL){
        return 0;
    }

    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;
    pLista->tamanho++;

    return 1;
}

//Manter como especificado
void THash_Inicia(THash *hash, int nro_listas){
    hash->n = 0;
    hash->nro_listas = nro_listas;

    hash->v = (TLista*) malloc(nro_listas * sizeof(TLista));
    
    for (int i=0; i<nro_listas; i++){
        TLista_Inicia(&hash->v[i]);
    }

}

//Manter como especificado
int THash_H(THash *hash, TChave chave){
    return (chave % hash->nro_listas);
}

//Manter como especificado
TCelula *THash_PesquisaCelula(THash *hash, TChave chave){

    int i = THash_H (hash,chave);
    TCelula *aux ;
    
    if ( TLista_EhVazia(&hash->v[i]) )
        return NULL; 
    
    aux = hash->v[i].pPrimeiro;

    while (aux->pProx->pProx != NULL && chave != aux->pProx->item.chave)
        aux = aux->pProx ;
    
    if (chave != aux->pProx->item.chave)
        return NULL ;
    else
        return aux ; 

}

//Manter como especificado
int THash_Insere (THash *hash, TItem x){

    if (THash_PesquisaCelula(hash, x.chave) == NULL ) {
        TLista_Insere(&hash->v[THash_H(hash, x.chave)], x);
        hash->n++;
        return 1;
    }
    return 0;
}
