/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  ALG1 - Trabalho 1                                                          *
 *                                                                             *
 *  Alex Frederico Ramos Barboza    Nº7986480                                  *
 *  alex.barbosa@usp.br                                                        *
 *                                                                             *
 *  Gil Barbosa Reis                Nº8532248                                  *
 *  gil.reis@usp.br                                                            *
 *                                                                             *
 *  Leonardo Sampaio Ferraz Ribeiro Nº8532300                                  *
 *  leonardo.sampaio.ribeiro@usp.br                                            *
 *                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "fila_dinamica.h"
#include "lista_dinamica.h"
#include "pilha_dinamica.h"

//#include "fila_estatica.h"
//#include "lista_estatica.h"
//#include "pilha_estatica.h"


#include <stdlib.h>
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


void ListarProdutos (Lista *produtos) {
	if (ListaEstaVazia (produtos)) {
		puts ("Nenhum produto cadastrado!\n\n");
		return;
	}
	else {
		puts ("\tProdutos cadastrados");
		puts ("\t--------------------");
		ListaPrint (produtos, 0);
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
	} while (valor <= 0);

	float ultimo;

#ifdef ALGI_lista_dinamica_h
	PilhaEspiaTopo (&aux->a_pilha, &ultimo);
#elif ALGI_lista_estatica_h
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
	
	puts ("\n");
}


void EncerraLeilao (Lista *produtos) {
	elem *aux;
	float lance;
	char nome[TAMANHO_DO_NOME];
	
	while (!ListaEstaVazia (produtos)) {
		ListaPop (produtos, &aux);	// pega cada bloco da lista, pra imprimir
		printf ("%s: ", aux->nome);	// mostra nome do produto
		
		if (PilhaPop (&aux->a_pilha, &lance) == ERRO) {	// pega o lance
			puts ("sem comprador; nenhum lance dado");	// se ninguem deu lance (ERRO)
		}
		else {	// tem lances! Alguem comprou
		
			// acha o nome do comprador	
			#ifdef ALGI_lista_dinamica_h
				FilaRetira (&aux->a_pilha.topo->preferencia, nome);
			#elif ALGI_lista_estatica_h
				FilaRetira (&aux->a_pilha.preferencia[aux->a_pilha.topo], nome);
			#endif
			printf ("Comprador: %s, por R$%.2f\n", nome, lance);
			
			// tem mais gente que deu o mesmo lance: ve se o primeiro quer dividir
			if (
				#ifdef ALGI_lista_dinamica_h
					FilaRetira (&aux->a_pilha.topo->preferencia, nome)
				#elif ALGI_lista_estatica_h
					FilaRetira (&aux->a_pilha.preferencia[aux->a_pilha.topo], nome)
				#endif
			!= ERRO) {
					
				printf ("Mais pessoas deram o mesmo lance.\nDeseja dividir o produto com %s", nome);
				while (
					#ifdef ALGI_lista_dinamica_h
						FilaRetira (&aux->a_pilha.topo->preferencia, nome)
					#elif ALGI_lista_estatica_h
						FilaRetira (&aux->a_pilha.preferencia[aux->a_pilha.topo], nome)
					#endif
				!= ERRO) {
					printf (", %s", nome);
				}
				
				printf ("?  s/n");
				
				char escolha;
				do {
					escolha = getchar ();
				} while (escolha != 's' && escolha != 'n');
				
				switch (escolha) {
					case 's':
						puts ("Voce escolheu dividir o premio. Parabens pela aquisicao!\n");
						break;
					case 'n':
						puts ("Voce escolheu comprar sozinho. Parabens pela aquisicao!\n");
						break;
				}
			}
			
			PilhaDestroi (&aux->a_pilha);
			free (aux);
		}
	}
}



int main (int argc, const char * argv[]) {
	
	char escolha;	// escolha do usuario a cada interacao com o sistema
	
	Lista produtos;
	
	ListaCria (&produtos);
	
	// loop principal do programa
	while (escolha != 'q') {
		MostraEscolhas ();	// mostra as escolhas pro usuario
		scanf (" %c", &escolha);	// le a escolha do usuario
		
// flush na entrada: especifica por OS
#ifdef __linux__
		__fpurge (stdin);
#elif __APPLE__
		fpurge (stdin);
#elif WIN32
		fflush (stdin);
#endif

		puts ("");
		
		switch (escolha) {
			case 'c':
				CadastraProduto (&produtos);
				break;
				
			case 'l':
				ListarProdutos (&produtos);
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

