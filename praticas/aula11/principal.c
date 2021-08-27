#include "hash.h"
#include <stdio.h>

int main(){
	int n,c;
	//criar variavel para tabela hash
	THash *hash;
	TItem item;

	//ler tamanho da tabela hash e a quantidade de chaves
	scanf("%d %d",&n,&c);

	//inicializar a tabela hash
	THash_Inicia(hash,n);

	//para cada chave da entrada, ler e inserir na tabela hash
	for(int i=0; i<c; i++){
		scanf("%d",&item.chave);
		THash_Insere(hash,item); 
	}

	
	//imprimir a tabela hash de acordo com a especificacao da saida
	for(int j=0; j<n; j++){
		printf("%d -> ", j);

		TCelula *Aux;
		Aux = hash->v[j].pPrimeiro->pProx;

		while(Aux != NULL) {
		
			printf("%d -> ", Aux->item.chave);
			Aux = Aux->pProx;

		}
		
		printf("\\\n");
	}

    return 0;
}
