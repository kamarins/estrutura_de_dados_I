//fila de inteiros 

#define MAX 100

typedef int Item;

typedef struct {
    Item itens[MAX];
    int tam, ini, fim;
} Fila;

typedef struct { 
    Item itens[MAX];
    int tamanho;
} Pilha;