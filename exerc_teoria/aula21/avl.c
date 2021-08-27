#include <stdio.h>
#include <stdlib.h>

typedef long TChave ;

typedef struct {
    TChave chave ;
/* outros componentes */
} TReg ;

typedef struct TNo {
    TReg reg ;
    TNo *pEsq , *pDir ;
} TNo ;

typedef TNo *TDicionario ;

int FB(TNo* pRaiz ) {
    if ( pRaiz == NULL )
    return 0;

    return Altura(pRaiz->pEsq )- Altura(pRaiz->pDir );
}

int Altura(TNo* pRaiz ) {
    int iEsq , iDir ;

    if ( pRaiz == NULL )
    return 0;

    iEsq = Altura(pRaiz->pEsq );
    iDir = Altura(pRaiz->pDir );

    if ( iEsq > iDir )
        return iEsq + 1;
    else
        return iDir + 1;
}

void RSE(TNo **ppRaiz ) {
    TNo * pAux ;
    pAux = (*ppRaiz )->pDir ;
    (*ppRaiz )->pDir = pAux->pEsq ;
    pAux->pEsq = (* ppRaiz );
    (*ppRaiz ) = pAux ;
}

void RSD(TNo **ppRaiz ) {
    TNo *pAux ;
    pAux = (*ppRaiz )->pEsq ;
    (*ppRaiz )->pEsq = pAux->pDir ;
    pAux->pDir = (*ppRaiz );
    (*ppRaiz ) = pAux ;
}

int BalancaEsquerda ( TNo ** ppRaiz ) {
    int fbe = FB ( (*ppRaiz)->pEsq );
    if ( fbe > 0 ) {
        RSD(ppRaiz) ;
        return 1;
    } else if ( fbe < 0 ) {
        /* Rotacão Dupla Direita */
        RSE ( &((* ppRaiz ) -> pEsq ) );
        RSD (ppRaiz) ; /* &(* ppRaiz ) */
        return 1;
    }
    return 0;
}

int BalancaDireita ( TNo ** ppRaiz ) {
    int fbd = FB ( (* ppRaiz ) -> pDir );
    if ( fbd < 0 ) {
        RSE ( ppRaiz ); 
        return 1;
    } else if ( fbd > 0 ) {
        /* Rota ção Dupla Esquerda */
        RSD ( &((* ppRaiz ) -> pDir ) );
        RSE ( ppRaiz ) ; /* &(* ppRaiz ) */
        return 1;
    }
    return 0;
}

int Balanceamento ( TNo ** ppRaiz ) {
    int fb = FB (* ppRaiz );
    if ( fb > 1)
        return BalancaEsquerda ( ppRaiz ) ;
    else if ( fb < -1 )
        return BalancaDireita ( ppRaiz );
    else
        return 0;
}

int Insere (TNo∗∗ ppRaiz,Reg∗ x ) {
    if (∗ppRaiz == NULL) {
        ∗ppRaiz = (TNo∗) malloc(sizeof(TNo)) ;
        (∗ppRaiz)−>Reg = ∗x ;
        (∗ppRaiz)−>pEsq = NULL ;
        (∗ppRaiz)−>pDir = NULL ;
        return 1 ;
    } else if ( (∗ppRaiz)−>Reg.chave > x−>chave ) {
        if ( Insere(&(∗ppRaiz)−>pEsq , x ) ) {
            if ( Balanceamento(ppRaiz))
                return 0 ;
            else
                return 1 ;
        }
    } else  if ( (∗ppRaiz)−>Reg.chave < x−>chave ) {
        if ( Insere (&(∗ppRaiz)−>pDir, x ) ) {
            if (Balanceamento (ppRaiz ) )
                return 0 ;
            else
                return 1 ;
        } else
            return 0 ;
    } else
        return 0 ; 

int Remove ( TNo **ppRaiz , Reg *pX ) {
    if (*ppRaiz == NULL )
        return 0;
    else if ( (*ppRaiz )->Reg.chave = pX->chave ) {
        * pX = (*ppRaiz )->Reg ;
        Antecessor ( ppRaiz ,&((*ppRaiz )->pEsq ));
        Balanceamento ( ppRaiz );
        return 1;
    } else if ( (*ppRaiz )->Reg.chave > pX->chave ) {
        if ( Remove ((*ppRaiz )->pEsq, pX )) {
            Balanceamento (ppRaiz);
            return 1;
        } else
            return 0;
    } else {
        /* có digo para sub -á rvore direita */
    }
}