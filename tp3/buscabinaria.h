# ifndef buscabinaria_h
# define buscabinaria_h

#define M 0.000001

double *alocaTiras(double *tiras, long int n);
double *desalocaTira(double *tiras);

void ordenar_vetor(double *v, int l, int r);
void merge(double *v, int l, int m, int r); 

double buscaBinaria(double *tiras, long int a, long int n);
double calculaArea(double *tiras, long int n);
int verifica(long int a, double *tiras, long int n);

# endif