#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main()
{
  Pilha pilha;
  char ch,aux1,aux2;
  Item item;
  int cont1=0, cont2=0;

  aux1 = '(';
  aux2 = ')';

  Pilha_Inicia(&pilha);

  while (scanf("%c", &ch)!= EOF)
  {
    if(ch == aux1){
      cont1++;
    }

    if(ch == aux2){
      cont2++;
    }

    item.expressao = ch;
    Pilha_Push(&pilha,item);
  }

//determinar o resultado

  if (cont1 == cont2){
    printf("correto\n");
  } else{
    printf("incorreto\n");  
  }

  Pilha_Esvazia(&pilha);

  return 0;//nao remova
}
