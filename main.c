//
//  main.c
//  T1
//
//  Created by Léo Sampaio on 02/11/13.
//  Copyright (c) 2013 Léo Sampaio. All rights reserved.
//

#include "fila_est.h"
#include "lista_estatica.h"
#include pilha (ainda nao sabemos o nome q o jovem dara ao role)

#include <stdio.h>


void MostraEscolhas () {
	puts ("c) Cadastrar produto");
	puts ("l) Listar produtos e lances");
	puts ("d) Dar um lance");
	puts ("e) Encerrar leilao\n");
	
	puts ("q) Sair do programa");
}



int main(int argc, const char * argv[])
{
	char escolha = 0;	// escolha do usuario a cada interacao com o sistema
	
	Fila historico;
	Lista produtos;
	
	FilaInicia(&historico);
	ListaCria (&produtos);
	
	// loop principal do programa
	while (escolha != 'q') {
		MostraEscolhas ();	// mostra as escolhas pro usuario
		scanf (" %c", &escolha);	// le a escolha do usuario
		
		switch (escolha) {
			case 'c':
				CadastraProduto (&L);
				break;
				
			case 'l':
				ListarProdutos (L);
				break;
			
			case 'd':
				DarLance (
			
		}
	}
	
    
    return 0;
}

