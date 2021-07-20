#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){

  alunos = (TipoAluno*) malloc (sizeof(TipoAluno) * n);

  if(alunos == NULL){
    exit(1);
  }

  return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){

  free(alunos);
  alunos = NULL;
  
  return alunos;
}

//ordena em ordem alfabetica
void ordena(TipoAluno *alunos, int n){
  int aux;//aux;
  char armazena[20];

  for (int i = 0; i < n; i++){
  
    aux = i;
  
    for (int j = i+1; j < n; j++){
      if (strcmp(alunos[j].nome,alunos[aux].nome) < 0){
        aux = j;
      }
    }

    strcpy(armazena,alunos[aux].nome);
    strcpy(alunos[aux].nome,alunos[i].nome);
    strcpy(alunos[i].nome, armazena);
  
  }
}


