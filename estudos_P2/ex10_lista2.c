
// #include "fila_vetor.h"
#define MAX 100

typedef int Item;

typedef struct {
    Item itens[MAX];
    int tam, ini, fim;
} Fila;

void Fila_Inicia(Fila *pFila){
    pFila->tam = 0;
    pFila->ini = 0;
    pFila->fim = MAX-1;
}

int Fila_EhVazia(Fila *pFila){
    if (pFila->tam == 0)
        return 1;
    return 0;
}

int Fila_Tamanho(Fila *pFila){
    return pFila->tam;
}

int Fila_Enfileira(Fila *pFila, Item x){
    if(pFila->tam < MAX){
        pFila->fim = (pFila->fim + 1) % MAX;
        pFila->itens[pFila->fim] = x;
        pFila->tam++;

        return 1;
    }
    return 0;

}

int Fila_Desenfileira(Fila *pFila, Item *pX){
    if(pFila->tam > 0){
        *pX = pFila->itens[pFila->ini];
        pFila->ini = (pFila->ini + 1) % MAX;
        pFila->tam--;
        return 1;
    }
    return 0;
}