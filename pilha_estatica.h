#include "pilha_estatica.h"

#define MAXTAM 255

typedef struct {
	float lances[MAXTAM];	// vetor de lances
	Fila preferencia[MAXTAM];	// vetor da fila de usuarios que deram os lances
	
	int topo;
} Pilha;



void PilhaCria (Pilha *P);
int PilhaEstaVazia (Pilha *P);
int PilhaEstaCheia (Pilha *P);
int PilhaPush (Pilha *P, float *valorLance);
int PilhaPop (Pilha *P, float *valorLance);
void PilhaDestroi (Pilha *P);
