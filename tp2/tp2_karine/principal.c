//Karine Isabelle Marins - 20.1.4057
#include "ordenacao.h"
#include <stdio.h>

//a ordem e dada pelo numero de medalalhas de ouro
//se ha empate em medalhas de ouro, quem tiver mais medalas de prata fica a frente 
//se ha empate entre ouro e prata, fica na frente quem tiver mais medalhas de bronze
//se dois ou mais paises empatarem nos tres tipos de medalhas, ordena os paises em ordem alfabetica

int main ()
{
    TPais *paises = NULL;
	int n;

	//ler as quantidades
	scanf("%d", &n);

	//alocar o vetor
	paises = alocaPaises(paises,n);

	//preencher o vetor
	lerPaises(paises,n);

	//ordenar
	ordena(paises,n);

    //imprimir o resultado
    print(paises,n);
	
	//desalocar o vetor
	paises = desalocaPaises(paises);

  	return 0;
}
