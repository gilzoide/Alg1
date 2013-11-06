/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  ALG1 - Trabalho 1                                                          *
 *  lista_estatica.c                                                           *
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
 *  Criado em 2 de Novembro de 2013                                            *
 *                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_estatica.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Criar Nova Lista
 *
 * Descricao: insere um elem x na posicao p da lista
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaCria(Lista* L) {
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
    
    if (L->tamanho >= TAMANHO_MAX_DA_LISTA)
        return 1;
    else
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
    
    if (L->tamanho <= 0)
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
    
    int i;
    
    if (ListaEstaCheia(L))
        return 1;
    
    // checa se a posicao eh valida
    else if (p > L->tamanho || p < 0)
        return 2;
    
    // 'empurra' os elementos para a direita
    for (i = p; i < L->tamanho; i++) {
        
        // L->elementos[i + 1] = L->elementos[i];
        strcpy(L->elementos[i + 1].info, L->elementos[i].info);
    }
    
    // insere o novo elemento
    strcpy(L->elementos[p].info, x->info);
    
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
    
    int i;
    
    // busca pela posicao que mantera a lista ordenada
    for (i = 0; i < L->tamanho; i++) {
        if (strcmp(L->elementos[i].info, x->info) >= 0)
            break;
    }
    
    // insere x na posicao encontrada
    return ListaInsereNaPosicaoP(L, x, i);
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
    
    int i;
    *p = NULL;
    
    if (ListaEstaVazia(L))
        return 1;
    
    // percorre a lista ate encontrar x
    for (i = 0; i < L->tamanho; i++) {
        if (strcmp(L->elementos[i].info, x->info) == 0)
            break;
    }
    
    // checa se realmente foi encontrado
    if (strcmp(L->elementos[i].info, x->info) == 0) {
        
        *p = &L->elementos[i];
        return 0;
    }
    
    else
        return 2;
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Apagar/Destruir/Queimar Elemento da Lista
 *
 * Descricao: retira um elemento da lista
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int ListaRetira(Lista* L, elem* x) {
    
    elem* p; elem* i;
    
    int encontrou = ListaBusca(L, x, &p);
    
    if (encontrou != 0)
        return encontrou;
    
    // reorganiza a lista usando aritmetica de ponteiros
    for (i = p; i != &L->elementos[L->tamanho]; i++) {
        strcpy(i->info, (i + 1)->info);
    }
    
    L->tamanho--;
    
    return 0;
}