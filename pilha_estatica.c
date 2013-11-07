#include "pilha_estatica.h"

#include <stdio.h>


void PilhaCria (Pilha *P) {
	P->topo = -1;
	return;        
}


int PilhaEstaVazia (Pilha *P) {
	if (P->topo == -1)
		return 1;
	else
		return 0;
}


int PilhaEstaCheia (Pilha *P) {
	if (P->topo == MAXTAM)
		return 1;
	else
		return 0;
}


int PilhaPush (Pilha *P, float *valorLance) {
	if (PilhaEstaCheia(P))
		return ERRO;
	else {
		P->topo++;
		P->lances[P->topo] = *valorLance;
		FilaCria(P->preferencia);
	}

	return 0;
}


int PilhaPop (Pilha *P, float *valorLance) {
	if (PilhaEstaVazia(P))
		return ERRO;
		
	else {
		P->lances[P->topo] = *valorLance;
		P->topo--;
		return 0;
	}
}


void PilhaEspiaTopo (Pilha *P, float *valorLance) {
	if (PilhaEstaVazia (P))
		*valorLance = 0;
	else
		*valorLance = P->lances[P->topo];
}


void PilhaDestroi (Pilha *P) {
	P->topo = -1;
}


void PilhaPrint (Pilha *P)
{
	if (PilhaEstaVazia(P)) {
		puts ("\tNao ha lances");
		return ;
	}
		
	float retorno;
	Pilha aux;
	PilhaCria (&aux);
		
	while (!PilhaEstaVazia(P)) {
		// so espia topo para ainda nao perdermos a fila
		PilhaEspiaTopo (P, &retorno);
		printf ("\tR$%.2f\n", retorno);
		FilaPrint(&P->preferencia[P->topo]);
		// copia da P pra pilha auxiliar
		PilhaPop (P, &retorno);
		PilhaPush(&aux, &retorno);
	}

	while (!PilhaEstaVazia(&aux)) {
		PilhaPop (&aux, &retorno);
		PilhaPush (P, &retorno);
	}

	PilhaDestroi(&aux);

}


int PilhaCopia (Pilha *P1, Pilha *P2) {
    if (PilhaEstaVazia(P2))
        return ERRO;
        
	float retorno;
    Pilha aux;
    PilhaCria (&aux);
        
	while (!PilhaEstaVazia(P2)) {
		PilhaPop (P2, &retorno);
		PilhaPush(&aux, &retorno);
	}

	while (!PilhaEstaVazia(&aux)) {
		  PilhaPop(&aux, &retorno);
		  PilhaPush(P1, &retorno);
		  PilhaPush(P2, &retorno);
	}
	
	PilhaDestroi (&aux);
	
	return 0;
}
