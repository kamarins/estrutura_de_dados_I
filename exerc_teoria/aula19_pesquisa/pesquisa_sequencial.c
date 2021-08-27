typedef long TChave ;

typedef struct {
    TChave chave ;
 /* outros componentes */
} TRegistro;

typedef struct {
    TRegistro *v;
    int n , max ;
} TDicionario;




/* inicializa um dicionario */
void TDicionario_Inicio(TDicionario *t ) {
    t->n = 0; t -> max = 10;
    t->v = ( TRegistro*) malloc(sizeof(TRegistro)*t->max);
}

/* encontra e retorna o í ndice da chave x no dicion á rio */
int TDicionario_Find(TDicionario *t , TChave c) {
    int i;
    for (i = t->n - 1; i >= 0; i--)
        if (t ->v[i ]. chave == c)
            return i;
    // retorna -1 caso a chave não seja encontrada
    return -1;
}

/* insere um registro no dicionario */
void TDicionario_Insere ( TDicionario *t , TRegistro *x) {
    if (t ->n == t -> max ) {
        t-> max *= 2;
        t->v = ( TRegistro*)realloc(t->v , sizeof(TRegistro) * t->max );
    }

    // n é o tamanho
   //da erro aq t->v[t->n++] = x ;
}