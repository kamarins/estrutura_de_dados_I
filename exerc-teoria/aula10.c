#include "aula9.h"

void TLista_Inicia(TLista *pLista);
int TLista_EhVazia(TLista *pLista);
int TLista_Insere(TLista *pLista, TItem x,int j);
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX);


typedef struct {
    int info;
} TItem;

typedef struct celula {
    struct celula *pProx;
    struct celula *pAnterior; 
    TItem item;

} TCelula;

typedef struct {
    TCelula *pPrimeiro, //pPrimeiro terá o endereço do primeiro elemento da lista
            *pUltimo; //pUltimo terá o endereço do ultimo elemento da lista
} TLista;

void TLista_Inicia ( TLista * pLista ) {

    pLista->pPrimeiro = ( TCelula *) malloc ( sizeof ( TCelula )) ;
    pLista->pUltimo =pLista->pPrimeiro;
    pLista->pPrimeiro->pAnterior = NULL;
    pLista->pPrimeiro->pProx = NULL;
}

int TLista_EhVazia ( TLista * pLista ) {
    return ( pLista->pPrimeiro == pLista -> pUltimo );
}


int TLista_Insere( TLista * pLista , TItem x, int j ){
    TCelula *pAux;
    pAux = pLista-> pUltimo;

    pLista->pUltimo->pProx = ( TCelula *) malloc ( sizeof ( TCelula )) ;
    pLista->pUltimo->pAnterior = pAux;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx= NULL;

    free(pAux);

    return 1;
}

int TLista_RetiraPrimeiro ( TLista * pLista , TItem * pX ) {
    if ( TLista_EhVazia ( pLista ))
        return 0;

    TCelula * pAux;

    pAux = pLista->pPrimeiro;
    
    *pX = pAux->item;

    pLista->pPrimeiro->pProx = pAux->pProx;
    pLista->pPrimeiro->pAnterior = pAux->pAnterior;

    free ( pAux);

    return 1;
}



