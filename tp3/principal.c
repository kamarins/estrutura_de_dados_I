#include "buscabinaria.h"
#include <stdio.h>

int main(){
    int verificacao;
    long int n,a,*tiras = NULL;
    
    do{

        scanf("%ld %ld", &n, &a); //numero de tiras e a area esperada 
 
        tiras = alocaTiras(tiras,n);

        if(n == 0 && a == 0) break;

        for (int i=0; i<n; i++){
            scanf("%ld",&tiras[i]);
        }

        ordenar_vetor(tiras,0,n-1); //ordenacao do vetor para efetuar busca binaria

        verificacao = verifica(a,tiras,n);

        if(verificacao == 0 ){
            //caso impossivel
            printf("-.-\n");
        } else if(verificacao == 1){
            //nenhum corte necesario
            printf(":D\n");
        } else {
            printf("%.4lf\n",buscaBinaria(tiras,a,n));
        }

        tiras = desalocaTira(tiras);
    }while(n != 0 && a != 0);

    return 0;
}