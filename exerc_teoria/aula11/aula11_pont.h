typedef int Item;

typedef struct celula{
    Item item;
    struct celula *prox;
} Celula;

typedef struct {
    Celula *cabeca;
   //int tam;
}Pilha;

void Pilha_Inicia(Pilha *pilha);

int Pilha_Eh_Vazia(Pilha *pilha);

int Pilha_Push(Pilha *pilha, Item item); //inserir

int Pilha_Pop(Pilha *pilha, Item *item); //remove elemento

void Pilha_Tamanho(Pilha *pilha);

void Pilha_Libera(Pilha *pilha);