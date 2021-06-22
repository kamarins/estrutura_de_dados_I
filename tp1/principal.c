#include "corretor.h"
#include <stdio.h>


int main(){
    int qtd;
    TADpont *P;
    TADsub *S;

    lerQuantidade(&qtd);

    S = alocaSubmissoes(S, qtd);
    P = alocaPontuacao(P);

    lerSubmissoes(S,qtd);
    calculaPontuacao(S,qtd,P);
    printPontuacao(P);

    S = liberaSubmissoes(S);
    P = liberaPontuacao(P);

    return 0; 
}