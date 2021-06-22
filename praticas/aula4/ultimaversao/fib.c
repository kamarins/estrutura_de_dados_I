#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

void lerQuantidade(int *n){
  scanf("%d", n);
  getchar();
  
}

void lerTeste(TADfib *f){
    scanf("%d", &f->i);
}

long int fibonacci(int n, TADfib *f){
//preencher o algoritmo recursivo

    //long long retorno;
    if ( n == 0)
    {   
        f->chamadas++;
        return 0;

    } else if (n == 1){

        f->chamadas++;
        return 1;

    } else{

        f->chamadas ++;
        return (fibonacci(n - 1 , f) + fibonacci(n-2, f));
    }

} 

void printResultado(TADfib f){
    printf("fib(%d) = %ld chamadas = %ld\n", f.i, f.chamadas, f.resultado);
}

