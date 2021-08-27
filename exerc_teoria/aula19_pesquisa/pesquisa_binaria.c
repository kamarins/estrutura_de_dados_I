typedef long TChave ;

typedef struct {
    TChave chave ;
/* outros componentes */
} TRegistro ;

typedef struct {
    TRegistro *v;
    int n , max ;
} TDicionario ;

/* inicializa um dicionario */
void TDicionario_Inicio(TDicionario *t ) {
    t->n = 0;
    t->max = 10;
    t->v = (TRegistro*) malloc (sizeof(TRegistro) * t->max);
}

//pesquisa binaria iterativa 
/* encontra o í ndice da chave x no dicion á rio */
int TDicionario_Find ( TDicionario *t , TChave c) {
    int i , esq , dir ;
    if (t->n == 0) return -1;

    esq = 0;
    dir = t->n -1;
    do {
        i = ( esq + dir ) / 2;
        if (c > t->v[i].chave ) esq = i + 1;
        else dir = i - 1;
    }
    while (c != t->v[i].chave && esq <= dir );

    if (c == t->v[i].chave ) return i;
    else return -1;
}