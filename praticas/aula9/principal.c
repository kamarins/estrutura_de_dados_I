#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m, itens, maximo=0;
	TipoCaixa *heap = NULL;

	//ler n e m
	//n eh o nro de funcionarios
	//m eh o nro de clientes
	scanf("%d %d", &n, &m);
	
	//alocar o vetor para o heap com tamanho n
	heap = alocaVetor(heap,n);

	//ler o tempo de atendimento de cada caixa
	//a principio, cada caixa esta disponivel no tempo zero
	for (int i = 0; i < n; i++){
		scanf("%d", &heap[i].tempo_vi);
		heap[i].tempo_atendimento = 0; //cada caixa disponivel no tempo 0
		heap[i].identificacao = i+1;
	}

	//criar a fila de prioridades
	Heap_Constroi(heap, n);
	
	while (m--) {

		//para cada cliente, ler a quantidade de produtos
		scanf("%d", &itens);
		
		//verificar qual caixa estara disponivel primeiro
		heap[0].tempo_atendimento += heap[0].tempo_vi * itens;

		//armazenar qual o tempo maximo para atender todos clientes ate agora
		if ( maximo < heap[0].tempo_atendimento )	
			maximo = heap[0].tempo_atendimento;

		//alterar a disponibilidade do caixa selecionado
		Heap_Constroi(heap,n);
	}

	//desalocar o vetor do heap
	heap = desalocaVetor(heap);

	//imprimir a resposta
	printf("%d\n",maximo);

	return 0;
}
