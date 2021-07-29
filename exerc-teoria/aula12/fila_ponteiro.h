typedef int Item;

typedef struct celula{
    Item item;
    struct celula *prox;
}Celula;

typedef struct{
    Celula *prox,*fim;
    int tam;
} Fila;

void Fila_Inicia(Fila *pFila);
int Fila_EhVazia(Fila *pFila);
int Fila_Tamanho(Fila *pFila);
int Fila_Enfileira(Fila *pFila, Item x);
int Fila_Desenfileira(Fila *pFila, Item *pX);