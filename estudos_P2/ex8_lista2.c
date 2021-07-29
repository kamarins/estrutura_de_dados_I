//percorrer a lista, achar o menor valor e colocar no começo da lista ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
} TItem;

typedef struct celula {
    TItem item;
    struct celula *prox;
} TCelula;

typedef struct {
    TCelula *prim;
    TCelula *ult;
    int tam;
} TLista;

//Inicia as variaveis da lista
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
void TLista_Imprime(TLista *pLista) {
    
    //o conteudo do endereço para o qual aux aponta recebe prox
    TCelula *Aux = pLista->prim->prox;

    while(Aux != NULL) {
       
        printf("|%d| ", Aux->item.x);
        Aux = Aux->prox;

    }
    printf("\n");
}

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


void MoveMenor(TLista *Lista){
    TCelula *Aux = Lista->prim->prox;
    TCelula *menor;
    // TItem menor;


    if (TLista_EhVazia(Lista))
        return ;

    while( Aux->prox != NULL){
        
        if (Aux->item.x < menor->item.x )
            menor = Aux; //aqui ta recebendo uma celula

        Aux = Aux->prox;
    }


    menor->prox = Lista->prim->prox;
    Lista->prim->prox = menor; 
    TCelula *aux = Lista->prim->prox; 
    Lista->prim->prox = aux->prox;


    Lista->prim->prox = menor;

}
void Troca(TLista *pLista1, int i){

    TCelula *Aux = pLista1->prim->prox;
    int cont=0;

    if (TLista_EhVazia(pLista1) || i+1 >= pLista1->tam)
        return ;

    while( Aux->prox != NULL){
        
        if (cont == i-1)
            break;

        cont++;
        Aux = Aux->prox;
    }

    TCelula *ap1,*ap2;
    
    ap1 = Aux->prox;
    ap2 = ap1->prox;

    Aux->prox = ap2;
    ap1->prox = ap2->prox;
    ap2->prox = ap1;
    

}

int main(){
    TLista lista;
    TItem x;

    TLista_Inicia(&lista);

    for (int i=0; i<10; i++){
        scanf("%d",&x.x);
        TLista_InsereFinal(&lista,x);
    }

    TLista_Imprime(&lista);
    Troca(&lista,7);
    TLista_Imprime(&lista);

    TLista_Esvazia(&lista);

    return 0;
}






//percorrer a lista, achar o menor valor e colocar no começo da lista ;
