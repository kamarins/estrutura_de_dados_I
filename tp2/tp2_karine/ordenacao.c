//Karine Isabelle Marins - 20.1.4057

#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao que aloca o vetor de paises
TPais *alocaPaises(TPais* paises, int n){

  paises = (TPais*) malloc (sizeof(TPais) * n);

  if(paises == NULL){
    exit(1);
  }

  return paises;
}

//funcao que desaloca o vetor de paises 
TPais *desalocaPaises(TPais *paises){

  free(paises);
  paises = NULL;
  
  return paises;
}

//funcao que le a informacao de cada pais 
void lerPaises(TPais *paises, int n){
    for (int i = 0; i<n ; i++){
        scanf("%s %d %d %d", paises[i].nome, &paises[i].ouro, &paises[i].prata, &paises[i].bronze);
    }
    
}

//funcao que efetua a troca dos paises 
void troca(TPais *paises, int j, int k){
    TPais armazenaPais;

    armazenaPais = paises[k];
    paises[k] = paises[j];
    paises[j] = armazenaPais;
}

//funcao que ordena os paises 
void ordena(TPais *paises, int n){
  
    for (int i = 0; i < n; i++){

        for (int j = 1; j < n - i; j++){

            if (paises[j].ouro > paises[j-1].ouro) //situacao por medalhas de ouro
                troca(paises,j,j-1);
            
            else if (paises[j].ouro == paises[j-1].ouro){ //situacao de empate de medalhas de ouro 
                
                if (paises[j].prata > paises[j-1].prata){
                    troca(paises,j,j-1);
                
                }else if (paises[j].prata == paises[j-1].prata){

                    if (paises[j].bronze > paises[j-1].bronze)
                        troca(paises,j,j-1);
                    
                    else if ((paises[j].bronze == paises[j-1].bronze))
                        ordenaAlfabeticamente(paises,j,j-1);
        
                }
            }          
        
        }   

    } 
}

//funcao que ordena os paises em ordem alfabetica
void ordenaAlfabeticamente(TPais *paises, int j, int k){
    
    if (strcmp(paises[j].nome,paises[k].nome) < 0)
        troca(paises,k,j);
    
}

//funcao que imprime o resultado
void print(TPais *paises, int n){
    for (int i =0 ; i< n; i++){
        printf("%s %d %d %d\n",paises[i].nome, paises[i].ouro, paises[i].prata, paises[i].bronze);
    }
}