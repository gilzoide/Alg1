#include "pilha_estatica.h"

void PilhaCria (Pilha *P) {
	P->topo = -1;
	CriaFila(P->preferencia);
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
	}
	return 0;
}

void PilhaDestroi (Pilha *P) {
	P->topo = -1;
	FilaDestroi(P->preferencia);
}

void PilhaPrint (Pilha *P)
{
	float retorno = 0.0;
	Pilha aux;
	PilhaCria (&aux);
	FilaCria(aux->preferenia);
	if (PilhaEstaVazia(P))
		return ERRO;
	else {
		while (!PilhaEstaVazia(P)) {
			PilhaPop (P, &retorno);
			printf("\tR$%.2f\n", retorno);
			FilaPrint(P->lances);
			PilhaPush(&aux, &retorno);
		}
	}

	while (!PilhaEstaVazia(&aux)) {
			PilhaPop(aux, &retorno);
			PilhaPush(P, &retorno);
	}

	PilhaDestroi(&aux);
}

int PilhaCopia (Pilha *P1, Pilha *P2) {
    Pilha aux;
    float retorno = 0.0;
    CriaPilha(aux);
    FilaCria(aux->preferenia);
    if (PilhaEstaVazia(P2))
        return ERRO;
    else {
        while (!PilhaEstaVazia(P2)) {
            PilhaPop (P2, &retorno);
			PilhaPush(&aux, &retorno);
        }
    }
    
    while (!PilhaEstaVazia(&aux)) {
		  PilhaPop(aux, &retorno);
		  PilhaPush(P1, &retorno);
		  PilhaPush(P2, &retorno);
	}
	
    return 0;	   
}
