#include "corretor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct submissao{
  char id;
  int tempo;
  char* julg;
};

struct pontuacao{
    int s;
    int p;
};

//ler a quantidade de submissoes do caso teste
void lerQuantidade(int *qtd){
    scanf("%i", qtd);
}

//aloca memoria para armazenar as submissoes e para a pontucao
TADsub* alocaSubmissoes(TADsub *S, int qtd){
  S = (TADsub*) malloc (qtd * sizeof(TADsub));
}

TADpont* alocaPontuacao(TADpont *P){
  P = (TADpont*) malloc (sizeof(TADsub));
}

//desaloca memoria para armazenada para as submissoes e para a pontuacao
TADpont* liberaPontuacao(TADpont *P){
  free(P);
}

TADsub* liberaSubmissoes(TADsub *S){
  free (S);
}

void lerSubmissoes(TADsub *S, int qtd){
    for (int i = 0; i<qtd; i++){
        scanf("%c" "%i" "%s", S[i].id, &S[i].tempo, S[i].julg);
    }
}
