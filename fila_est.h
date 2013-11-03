/* TAD da Fila Estatica Circular */


#define TAM 20	// tamanho estatico maximo da fila
#define SUCCESS 1	// retorno de funcoes: fez o que deveria fazer
#define ERRO -1	// retorno de funcoes: deu algum problema no caminho


typedef struct fila {
	char usuario[TAM][30];	// nome de quem deu o lance
	int lance[TAM];	// valor do lance
	
	int ini, fim;	// inicio e fim da fila, ini == -1 significa lista vazia
} Fila;


/* inicializa a fila com padroes determinados */
void FilaInicia (Fila *);

/* verifica se a fila esta vazia
 * uso:
 * 		if (FilaEstaVazia (&F))
 */
int FilaEstaVazia (Fila *);

/* insere usuario e lance na fila
 * 
 * ERRO: Overflow, fila cheia
 */
int FilaInsere (Fila *, int *, const char *);

/* remove primeiro da fila, retornando os valores por referencias
 * 
 * ERRO: Underflow, fila vazia 
 */
int FilaRetira (Fila *, int *, char *);

/* Imprime todos os elementos da fila, mantendo-a intacta */
void FilaPrint (Fila *);

/* Destroi uma fila (limpa-a) */
void FilaDestroi (Fila *);
