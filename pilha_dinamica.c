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
    return 0;        // dinamica: nunca estara cheia
}


int PilhaPush (Pilha *P, float *valorLance) {
    pilha_No *aux;
    
    if ((aux = (pilha_No*) malloc (sizeof (pilha_No))) == NULL) {
		return ERRO;
	}
    
    else {
        // 'recheia' o bloco
        aux->lances  = *valorLance;

        aux->prox = P->topo;
        P->topo = aux;
        
        return 1;
	}
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


void PilhaEspiaTopo (Pilha *P, float *valorLance) {
	*valorLance = P->topo->lances;
}


void PilhaDestroi (Pilha *P) {
	float aux;
	
	while (!PilhaEstaVazia (P)) {
		FilaDestroi (&P->topo->preferencia);
		PilhaPop (P, &aux);
	}
}


void PilhaPrint (Pilha *P) {
	
	if (PilhaEstaVazia(P))
		return ERRO;
		
    Pilha aux;
    float retorno;
    
    PilhaCria(&aux);
    
    while (!PilhaEstaVazia(P)) {
        // so espia topo para ainda nao perdermos a fila
		PilhaEspiaTopo (P, &retorno);
		printf("\tR$%.2f\n", retorno);
		FilaPrint(&P->topo->preferencia);
		// copia da P pra pilha auxiliar
		PilhaPop (P, &retorno);
		PilhaPush(&aux, &retorno);
    }
    
    while (!PilhaEstaVazia(&aux)) {
		PilhaPop(aux, &retorno);
		PilhaPush(P, &retorno);
	}

	PilhaDestroi(&aux);      
}


int PilhaCopia (Pilha *P1, Pilha *P2) {
    if (PilhaEstaVazia(P2))
        return ERRO;
    
    float retorno;
    Pilha aux;
    PilhaCria (&aux);
    Fila f_aux;
    FilaCria (&f_aux);
    
    while (!PilhaEstaVazia(P2)) {
		FilaCopia (&f_aux, P2->topo->preferencia);
        PilhaPop (P2, &retorno);
        PilhaPush(&aux, &retorno);
        FilaCopia (&aux, &f_aux);
    }
    
    while (!PilhaEstaVazia(&aux)) {
		FilaCopia (&f_aux, aux->topo->preferencia);
        PilhaPop(aux, &retorno);
        PilhaPush(P1, &retorno);
        FilaCopia (&aux, P1);
        PilhaPush(P2, &retorno);
        FilaCopia (&aux, P2);
    }
    
    PilhaDestroi (&aux);
    FilaDestroi (&f_aux);
    
    return 0;
}
