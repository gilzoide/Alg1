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
#include "lista_estatica.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Criar Nova Lista
 *
 * Descricao: insere um elem x na posicao p da lista
 *
 * Parametros:
 *          Lista* L: a lista que sera criada
 *
 * Retorno:
 *          int:    0: sucesso
 *                  1: erro: nao foi possivel criar a lista
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int cria_a_lista(Lista* L) {
    L->tamanho = 0;
    return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Esta Cheia?
 *
 * Descricao: verifica se a lista esta cheia
 *
 * Parametros:
 *          Lista* L: a lista
 *
 * Retorno:
 *          int:    0: nao esta cheia
 *                  1: esta cheia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int a_lista_esta_cheia(Lista* L) {
    
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
 * Parametros:
 *          Lista* L: a lista
 *
 * Retorno:
 *          int:    0: nao esta vazia
 *                  1: esta vazia
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int a_lista_esta_vazia(Lista* L) {
    
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
 * Parametros:
 *          Lista* L: a lista onde havera insercao
 *          elem* x: ponteiro para o elemento que sera inserido
 *          int p: a posicao onde ocorrera a insercao
 *
 * Retorno:
 *          int:    0: sucesso
 *                  1: erro: a lista esta cheia
 *                  2: erro: posicao invalida ou erro na insercao
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int insere_x_na_posicao_p_da_lista(Lista* L, elem* x, int p) {
    
    int i;
    
    if (a_lista_esta_cheia(L))
        return 1;
    
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Inserir Ordenado
 *
 * Descricao: insere um elem x mantendo a ordenacao da lista
 *
 * Parametros:
 *          Lista* L: a lista onde havera insercao
 *          elem* x: ponteiro para o elemento que sera inserido
 *
 * Retorno:
 *          int:    0: sucesso
 *                  1: erro: a lista esta cheia
 *                  2: erro: erro na insercao
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int insere_x_na_lista_ordenada(Lista* L, elem* x) {
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Busca Elemento da Lista
 *
 * Descricao: busca um elemento x e retorna um ponteiro para
 * o mesmo na lista usando o parametro p da fucao
 *
 * Parametros:
 *          Lista* L: a lista onde havera insercao
 *          elem* x: elemento que sera (ou nao) encontrado
 *          elem* p: se x for encontrado, sera o ponteiro para o mesmo,
 *                   caso contrario, sera NULL
 *
 * Retorno:
 *          int:    0: sucesso
 *                  1: erro: a lista esta vazia
 *                  2: erro: elemento nao encontrado
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int busca_elemento_na_lista(Lista* L, elem* x, elem* p) {
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Funcao Apagar/Destruir/Queimar Elemento da Lista
 *
 * Descricao: retira um elemento da lista
 *
 * Parametros:
 *          Lista* L: a lista onde havera insercao
 *          elem* x: elemento que sera retirado
 *
 * Retorno:
 *          int:    0: sucesso
 *                  1: erro: a lista esta vazia
 *                  2: erro: elemento nao encontrado
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int retira_x_da_lista(Lista* L, elem* x) {
    
}