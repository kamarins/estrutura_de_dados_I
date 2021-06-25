# ifndef corretor_h
# define corretor_h

//estrutura submissao 
typedef struct submissao TADsub;
typedef struct pontuacao TADpont;

//funcao para ler a quantidade de submissoes do caso teste
void lerQuantidade(int *qtd);

//funcao para alocar memoria para armazenar as submissoes
TADsub* alocaSubmissoes(TADsub *S, int qtd);

//funcao para alocar memoria para armazenar para a pontuacao
TADpont* alocaPontuacao(TADpont *P);

//funcao para desalocar memoria armazenada para as submissoes 
TADsub* liberaSubmissoes(TADsub*S);

//funcao para desalocar memoria armazenada para as submissoes 
TADpont* liberaPontuacao(TADpont *P);

//funcao que le as submissoes do aluno 
void lerSubmissoes(TADsub *S, int qtd);

//funcao que calcula a pontuacao do aluno 
void calculaPontuacao(TADsub *S, int qtd, TADpont *P);

//funcao que calcula a quantidade de vezes que um caso correto, foi incompleto 
void quantidadeIncompletos(TADsub *S, TADpont *P, int qtd, int i);

//Print o resultado do aluno 
void printPontuacao(TADpont *P);

# endif
