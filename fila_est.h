/* TAD da Fila Estatica Circular */

#include <string.h>

#define TAM 20
#define SUCCESS 1
#define ERRO -1

typedef struct fila Fila;


// inicializa a fila com padroes determinados
void FilaInicia (Fila *F);
// verifica se a fila esta vazia
int FilaEstaVazia (Fila *F);
// insere usuario e lance na fila
int FilaInsere (Fila *F, int *valor, char *nome);
// remove primeiro da fila, retornando os valores por referencias
int FilaRetira (Fila *F, int *valor, char *nome);

