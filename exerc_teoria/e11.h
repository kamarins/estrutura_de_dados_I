//Karine Isabelle Marins - 20.1.4057

typedef struct {
    int info;
} TItem;

typedef struct celula {
    TItem item;
    struct celula *prox;
} TCelula;

typedef struct {
    TCelula *prim;
    int tam;
} TLista;

typedef struct{
    TLista lista;
}TPilha;

//TLista implementa: 
//void TLista_Inicia ( TLista * pLista );
// void Lista_Insere ( TLista * pLista , TItem * pItem , int pos );
// int Lista_Retira ( TLista * pLista , TItem * pItem , int pos ) ;
// int Lista_Tamanho ( Tlista * lista ) ;

//implementar utilizando Tlista
void TPilha_Inicia ( TPilha **pilha);
int TPilha_EhVazia ( TPilha *pilha);
int TPilha_Push ( TPilha *pilha ,  TItem * x);/* insere no inicio */
int TPilha_Pop ( TPilha *pilha, TItem * x) ;/* retira do inicio */

