
#ifndef ALGI_pilha_estatica_h
#define ALGI_pilha_estatica_h

#include "fila_estatica.h"

#define MAXTAM 255

typedef struct {
	float lances[MAXTAM];        // vetor de lances
	Fila preferencia[MAXTAM];        // vetor da fila de usuarios que deram os lances
	
	int topo;
} Pilha;


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao PilhaPrint
 *
 * Descricao: imprime os elementos da pilha
 *
 * Parametros:
 *          Pilha *P: pilha contendo os elementos a serem impressos
 *
 * Retorno:
 *          void
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void PilhaPrint (Pilha *P);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao PilhaCria
 *
 * Descricao: cria uma pilha
 *
 * Parametros:
 *          Pilha *P: pilha a ser criada
 *
 * Retorno:
 *          void
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void PilhaCria (Pilha *P);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao PilhaEstaVazia
 *
 * Descricao: verifica se pilha esta vazia
 *
 * Parametros:
 *          Pilha: pilha a ser verificada
 *
 * Retorno:
 *          int:    0: nao esta cheia
 *                  1: esta cheia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int PilhaEstaVazia (Pilha *P);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao PilhaEstaCheia
 *
 * Descricao: verifica se a pilha esta cheia
 *
 * Parametros:
 *          Fila*: pilha a ser verificada
 *
 * Retorno:
 *          int:    0: nao esta cheia
 *                  1: esta cheia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int PilhaEstaCheia (Pilha *P);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao PilhaPush
 *
 * Descricao: insere um novo elemento na pilha
 *
 * Parametros:
 *          Pilha *P: pilha em que serah inserido um novo elemento
 * float *valorLance: ponteiro contendo o novo elementos da pilha
 *
 * Retorno:
 *          int:    0: caso nao tenha ocorrido erros na insercao
 *                  1: caso contrario
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int PilhaPush (Pilha *P, float *valorLance);

 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao PilhaPop
 *
 * Descricao: remove o elemento do topo da pilha
 *
 * Parametros:
 *          Pilha *P: pilha em que sera removido o topo
 * 			float *valorLance: ponteiro contendo o elemento removido
 *
 * Retorno:
 *          int:    0: caso nao tenha ocorrido erros na remocao
 *                  1: caso contrario
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int PilhaPop (Pilha *P, float *valorLance);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Espia Topo
 *
 * Descricao: espia o elemento do topo da pilha, sem retira-lo
 *
 * Parametros:
 *          Pilha *P: pilha em questao
 * 			float *valorLance: elemento a receber o valor do topo
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void PilhaEspiaTopo (Pilha *P, float *valorLance);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao PilhaDestroi
 * 
 * Descricao: detroi uma pilha
 *
 * Parametros:
 *	    Pilha *P: pilha a ser destruida
 *
 * Retorno:
 *            void
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void PilhaDestroi (Pilha *P);

int PilhaCopia (Pilha *P1, Pilha *P2);

#endif
