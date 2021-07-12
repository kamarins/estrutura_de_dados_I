#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
  Pilha pilha;
  char ch;
  Item item;

  Pilha_Inicia(&pilha);

  while (scanf("%c", &ch)!= EOF)
  {
    if ( ch == '(' ){
      item.parenteses = ch;
      Pilha_Push(&pilha,item);
    } 
    else if( ch == ')'){
      int aux = Pilha_Pop(&pilha,&item);
      if(aux == 0){
        Pilha_Push(&pilha,item);
        break;
      }
    }
  }

  //determinar o resultado
  if(Pilha_EhVazia(&pilha)){
    printf("correto\n");
  } else{
    printf("incorreto\n");
  }

  Pilha_Esvazia(&pilha);

  return 0;//nao remova
}