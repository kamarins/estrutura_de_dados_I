#include "corretor.h"
#include <stdio.h>


int main(){
    int qtd;
    int *V;
    TADsub *S;

    lerQuantidade(&qtd);
    S = alocaSubmissoes(S, qtd);
    lerSubmissoes(S,qtd);
    printPontuação(V);

    S = desalocaSubmissoes(S);

    return 0; 
}