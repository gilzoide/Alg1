/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  ALG1 - Trabalho 1                                                          *
 *  lista_dinamica.c                                                           *
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
 *  Criado em 4 de Novembro de 2013                                            *
 *                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dinamica.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Criar Nova Lista
 *
 * Descricao: insere um elem x na posicao p da lista
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaCria(Lista* L) {
    
    L->cabeca = NULL;
    L->tamanho = 0;
    return 0;
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Esta Cheia?
 *
 * Descricao: verifica se a lista esta cheia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaEstaCheia(Lista* L) {
    
        // lista dinamica nunca estara cheia
        return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Esta Vazia?
 *
 * Descricao: verifica se a lista esta vazia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaEstaVazia(Lista* L) {
    
    if (L->cabeca == NULL || L->tamanho == 0)
        return 1;
    else
        return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Inserir na Posicao
 *
 * Descricao: insere um elem x na posicao p da lista
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaInsereNaPosicaoP(Lista* L, elem* x, int p) {
    
    int i; no** aux;
    
    // checa se a posicao eh valida
    if (p > L->tamanho || p < 0)
        return 2;
    
    // encontra a posicao
    for (i = 0, aux = &L->cabeca; i < p; i++, *aux = (*aux)->prox);
    
    // insere o novo elemento
    
    no* novo = (no*) malloc(sizeof(no));
    if (novo == NULL) return 2;
    
    PilhaCria (&novo->info.a_pilha);
    strcpy(novo->info.nome, x->nome);
    novo->prox = (*aux)->prox;
    *aux = novo;
    
    // atualiza o tamanho da lista
    L->tamanho++;
    
    return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Inserir Ordenado
 *
 * Descricao: insere um elem x mantendo a ordenacao da lista
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaInsereOrdenado(Lista* L, elem* x) {
    
    no** aux;
    
    // encontra a posicao
    for (aux = &L->cabeca; (*aux) != NULL; aux = &(*aux)->prox) {
        if (strcmp((*aux)->info.nome, x->nome) >= 0)
            break;
    }
    
    // insere o novo elemento
    no* novo = (no*) malloc(sizeof(no));
    if (novo == NULL) return 2;
    
    strcpy(novo->info.nome, x->nome);
    
    if (*aux != NULL || *aux != L->cabeca)
        novo->prox = (*aux);
    *aux = novo;
    
    // atualiza o tamanho da lista
    L->tamanho++;
    
    return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Busca Elemento da Lista
 *
 * Descricao: busca um elemento x e retorna um ponteiro para
 * o mesmo na lista usando o parametro p da funcao
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaBusca (Lista* L, elem* x, elem** p) {
    
    no** aux; *p = NULL;
    
    if (ListaEstaVazia(L))
        return -1;
    
    // encontra o elemento
    for (aux = &L->cabeca; (*aux) != NULL; *aux = (*aux)->prox) {
        if (strcmp((*aux)->info.nome, x->nome) == 0)
            break;
    }
    
    // checa se encontrou o elemento
    if ((*aux) != NULL && strcmp((*aux)->info.nome, x->nome) == 0) {
        
        *p = &(*aux)->info;
        return 0;
        
    }
    
    // nao encontrou
    else {
        return -2;
    }
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao insere na pilha dentro da Lista
 *
 * Descricao: busca um elemento x insere o valor na pilha
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaInserePilha (Lista* L, elem* x, float* valor) {
	
	elem *aux;
    
    if (ListaBusca (L, x, &aux) == 0) {
        // insere lance na pilha respectiva
        PilhaPush (&(aux)->a_pilha, valor);
        return 0;
	}
	else {
		return 1;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Insere na fila dentro da pilha dentro da Lista
 *
 * Descricao: busca um elemento x e insere o nome na fila
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaInsereFila (Lista* L, elem* x, char* usuario) {
	
    elem *aux;
    
    if (ListaBusca (L, x, &aux) == 0) {
		// insere nome na fila do lance respectivo
		FilaInsere (&(aux)->a_pilha.topo->preferencia, usuario);
        return 0;
    }
    else {
		return 1;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Apagar/Destruir/Queimar Elemento da Lista
 *
 * Descricao: retira um elemento da lista
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaRetira(Lista* L, elem* x) {
    
    no** aux;
    
    if (ListaEstaVazia(L))
        return 1;
    
    // encontra o elemento
    for (aux = &L->cabeca; (*aux) != NULL; *aux = (*aux)->prox) {
        if (strcmp((*aux)->info.nome, x->nome) == 0)
            break;
    }
    
    // checa se encontrou o elemento
    if ((*aux) != NULL && strcmp((*aux)->info.nome, x->nome) == 0) {
        
        no* tmp = (*aux);
        *aux = (*aux)->prox;
        free(tmp);
        return 0;
    }
    
    // nao encontrou
    else {
        return 2;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Imprimir Lista
 *
 * Descricao: Imprime todos os elementos da lista,
 * 			  inclusive o conteudo da pilha
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void ListaPrint (Lista* L, char ultimo) {
	no* aux;
	
	int i = 0;
	
	for (aux = L->cabeca; aux != NULL; aux = aux->prox) {
		printf ("Produto %d: %s\n", ++i, aux->info.nome);
		PilhaPrint (&aux->info.a_pilha);
		puts ("");
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Apagar/Destruir/Queimar Lista
 *
 * Descricao: destroi toda a lista, liberando a memoria
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void ListaDestroi (Lista *L) {
	no *ant, *aux;
	
	if (!ListaEstaVazia (L)) {
		ant = L->cabeca;
		aux = L->cabeca->prox;
		free (ant);
		while (aux != NULL) {
			ant = aux;
			aux = aux->prox;
			// libera a memoria do bloco assim como o da pilha la dentro
			PilhaDestroi (&ant->info.a_pilha);
			free (ant);
		}
	}
	
	L->tamanho = 0;
	L->cabeca = NULL;
}









