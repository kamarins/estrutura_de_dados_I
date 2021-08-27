//Escreva um algoritmo recursivo que conte o número de folhas de uma árvore binária.

#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave chave;
} TItem ;

typedef struct No {
    TItem item;
    struct No *pEsq, *pDir; 
} TNo ;

typedef TNo *TArvore;

void TArvore_Inicia (TNo **pRaiz);
void TArvore_Insere_Raiz (TNo **ppRaiz , TItem x);
int TArvore_Insere (TNo *pRaiz , TItem x);
TNo * TNo_Cria (TItem x);
//retira
void Prefixa(TNo *p);
void Infixa(TNo *p);
void Posfixa(TNo *p);

//Manter como especificado
void TArvore_Inicia (TNo **pRaiz){
    *pRaiz = NULL;
}

//Manter como especificado
void TArvore_Insere_Raiz (TNo **ppRaiz , TItem x){
    
    if (*ppRaiz == NULL ) {
        *ppRaiz = TNo_Cria(x);
        return;
    }

    TArvore_Insere(*ppRaiz, x) ;

}

//Manter como especificado
int TArvore_Insere (TNo *pRaiz , TItem x){
    if ( pRaiz == NULL ) return -1; // arvore vazia

    if (x.chave < pRaiz->item.chave ) {
        if ( pRaiz->pEsq == NULL ) {
            pRaiz->pEsq = TNo_Cria (x);
            return 1;
        }
        return TArvore_Insere(pRaiz->pEsq , x);
    }

    if (x.chave > pRaiz->item.chave ) {
        
        if ( pRaiz-> pDir == NULL ) {
            pRaiz->pDir = TNo_Cria(x);
            return 1;
        }
        return TArvore_Insere(pRaiz->pDir, x);
    }

    return 0;
    
}

//Manter como especificado
TNo *TNo_Cria (TItem x){

    TNo *pAux = (TNo*) malloc(sizeof(TNo));
    pAux->item = x;
    pAux->pEsq = NULL ;
    pAux->pDir = NULL ;
    return pAux ;
} 

//Manter como especificado
void somatorio(TNo *p, int *soma){

    if (p == NULL ) return ;

    somatorio(p->pEsq,soma);
    somatorio(p->pDir,soma);
    *soma += p->item.chave;
}

int main ()
{
	int n, no;
	TArvore *arvore;
	TItem item_auxiliar;

	//ler n
	scanf("%d", &n);
	TArvore_Inicia(arvore);
	
	//ler o primeiro no e criar a raiz da arvore
	scanf("%d",&no);
	item_auxiliar.chave = no;
	TArvore_Insere_Raiz(&(*arvore),item_auxiliar);

	for(int i = 1; i < n; i++) {
		//ler o no
		scanf("%d",&no);
		//inserir na arvore
		item_auxiliar.chave = no;
		TArvore_Insere((*arvore),item_auxiliar);
	}
    int soma=0;
    somatorio(*arvore,&soma);
    printf("soma= %d\n", soma);

	return 0;
}