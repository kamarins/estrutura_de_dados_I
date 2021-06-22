#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
  char nome[20];
  int idade;
  int escalado;
};

struct time { 
  char lider[20];
  char entregador[20];
  char piloto[20];
  int idadeLider;
  int idadeEntregador;
  int idadePiloto;
};

void lerQuantidade(int *qtd){
  scanf("%i", qtd);
}

//Manter como especificado
TADduende *alocaDuendes(TADduende *D, int qtd){
  D = (TADduende*) malloc (qtd * sizeof(TADduende));

  return D;
}

//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd){
  T = (TADtime*) malloc (qtd * sizeof(TADtime));

  return T;
}

//Manter como especificado
TADduende *desalocaDuendes(TADduende *D){
  free (D);
}

//Manter como especificado
TADtime *desalocaTimes(TADtime *T){
  free (T);
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;

  for (i=0; i<qtd; i++){
    scanf("%s %i",D[i].nome, &D[i].idade);
    D->escalado=0;
  }
  //ler nome e idade de cada duente
  //aproveitar para colocar o valor 0 no campo escalado
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i, indice;

  //completar o XXX
  for (i=0; i < qtd/3; i++){
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1 ;
    
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].lider, D[indice].nome);
    T[i].idadeLider = D[indice].idade;
    //copiar a idade
  }

  //repetir o laco acima, mas para o entregador
  for (i=0; i < qtd/3; i++){
    indice = proximoMaisVelho(D, qtd);

    //marcar o duende do indice como escalado
    D[indice].escalado = 1 ;
    
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].entregador, D[indice].nome);
    T[i].idadeEntregador = D[indice].idade;
    //copiar a idade
  }

  //repetir o laco acima, mara para o piloto
  for (i=0; i < qtd/3; i++){
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1 ;
    
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].piloto, D[indice].nome);
    T[i].idadePiloto = D[indice].idade;
    //copiar a idade
  }
}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice,aux=9;

  for (int i=0; i < qtd; i++){
    if (D[i].idade > aux && D[i].escalado == 0){
      aux = D[i].idade;
      indice = i;
    }
  }
  //determinar o indice do duende mais velho nao escalado ainda
  //variaveis adicionais podem ser criadas
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
  
  for (int i=0; i < qtd; i++){
    printf("Time %i \n", i+1);
    printf("%s %i\n", T[i].lider, T[i].idadeLider);
    printf("%s %i\n", T[i].entregador, T[i].idadeEntregador);
    printf("%s %i\n", T[i].piloto, T[i].idadePiloto);
    printf("\n");
  }

}
