#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {

    pLista -> pPrimeiro = ( TCelula *) malloc ( sizeof ( TCelula )) ;
    pLista -> pUltimo = pLista -> pPrimeiro ;
    pLista -> pPrimeiro -> pProx = NULL ;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {

    return ( pLista -> pPrimeiro == pLista -> pUltimo );
} 

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {

    pLista -> pUltimo -> pProx =( TCelula *) malloc ( sizeof ( TCelula ));
    pLista -> pUltimo = pLista -> pUltimo -> pProx ;
    pLista -> pUltimo -> Item = x;
    pLista -> pUltimo -> pProx = NULL ;

    return 1;

}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {

    if ( TLista_EhVazia ( pLista ))
        return 0;

    TCelula * pAux;
    pAux = pLista -> pPrimeiro -> pProx ;

    * pX = pAux -> Item ;
    pLista -> pPrimeiro -> pProx = pAux -> pProx ;

    free (pAux);

    return 1;

}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {

    TCelula *pAux;
    for (pAux =pLista->pPrimeiro->pProx, pAux != NULL; pAux = pAux->pProx){
            printf("%d ", pAux->Item.nome);
    }

    printf("\n");
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    TCelula* pAux1 = pLista;

    while (pAux1 != NULL) {
        TCelula* pAux2 = pAux1->pProx; 
        
        free(pAux1); 
        pAux1 = pAux2; 
    }

}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){

    // TCelula *pAux;

    // for (pAux=pLista2->pPrimeiro->pProx; pAux != NULL; pAux = pAux->pProx){
    //     pLista1->pUltimo->pProx=pLista2->pPrimeiro->pProx;
    //     pAux->Item.nome=pLista2->pPrimeiro->Item.nome;
    // }

    if (pLista1->pUltimo == NULL ){
        pLista1->pUltimo = pLista2;
    }
    else 
        TLista_append(pLista1->pUltimo->pProx,pLista2);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    if (pLista1->pPrimeiro->pProx != NULL){
        TCelula *pAux;
        pAux = (*TCelula) malloc (sizeof(Tcelula));

        
    }
        
}
