# ifndef prioridade_h
# define prioridade_h

typedef struct{
	int identificacao;// identificacao e quando estará livre
	int tempo_vi;
	int tempo_atendimento;
} TipoCaixa;

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n);

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap);

//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n);

//Manter como especificado
void Heap_Refaz(TipoCaixa *heap, int esq, int dir);
# endif
