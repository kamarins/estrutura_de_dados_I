//Karine Isabelle Marins / 20.1.4057

#include "aula9.h"

void TLista_FazVazia (TLista* pLista ) {
 pLista -> primeiro = INICIO ;
 pLista -> ultimo = pLista -> primeiro ;
}

int TLista_EhVazia (TLista* pLista ) {
 return ( pLista -> ultimo == pLista -> primeiro );
}

int TLista_Insere (TLista* pLista , TItem x) {
 if ( pLista->ultimo == MaxTam )
    return 0; /* lista cheia */
 pLista -> item [ pLista->ultimo ++] = x;
    return 1;
}

void TLista_Imprime (TLista*pLista ) {
 int i;

 for (i = pLista->primeiro ; i < pLista -> ultimo ; i ++)
    printf ("%d\n", pLista -> item[i].chave );
}

void Tlista_Concatena(TLista *pLista1, TLista *pLista2){
    int i ;

    for (i = 0; i <  pLista2->ultimo; i++) {
        pLista1->item[pLista2->ultimo] = pLista1->item[i];
        pLista1->ultimo++; 
    }
}

void TLista_Divide(TLista *pLista1, TLista *pLista2, int i){
    pLista2->primeiro = pLista1->item[i].chave;

    for (int j=0; j < pLista1->ultimo - i; j++){
        pLista2->item[j] = pLista1->item[i+1];
    }

    pLista2->ultimo = pLista1->ultimo;
    pLista1->ultimo = pLista1->item[i].chave;
   
}

void TLista_Copia(TLista *pLista1, TLista *pLista2){
    pLista2->primeiro = pLista1->primeiro;
    pLista2->ultimo = pLista1->ultimo;

    for (int i=0; i<pLista1->ultimo; i++){
        pLista2->item[i]=pLista1->item[i];
    }

}

int TLista_Pesquisa(TLista *pLista1, int j){

   for (int i=0; i<pLista1->ultimo; i++){
       if ( pLista1->item[i].chave == j ){
           return 0;
       }
   }

   return 1;
}

void TLista_Imprime (TLista* pLista) {
    int i;
    for (i = pLista->primeiro ; i< pLista->ultimo ; i ++)
        printf ("%d\n", pLista->item[i].chave );
}