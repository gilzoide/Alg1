#include "pilha_dinamica.h"

#include <stdlib.h>


void PilhaCria (Pilha *P) {
	P->topo = NULL;
}


int PilhaEstaVazia (Pilha *P) {
    if (P->topo == NULL)
        return 1;
    else
		return 0;
}


int PilhaEstaCheia (Pilha *P) {
    return 0;	// dinamica: nunca estara cheia
}


int PilhaPush (Pilha *P, float *valorLance) {
    pilha_No *aux;
    if ((aux = (pilha_No*) malloc (sizeof (pilha_No))) == NULL) {
		return ERRO;
	}
	
	// 'recheia' o bloco
	aux->lances  = *valorLance;

	aux->prox = P->topo;
	P->topo = aux;
	
	return 1;
}


int PilhaPop (Pilha *P, float *valorLance) {
    if (PilhaEstaVazia (P))
		return ERRO;
	
	else {
		pilha_No *aux = P->topo;
		
		*valorLance = aux->lances;
		P->topo = P->topo->prox;
		free (aux);
		
		return 1;
	}
}


void PilhaDestroi (Pilha *P) {
	float aux;
	
	while (!PilhaEstaVazia (P)) {
		PilhaPop (P, &aux);
	}
}
