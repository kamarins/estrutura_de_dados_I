#include "arvore.h"
#include <stdio.h>

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

	//gerar percurso em ordem prefixa
	printf("PREFIXA:");
	Prefixa(*arvore);

	//gerar percurso em ordem infixa
	printf("\nINFIXA:");
	Infixa(*arvore);
	
	//gerar percurso em ordem posfixa
	printf("\nPOSFIXA:");
	Posfixa(*arvore);
	printf("\n");

	return 0;
}
