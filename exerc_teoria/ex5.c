
#include <stdio.h>
/*
void Procedimento1() {
    int n;
    printf("Digite um numero: \n");
    scanf("%i",&n);
    int i=0, a=0,cont;
   
    while (i<n){
         cont ++;
        a += i;
        i += 2;
    }
    printf("a = %i", a);
    printf("cont = %i\n", cont);
}

int main(){
    Procedimento1();

    return 0;
} */

void Procedimento2() {
    int n;
    printf("Digite um numero: \n");
    scanf("%i",&n);
    int i, j, a=0, cont=0;

   for (i=0; i<n; i++){
      
       for (j=0; j<i;j++){
           a += i + j ;
            cont ++;
       }
   }
    printf("cont = %i\n", cont);
    printf("a = %i\n", a);
}

int main(){
    Procedimento2();

    return 0;
} 