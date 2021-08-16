#define MAX 100

typedef int Item;
typedef struct {
    Item itens[MAX];
    int tam, ini, fim;
} Fila;

void Fila_Inicia(Fila *pFila);
int Fila_EhVazia(Fila *pFila);
int Fila_Tamanho(Fila *pFila);
int Fila_Enfileira(Fila *pFila, Item x);
int Fila_Desenfileira(Fila *pFila, Item *pX);