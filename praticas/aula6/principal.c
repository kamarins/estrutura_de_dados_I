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
    item.parenteses = ch;

    if ( ch == '(' ){
      //empilha os parenteses que abrem
      Pilha_Push(&pilha,item);
    } 
    else if( ch == ')'){
      if(Pilha_Pop(&pilha,&item) == 0){ //se a pilha for vazia
       //adiciona o parenteses nela
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
