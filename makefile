# Makefile da geral

objs = main.o lista_estatica.o lista_dinamica.o fila_estatica.o fila_dinamica.o pilha_estatica.o pilha_dinamica.o
objs_static = fila_estatica.o pilha_estatica.o lista_estatica.o
objs_dinamic = fila_dinamica.o pilha_dinamica.o lista_dinamica.o

source_static = fila_estatica.c fila_estatica.h pilha_estatica.c pilha_estatica.h lista_estatica.c lista_estatica.h
source_dinamic = fila_dinamica.c fila_dinamica.h pilha_dinamica.c pilha_dinamica.h lista_dinamica.c lista_dinamica.h

# Programa final: versao estatica
estatica : $(objs_static) main.o
	@cc main.o $(objs_static) -o main -O3 -march=native

dinamica : $(objs_dinamic) main.o
	@cc main.o $(objs_dinamic) -o main -O3 -march=native


# objetos
main.o : $(source_static) $(source_dinamic)
lista_estatica.o : lista_estatica.h
lista_dinamica.o : lista_dinamica.h
fila_estatica.o : fila_estatica.h
fila_dinamica.o : fila_dinamica.h
pilha_estatica.o : pilha_estatica.h
pilha_dinamica.o : pilha_dinamica.h


run : main.o
	@./main

commit :
	@git commit -a && git push

zip :
	@zip makefile main.c $(source_static) $(source_dinamic)

clean :
	@rm $(objs) *~ alg1.zip
