//	Trabalho 1 de Algoritmos e Estruturas de Dados 1
//
//  Created by Léo Sampaio, Alex Barboza e Gil Reis on 02/11/13.
//
//  Copyright (c) 2013 Léo Sampaio. All rights reserved.
//


#include "fila_dinamica.h"
#include "lista_dinamica.h"
#include "pilha_dinamica.h"

//#include "fila_estatica.h"
//#include "lista_estatica.h"
//#include "pilha_estatica.h"

#include <stdio.h>


void MostraEscolhas () {
	puts ("Leilões Alg1:");
	puts ("c) Cadastrar produto");
	puts ("l) Listar produtos e lances");
	puts ("d) Dar um lance");
	puts ("e) Encerrar leilao");
	puts ("q) Sair do programa\n");
	
	printf ("resposta > ");
}


void CadastraProduto (Lista *produtos) {
	elem novo;
	
	printf ("Nome do produto: ");
	fgets (novo.nome, TAMANHO_DO_NOME, stdin);	// le do usuario o nome do produto
	
	ListaInsereOrdenado (produtos, &novo);	// insere nome na lista
	puts ("\n");
}


void ListarProdutos (Lista produtos) {
	if (ListaEstaVazia (&produtos)) {
		puts ("Nenhum produto cadastrado!\n\n");
		return;
	}
	else {
		puts ("\tProdutos cadastrados");
		puts ("\t--------------------");
		ListaPrint (&produtos);
		puts ("\n");
	}
}


void DarLance (Lista *produtos) {
	if (ListaEstaVazia (produtos)) {
		puts ("Nenhum produto cadastrado!\n\n");
		return;
	}
	
	float valor;
	char usuario[30];
	elem novo, *aux;
	
	printf ("Nome do produto: ");
	fgets (novo.nome, TAMANHO_DO_NOME, stdin);
	
	int i = ListaBusca (produtos, &novo, &aux);
	if (i == -1 || i == -2) {
		puts ("Produto Invalido!\nEscolha 'l' para listagem de produtos\n");
		return;
	}
	
	printf ("Nome do usuario: ");
	fgets (usuario, 30, stdin);
	
	do {
		printf ("Valor do lance: ");
		scanf ("%f", &valor);
	} while (valor < 0);

	float ultimo;

#ifdef ALGI_lista_dinamica_h
	PilhaEspiaTopo (&aux->a_pilha, &ultimo);
#endif
#ifdef ALGI_lista_estatica_h
	PilhaEspiaTopo (&produtos->elementos[i].a_pilha, &ultimo);
#endif

	if (valor < ultimo) {
		puts ("Valor menor que ultimo lance dado!");
	}
	else if (valor == ultimo) {
		ListaInsereFila (produtos, &novo, usuario);
	}
	else {
		ListaInserePilha (produtos, &novo, &valor);
		ListaInsereFila (produtos, &novo, usuario);
	}
}


void EncerraLeilao (Lista *produtos) {
	
}



int main (int argc, const char * argv[]) {
	
	int escolha;	// escolha do usuario a cada interacao com o sistema
	
	Lista produtos;
	
	ListaCria (&produtos);
	
	// loop principal do programa
	while (escolha != 'q') {
		MostraEscolhas ();	// mostra as escolhas pro usuario
		__fpurge (stdin);
		scanf (" %c", &escolha);	// le a escolha do usuario
		__fpurge (stdin);
		puts ("");
		
		switch (escolha) {
			case 'c':
				CadastraProduto (&produtos);
				break;
				
			case 'l':
				ListarProdutos (produtos);
				break;
			
			case 'd':
				DarLance (&produtos);
				break;
				
			case 'e':
				EncerraLeilao (&produtos);
				break;
		}
	}
	
	
    
    return 0;
}

