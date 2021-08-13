#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m, itens, resultado=0, max=0;
	TipoCaixa *heap = NULL;

	//ler n e m
	//n eh o nro de funcionarios
	//m eh o nro de clientes
	scanf("%d %d", &n, &m);
	
	//alocar o vetor para o heap com tamanho n
	heap = alocaVetor(heap,n);

	//ler o tempo de atendimento de cada caixa
	//a principio, cada caixa esta disponivel no tempo zero
	for (int i = 1; i <= n; i++){
		scanf("%d", &heap[i].tempo_vi);
		heap[i].tempo_atendimento = 0;
		heap[i].identificacao = i;
	}

	//criar a fila de prioridades
	Heap_Constroi(heap, n);

	printf("\nidentificacao:");

	for(int j=0; j<n;j++){
		printf("|%d",heap->identificacao);
	}

	printf("\natendimento:");
	for(int j=0; j<n;j++){
		printf("|%d",heap->tempo_atendimento);
	}
	

	while (m--) {

		//para cada cliente, ler a quantidade de produtos
		scanf("%d", &itens);
		
		//verificar qual caixa estara disponivel primeiro
		heap[0].tempo_atendimento += heap[0].tempo_vi * itens;

		//armazenar qual o tempo maximo para atender todos clientes ate agora
		if (max < heap[0].tempo_atendimento)	
			max = heap[0].tempo_atendimento;


		//alterar a disponibilidade do caixa selecionado
		Heap_Constroi(heap,n);
	}

	//desalocar o vetor do heap
	heap = desalocaVetor(heap);

	//imprimir a resposta
	for(int k=0; k<n; k++){
		resultado += heap[k].tempo_atendimento;
	}
	printf("%d\n", resultado);

	return 0;
}
