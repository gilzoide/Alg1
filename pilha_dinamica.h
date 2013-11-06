#include "fila_dinamica.h"	// existe uma fila dentro da pilha

#define MAXTAM 255

#ifndef ALGI_pilha_dinamica_h
#define ALGI_pilha_dinamica_h


typedef struct pilha_no {
	float lances;	// lance
	Fila preferencia;	// fila de usuarios que deram os lances
	
	struct pilha_no *prox;
} pilha_No;

typedef struct {
	pilha_No *topo;
} Pilha;



void PilhaCria (Pilha *P);
int PilhaEstaVazia (Pilha *P);
int PilhaEstaCheia (Pilha *P);
int PilhaPush (Pilha *P, float *valorLance);
int PilhaPop (Pilha *P, float *valorLance);
void PilhaDestroi (Pilha *P);

#endif
