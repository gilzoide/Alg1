/* TAD da Fila Dinamica */


#define ERRO -1	// retorno de funcoes: deu algum problema no caminho


typedef struct no {
	char usuario[30];	// nome de quem deu o lance
	int lance;	// valor do lance

	struct no* prox;
} No;


typedef struct fila {
	No *ini, *fim;	// inicio e fim da fila
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
 * ERRO: erro na alocacao de memoria
 */
int FilaInsere (Fila *, int *, const char *);

/* remove primeiro da fila, retornando os valores por referencias
 * 
 * ERRO: Underflow, fila vazia 
 */
int FilaRetira (Fila *, int *, char *);

/* Imprime todos os elementos da fila, mantendo-a intacta */
void FilaPrint (Fila *);

/* Destroi uma fila (limpa-a) 
 * 
 * sempre lembre-se de destruir toda e qualquer fila criada
 */
void FilaDestroi (Fila *);
