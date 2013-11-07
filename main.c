//	Trabalho 1 de Algoritmos e Estruturas de Dados 1
//
//  Created by Léo Sampaio, Alex Barboza e Gil Reis on 02/11/13.
//
//  Copyright (c) 2013 Léo Sampaio. All rights reserved.
//


#include "fila_dinamica.h"
#include "lista_dinamica.h"
#include "pilha_dinamica.h"
/*
#include "fila_estatica.h"
#include "lista_estatica.h"
#include "pilha_estatica.h"
*/
#include <stdio.h>


void MostraEscolhas () {
	puts ("Leilões Alg1:");
	puts ("c) Cadastrar produto");
	puts ("l) Listar produtos e lances");
	puts ("d) Dar um lance");
	puts ("e) Encerrar leilao\n");
	
	puts ("q) Sair do programa");
}


void CadastraProduto (Lista *produtos) {
	elem novo;
	
	printf ("Nome do produto: ");
	fgets (novo.nome, 50, stdin);	// le do usuario o nome do produto
	
	ListaInsereOrdenado (produtos, &novo);	// insere nome na lista
}


void ListarProdutos (Lista produtos) {
	if (ListaEstaVazia (&produtos)) {
		puts ("Nenhum produto cadastrado!\n\n");
	}
	else {
		puts ("Produtos cadastrados\n");
		ListaPrint (&produtos);
		puts ("\n");
	}
}


void DarLance (Lista *produtos) {
	float valor;
	char usuario[30];
	elem novo, **aux;
	
	fgets (novo.nome, 30, stdin);
	
	if (ListaBusca (produtos, &novo, aux) != 0) {
		puts ("Produto Invalido!\n\
			Escolha 'l' para listagem de produtos");
		return;
	}
	
	do {
		printf ("Valor do lance: ");
		scanf ("%f", &valor);
	} while (valor < 0);

#ifdef ALGI_lista_dinamica_h
	float ultimo;
	PilhaEspiaTopo (&(*aux)->a_pilha, &ultimo);
#endif
#ifdef ALGI_lista_estatica_h
	int i = ListaBusca (produtos, &novo, aux);
	float ultimo;
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
		scanf (" %c", &escolha);	// le a escolha do usuario
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

