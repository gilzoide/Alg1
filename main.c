//	Trabalho 1 de Algoritmos e Estruturas de Dados 1
//
//  Created by Léo Sampaio, Alex Barboza e Gil Reis on 02/11/13.
//
//  Copyright (c) 2013 Léo Sampaio. All rights reserved.
//

#include "fila_estatica.h"
#include "lista_estatica.h"
#include "pilha_estatica.h"

#include <stdio.h>


void MostraEscolhas () {
	puts ("Leilões Alg1:\n");

	puts ("c) Cadastrar produto");
	puts ("l) Listar produtos e lances");
	puts ("d) Dar um lance");
	puts ("e) Encerrar leilao\n");
	
	puts ("q) Sair do programa");
}


void CadastraProduto (Lista *produtos) {
	char nome[50];
	
	printf ("Nome do produto: ");
	fgets (nome, 50, stdin);	// le do usuario o nome do produto
	
	ListaInsereOrdenado (produtos, nome);	// insere nome na lista
}


void ListarProdutos (Lista produtos) {
	puts ("Produtos cadastrados\n");
	ListaPrint (&produtos);
	puts ("");
}


void DarLance (Lista *produtos) {
	float valor;
	char nome[30], usuario[30];
	
	fgets (nome, 30, stdin);
	
	if (ListaBusca (produtos, nome, &nome) != 0) {
		puts ("Produto Invalido!\n\
			Escolha 'l' para listagem de produtos"
		return;
	}
	
	do {
		printf ("Valor do lance: ");
		scanf ("%f", &valor);
	} while (valor < 0);

#ifdef ALGI_lista_dinamica_h	
	float ultimo = PilhaEspiaTopo (&produtos->info.a_pilha);
#endif
#ifdef ALGI_lista_estatica_h
	float ultimo = PilhaEspiaTopo (&produtos->info.a_pilha);
#endif

	if (valor < ultimo) {
		puts ("Valor menor que ultimo lance dado!");
	}
	else if (valor == ultimo) {
		ListaInsereFila (produtos, nome, usuario);
	}
	else {
		ListaInserePilha (produtos, nome, &valor);
	}
}


void EncerraLeilao (Lista *produtos) {
	
}



int main (int argc, const char * argv[])
{
	char escolha = 0;	// escolha do usuario a cada interacao com o sistema
	
	Lista produtos;
	
	ListaCria (&produtos);
	
	// loop principal do programa
	while (escolha != 'q') {
		MostraEscolhas ();	// mostra as escolhas pro usuario
		scanf (" %c", &escolha);	// le a escolha do usuario
		
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

