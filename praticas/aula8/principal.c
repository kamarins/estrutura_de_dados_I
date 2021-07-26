#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	int *vetor = NULL;
	int i, n, movimentos;
	while(scanf("%d", &n), n)
	{
		//alocar o vetor
		vetor = alocaVetor(vetor, n);
		movimentos = 0;
		//preencher o vetor
		for (i=0; i<n; i++){
			scanf("%d",&vetor[i]);
		}

		//ordenar o vetor e determinar o número de movimentos
		//troca entre elementos consecutivos 
	 	ordenacao(vetor,n ,&movimentos);

		//imprimir o resultado
		if (movimentos % 2 == 0 ){
			printf("Carlos\n");
		}else{
			printf("Marcelo\n");
		} 
		
		//desalocar o vetor
		vetor = desalocaVetor(vetor);
		
	}

	return 0;
}



