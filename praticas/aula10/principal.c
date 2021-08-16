#include "arvore.h"
#include <stdio.h>

int main ()
{
	int n, no;
	TArvore* arvore;

	//ler n
	scanf("%d", &n);
	// printf("li\n");

	TArvore_Inicia(&arvore);
	//ler o primeiro no e criar a raiz da arvore
	scanf("%d",&no);
	arvore->item->chave = no;

	
	TArvore_Insere_Raiz(&arvore,arvore->item);

	for(int i = 1; i < n; i++) {
		//ler o no
		scanf("%d",&no);

		//inserir na arvore
		arvore->item.chave = no;
		TArvore_Insere(arvore,arvore->item);
	}

	//gerar percurso em ordem prefixa
	printf("PREFIXA:");
	Prefixa(arvore);

	//gerar percurso em ordem infixa
	printf("\nINFIXA:");
	Infixa(arvore);
	
	//gerar percurso em ordem posfixa
	printf("POSFIXA:");
	Posfixa(arvore);
	printf("\n");

	return 0;
}
