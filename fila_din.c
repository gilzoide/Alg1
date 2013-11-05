/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  ALG1 - Trabalho 1                                                          *
 *  lista_estatica.h                                                           *
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
 

/* TAD da Fila Dinamica */


#include "fila_din.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void FilaCria (Fila *F) {
	F->ini = NULL;
	F->fim = NULL;
}


int FilaEstaVazia (Fila *F) {
	return F->ini == NULL;
}


int FilaEstaCheia (Fila *F) {
	return 0;
}


int FilaInsere (Fila *F, const char *nome) {
	No *aux;
	
	// cria o novo bloco de informacao da fila
	if ((aux = (No*) malloc (sizeof (No))) == NULL)
		return ERRO;
	
	
	// entra com o nome no bloquinho
	strcpy (aux->usuario, nome);
	aux->prox = NULL;
	
	// se a lista estava vazia, inicio eh o novo No
	if (FilaEstaVazia (F))
		F->ini = aux;
	// senao encadeia ele atras do ultimo
	else
		F->fim->prox = aux;
	
	// de qualquer modo aux agora eh o ultimo No
	F->fim = aux;
	
	return 1;
}


int FilaRetira (Fila *F, char *nome) {
	// se lista esta vazia, nao ha o que retirar
	if (FilaEstaVazia (F))
		return ERRO;
	
	else {
		No *aux = F->ini;	// No a ser retirado eh o primeiro
		F->ini = F->ini->prox;	// primeiro No agora eh o antigo segundo
		
		// retira o nome do No
		strcpy (nome, aux->usuario);
		
		// apaga No
		free (aux);
		
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
			FilaRetira (F, nome);
			printf ("%s\n", nome);
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
	No *aux;
	
	while (!FilaEstaVazia (F)) {
		aux = F->ini;
		F->ini = F->ini->prox;
		free (aux);
	}
}
