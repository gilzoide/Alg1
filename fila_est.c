/* TAD da Fila Estatica Circular */

#include "fila_est.h"

#include <string.h>
#include <stdio.h>


/* Funcao auxiliar para facilitar a circularidade da fila (inclusive nao consta no .h)
 * 
 * 'x' eh levado ao comeco caso tenha passado do final
 * 
 * retorno pode ser usado tanto para comparacoes quanto para atribuicao
 */
int Circular (int x) {
	return x % TAM;
}


void FilaInicia (Fila *F) {
	F->ini = -1;
	F->fim = -1;
}


int FilaEstaVazia (Fila *F) {
	return F->ini == -1;
}


int FilaEstaCheia (Fila *F) {
	return F->ini == Circular (F->fim + 1);
}


int FilaInsere (Fila *F, int *valor, const char *nome) {
	// versao estatica, pode se ter estouro do vetor
	if (FilaEstaCheia (F))
		return ERRO;
		
	else {
		// avanca o fim, respeitando a circularidade
		F->fim = Circular (F->fim + 1);
		// entra com os valores no bloquinho
		F->lance[F->fim] = *valor;
		strcpy (F->usuario[F->fim], nome);
		
		// se a lista estava vazia, inicio eh o mesmo do fim
		if (FilaEstaVazia (F))
			F->ini = F->fim;
		
		return 1;
	}
}


int FilaRetira (Fila *F, int *valor, char *nome) {
	// se lista esta vazia, nao ha o que retirar
	if (FilaEstaVazia (F))
		return ERRO;
	
	else {
		// retira os valores do bloquinho
		*valor = F->lance[F->ini];
		strcpy (nome, F->usuario[F->ini]);
		// avanca o inicio, respeitandoa a circularidade
		F->ini = Circular (F->ini + 1);
		
		// esvaziou a fila
		if (F->ini == Circular (F->fim + 1))
			F->ini = -1;
		
		return 1;
	}
}


void FilaPrint (Fila *F) {
	if (FilaEstaVazia (F)) {
		puts ("Fila Vazia");
		return;
	}

	else {
		Fila aux;
		FilaInicia (&aux);
		
		int x;
		char nome[30];
		
		// copia de uma fila pra outra e escreve os resultados parciais
		while (!FilaEstaVazia (F)) {
			FilaRetira (F, &x, nome);
			printf ("%s: %d\n", nome, x);
			FilaInsere (&aux, &x, nome);
		}
		// recopia para a fila original
		while (!FilaEstaVazia (&aux)) {
			FilaRetira (&aux, &x, nome);
			FilaInsere (F, &x, nome);
		}
		
		FilaDestroi (&aux);
	}
}


void FilaDestroi (Fila *F) {
	F->ini = -1;
	F->fim = -1;
}
