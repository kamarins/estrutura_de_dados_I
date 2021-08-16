#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
void TArvore_Inicia (TNo **pRaiz){
    *pRaiz = NULL;
}

//Manter como especificado
void TArvore_Insere_Raiz (TNo **ppRaiz , TItem x){
    
    if (*ppRaiz == NULL ) {
        *ppRaiz = TNo_Cria(x);
        return;
    }

    TArvore_Insere(*ppRaiz, x) ;

}

//Manter como especificado
int TArvore_Insere (TNo *pRaiz , TItem x){
    if ( pRaiz == NULL ) return -1; // arvore vazia

    if (x.chave < pRaiz->item.chave ) {
        if ( pRaiz->pEsq == NULL ) {
            pRaiz->pEsq = TNo_Cria (x);
            return 1;
        }
        return TArvore_Insere(pRaiz->pEsq , x);
    }

    if (x.chave > pRaiz->item.chave ) {
        
        if ( pRaiz-> pDir == NULL ) {
            pRaiz->pDir = TNo_Cria(x);
            return 1;
        }
        return TArvore_Insere(pRaiz->pDir, x);
    }

    return 0;
    
}

//Manter como especificado
TNo *TNo_Cria (TItem x){

    TNo *pAux = (TNo*) malloc(sizeof(TNo));
    pAux->item = x;
    pAux->pEsq = NULL ;
    pAux->pDir = NULL ;
    return pAux ;
} 

//Manter como especificado
void Prefixa(TNo *p){

    if (p == NULL ) return ;

    printf (" %d", p->item.chave ) ;
    Prefixa (p->pEsq );
    Prefixa (p->pDir );
}

//Manter como especificado
void Infixa(TNo * p){
    
    if (p == NULL ) return ;

    Infixa(p->pEsq) ;
    printf (" %d", p->item.chave ) ;
    Infixa(p->pDir) ;
}

//Manter como especificado
void Posfixa(TNo * p){

    if (p == NULL ) return ;

    Posfixa (p->pEsq );
    Posfixa (p->pDir );
    printf (" %d", p->item.chave ) ;
}
