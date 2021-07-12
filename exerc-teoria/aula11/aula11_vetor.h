#define N 100 //tamanho maximo

typedef int Item;

typedef struct { 
    Item itens[N];
    int tamanho;
} Pilha;

void Pilha_Inicia(Pilha *pilha);

int Pilha_Eh_Vazia(Pilha *pilha);

int Pilha_Push(Pilha *pilha, Item item); //inserir

int Pilha_Pop(Pilha *pilha, Item *item); //remove elemento

void Pilha_Tamanho(Pilha *pilha);