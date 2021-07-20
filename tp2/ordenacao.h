//Karine Isabelle Marins - 20.1.4057

# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
    char nome[50];
	int ouro;
    int prata;
    int bronze;
} TPais;


//funcao que aloca o vetor de paises
TPais *alocaPaises(TPais* paises, int n);

//funcao que desaloca o vetor de paises
TPais *desalocaPaises(TPais *paises);

//funcao que le a informacao de cada pais 
void lerPaises(TPais *paises, int n);

//funcao que ordena os paises 
void ordena(TPais *paises, int n);

//funcao que ordena os paises em ordem alfabetica
void ordenaAlfabeticamente(TPais *paises, int j, int k);

//funcao que troca a posicao dos paises 
void troca(TPais *paises, int j, int k);

//funcao que imprime o resultado
void print(TPais *paises, int n);
# endif
