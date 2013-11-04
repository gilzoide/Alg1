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
    
    strcpy(novo->info, x);
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
    for (aux = &L->cabeca; (*aux) != NULL; *aux = (*aux)->prox) {
        if (strcmp((*aux)->info, x) >= 0)
            break;
    }
    
    // insere o novo elemento
    no* novo = (no*) malloc(sizeof(no));
    if (novo == NULL) return 2;
    
    strcpy(novo->info, x);
    novo->prox = (*aux)->prox;
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
 * o mesmo na lista usando o parametro p da fucao
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaBusca(Lista* L, elem* x, elem** p) {
    
    no** aux; *p = NULL;
    
    if (ListaEstaVazia(L))
        return 1;
    
    // encontra o elemento
    for (aux = &L->cabeca; (*aux) != NULL; *aux = (*aux)->prox) {
        if (strcmp((*aux)->info, x) == 0)
            break;
    }
    
    // checa se encontrou o elemento
    if ((*aux) != NULL && strcmp((*aux)->info, x) == 0) {
        
        *p = (*aux)->info;
        return 0;
        
    }
    
    // nao encontrou
    else {
        return 2;
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
        if (strcmp((*aux)->info, x) == 0)
            break;
    }
    
    // checa se encontrou o elemento
    if ((*aux) != NULL && strcmp((*aux)->info, x) == 0) {
        
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