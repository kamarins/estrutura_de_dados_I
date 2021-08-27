# ifndef buscabinaria_h
# define buscabinaria_h

#define decimais 0.000001

long int *alocaTiras(long int *tiras, long int n);
long int *desalocaTira(long int *tiras);

void ordenar_vetor(long int *v, int l, int r);
void merge(long int *v, int l, int m, int r); 

double buscaBinaria(long int *tiras, long int a, long int n);
long int calculaArea(long int *tiras, long int n);
int verifica(long int a, long int *tiras, long int n);

# endif