#include "fib.h"
#include<stdio.h>

int main()
{
    int n;
    
    //adicionar variaveis conforme necessidade
    TADfib f;

    lerQuantidade(&n);
    //fazer a leitura do numero de casos de teste
    //ler o caso de teste e processar antes de ler o proximo
    f.i=0;
    f.chamadas=-1;
    f.resultado=0;

    for (int j =0; j<n; j++){
        lerTeste(&f);
        f.resultado = fibonacci(f.i,&f);
        printResultado(f);
        f.i=0;
        f.chamadas=-1;
        f.resultado=0;
    }
    

    //imprimir a resposta no formato adequado
   
    return 0;//nao remova 
}
