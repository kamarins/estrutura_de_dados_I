#include "corretor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para os dados da submissao
struct submissao{
  char id;
  int tempo;
  char julg[20];
};

//struct para a pontuação, 
//s = quantidade de casos corretos 
//p = soma dos tempos 
struct pontuacao{
  int s;
  int p;
};

//funcao para ler a quantidade de submissoes do caso teste
void lerQuantidade(int *qtd){
    scanf("%d", qtd);
}

//funcao para alocar memoria para armazenar as submissoes
TADsub* alocaSubmissoes(TADsub *S, int qtd){
  S = (TADsub*) malloc (qtd * sizeof(TADsub));

  if (S == NULL){      
    exit(1);
  }

  return S;
}


//funcao para alocar memoria para a pontuacao
TADpont* alocaPontuacao(TADpont *P){
  P = (TADpont*) malloc (sizeof(TADpont));

  if (P == NULL){      
    exit(1);
  }

  P->p = 0;
  P->s = 0; 

  return P;
}

//funcao para desalocar memoria armazenada para a pontuacao
TADsub* liberaSubmissoes(TADsub *S){
  free(S);

  return NULL;
}

//funcao para desalocar memoria armazenada para as submissoes 
TADpont* liberaPontuacao(TADpont *P){
  free(P);

  return NULL;
}



//funcao que le as submissoes 
void lerSubmissoes(TADsub *S, int qtd){
  int i;
  for (i = 0; i < qtd; i++){
      scanf(" %c ", &S[i].id);
      scanf(" %d ", &S[i].tempo);
      scanf(" %s ", S[i].julg); 
  }
}

//funcao que calcula a pontuacao do aluno 
void calculaPontuacao(TADsub *S, int qtd, TADpont *P){
  
  for (int i = 0; i < qtd ; i++){
    
    if (strcmp(S[i].julg,"correto") == 0){ 
      P->p += S[i].tempo;
      P->s ++;
      quantidadeIncompletos(S,P,qtd,i);

    }
  }
}

//funcao que calcula a quantidade de vezes que um caso correto, foi incompleto 
void quantidadeIncompletos(TADsub *S, TADpont *P, int qtd, int i){

  for (int k=0; k<qtd; k++){
    if ((S[i].id == S[k].id) &&  strcmp(S[k].julg,"incompleto") == 0) {
      P->p += 20;
    } 
  }  
}

//Print o resultado do aluno 
void printPontuacao(TADpont *P){
  printf("%d %d\n", P->s, P->p);
}
