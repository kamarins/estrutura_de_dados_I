# ifndef corretor_h
# define corretor_h

//estrutura submissao 
typedef struct submissao TADsub;
typedef struct pontucao TADpont;

//ler a quantidade de submissoes do caso teste
void lerQuantidade(int *qtd);

//aloca memoria para armazenar as submissoes
TADsub* alocaSubmissoes(TADsub *S, int qtd);
TADpont* alocaPontuacao(TADpont *P);

//desaloca memoria para armazenada para as submissoes e a pontuacao
TADsub* liberaSubmissoes(TADsub*S);
TADpont* liberaPontuacao(TADpont *P);

//ler as submissoes do aluno
void lerSubmissoes(TADsub *S, int qtd);

//Print o resultado do aluno 
void printPontuação(int *V);

# endif