#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m;
	TipoCaixa *heap;

	//ler n e m
	scanf("%d %d", &n, &m);
	
	//alocar o vetor para o heap com tamanho n
	heap = alocaVetor(heap,n);

	//ler o tempo de atendimento de cada caixa
	for (int i=0; i<n; i++){
		scanf("%d", heap[i].tempo);
	}

	//criar a fila de prioridades
	Heap_Constroi(heap, n);

	//a principio, cada caixa esta disponivel no tempo zero

	while (m--) {
		//para cada cliente, ler a quantidade de produtos
		for (int j = 0; j < m; j++){
			scanf("%d",)
		}

		//verificar qual caixa estara disponivel primeiro
		//alterar a disponibilidade do caixa selecionado
		//armazenar qual o tempo maximo para atender todos clientes ate agora
	}

	//desalocar o vetor do heap
	//imprimir a resposta
	return 0;
}
