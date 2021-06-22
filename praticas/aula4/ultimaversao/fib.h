# ifndef fib_h
# define fib_h

typedef struct{
  int i;
  long int resultado;
  long int chamadas;
} TADfib;

void lerQuantidade(int *n);

void lerTeste(TADfib *f);
 
//funcao que executa o calculo de fibonacci 
long int fibonacci(int n, TADfib *f);

void printResultado (TADfib f);

# endif
