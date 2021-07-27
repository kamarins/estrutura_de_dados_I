# define INICIO 0
# define MAXTAM 1000

//isso é com vetor

typedef struct {
    int chave ; /* outros campos */
} TItem ;

 typedef struct {
    TItem item [ MAXTAM ];
    int primeiro , ultimo ;
} TLista ;