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

#include "fila_estatica.h"

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


void FilaCria (Fila *F) {
	F->ini = -1;
	F->fim = -1;
}


int FilaEstaVazia (Fila *F) {
	return F->ini == -1;
}


int FilaEstaCheia (Fila *F) {
	return F->ini == Circular (F->fim + 1);
}


int FilaInsere (Fila *F, const char *nome) {
	// versao estatica, pode se ter estouro do vetor
	if (FilaEstaCheia (F))
		return ERRO;
		
	else {
		// avanca o fim, respeitando a circularidade
		F->fim = Circular (F->fim + 1);
		// entra com o nome no bloquinho
		strcpy (F->usuario[F->fim], nome);
		
		// se a lista estava vazia, inicio eh o mesmo do fim
		if (FilaEstaVazia (F))
			F->ini = F->fim;
		
		return 0;
	}
}


int FilaRetira (Fila *F, char *nome) {
	// se lista esta vazia, nao ha o que retirar
	if (FilaEstaVazia (F))
		return ERRO;
	
	else {
		// retira o nome do bloquinho
		strcpy (nome, F->usuario[F->ini]);
		// avanca o inicio, respeitandoa a circularidade
		F->ini = Circular (F->ini + 1);
		
		// esvaziou a fila
		if (F->ini == Circular (F->fim + 1))
			F->ini = -1;
		
		return 1;
	}
}


int FilaCopia (Fila *destiny, Fila *source) {
	if (FilaEstaVazia (source))
		return ERRO;
	
	else {
		FilaDestroi (destiny);
		
		Fila aux;
		FilaInicia (&aux);
		
		char nome[30];
				
		// copia para fila auxiliar
		while (!FilaEstaVazia (source)) {
			FilaRetira (source, nome);
			FilaInsere (&aux, nome);
		}
		// para podermos copiar para duas ao mesmo tempo
		while (!FilaEstaVazia (&aux)) {
			FilaRetira (&aux, nome);
			// copia para a outra
			FilaInsere (destiny, nome);
			// e recopia para a original
			FilaInsere (source, nome);
		}
		
		return 0;
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
		
		char nome[30];
		
		// copia de uma fila pra outra e escreve os resultados parciais
		while (!FilaEstaVazia (F)) {
			FilaRetira (F, nome);
			printf ("\t\t%s\n", nome);
			FilaInsere (&aux, nome);
		}
		// recopia para a fila original
		while (!FilaEstaVazia (&aux)) {
			FilaRetira (&aux, nome);
			FilaInsere (F, nome);
		}
		
		FilaDestroi (&aux);
	}
}


void FilaDestroi (Fila *F) {
	F->ini = -1;
	F->fim = -1;
}
