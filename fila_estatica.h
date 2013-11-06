/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  ALG1 - Trabalho 1                                                          *
 *                                                                             *
 *  Alex Frederico Ramos Barboza    Nº7986480                                  *
 *  alex.barbosa@usp.br                                                        *
 *                                                                             *
 *  Gil Barboza Reis                Nº8532248                                  *
 *  gil.reis@usp.br                                                            *
 *                                                                             *
 *  Leonardo Sampaio Ferraz Ribeiro Nº8532300                                  *
 *  leonardo.sampaio.ribeiro@usp.br                                            *
 *                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* TAD da Fila Estatica Circular */

#ifndef ALGI_fila_estatica_h
#define ALGI_fila_estatica_h


#define TAM 20	// tamanho estatico maximo da fila
#define ERRO -1	// retorno de funcoes: deu algum problema no caminho


typedef struct fila {
	char usuario[TAM][30];	// nome de quem deu o lance
	
	int ini, fim;	// inicio e fim da fila, ini == -1 significa lista vazia
} Fila;


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Criar Nova Fila
 *
 * Descricao: Inicializa a fila com padroes de fila vazia
 *
 * Parametros:
 *          Fila*: fila que sera criada
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void FilaCria (Fila *);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Esta Vazia?
 *
 * Descricao: verifica se a fila esta vazia
 *
 * Parametros:
 *          Fila*: fila a ser verificada
 *
 * Retorno:
 *          int:    0: nao esta vazia
 *                  1: esta vazia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int FilaEstaVazia (Fila *);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Esta Cheia?
 *
 * Descricao: verifica se a lista esta cheia
 *
 * Parametros:
 *          Fila*: fila a ser verificada
 *
 * Retorno:
 *          int:    0: nao esta cheia
 *                  1: esta cheia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int FilaEstaCheia (Fila *);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Inserir
 *
 * Descricao: insere um lance na fila
 *
 * Parametros:
 *          Fila*: fila onde sera inserido o lance
 *          int*: valor do lance
 * 			const char*: nome do usuario que esta dando o lance
 *
 * Retorno:
 *          int:    0: sucesso
 *                  ERRO: overflow, fila cheia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int FilaInsere (Fila *, const char *);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Remover
 *
 * Descricao: retira o primeiro da fila e retorna-o pelos
 * 			  parametros passados por referencia
 *
 * Parametros:
 *          Fila*: fila a ter o lance retirado
 *          int*: variavel a ser guardado o valor do lance 
 *          char*: variavel a ser guardado o nome do usuario
 *
 * Retorno:
 *          int:    0: sucesso
 *                  ERRO: underflow, fila vazia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int FilaRetira (Fila *, char *);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Imprimir
 *
 * Descricao: imprime todos os elementos da fila, deixando-a intacta;
 * 			  no caso de fila vazia, imprime na tela: "Fila vazia"
 *
 * Parametros:
 *          Fila*: fila a ter seus elementos impressos
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void FilaPrint (Fila *);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Destruir
 *
 * Descricao: destroi a fila, restaurando padroes de fila vazia
 *
 * Parametros:
 *          Fila*: fila a ser destruida
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void FilaDestroi (Fila *);

#endif
