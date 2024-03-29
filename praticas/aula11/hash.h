# ifndef hash_h
# define hash_h

// TAD lista
typedef int TChave;

typedef struct {
  TChave chave;
} TItem;

typedef struct celula {
  struct celula *pProx;
  TItem item;
} TCelula;

typedef struct {
  TCelula *pPrimeiro, *pUltimo;
  int tamanho;
} TLista;

void TLista_Inicia(TLista *pLista);
int TLista_EhVazia(TLista *pLista);
int TLista_Insere(TLista *pLista , TItem x);

//TAD hash

typedef struct {
  int n; //nro de itens
  int nro_listas; //tamanho do vetor de listas
  TLista *v; //array de listas
} THash ;

//Manter como especificado
void THash_Inicia(THash *hash, int nro_listas);
//Manter como especificado
int THash_H(THash *hash, TChave chave);
//Manter como especificado
TCelula *THash_PesquisaCelula(THash *hash, TChave chave);
//Manter como especificado
int THash_Insere (THash *hash, TItem x);

# endif
