# Makefile da geral

objs = main.o lista_estatica.o lista_dinamica.o fila_estatica.o fila_dinamica.o pilha_estatica.o pilha_dinamica.o
objs_static = fila_estatica.o pilha_estatica.o lista_estatica.o
objs_dinamic = fila_dinamica.o pilha_dinamica.o lista_dinamica.o

source_static = fila_estatica.c fila_estatica.h pilha_estatica.c pilha_estatica.h lista_estatica.c lista_estatica.h
source_dinamic = fila_dinamica.c fila_dinamica.h pilha_dinamica.c pilha_dinamica.h lista_dinamica.c lista_dinamica.h


CFLAGS = -g -O2 -march=native

# Programa final: versao estatica
estatica : $(objs_static) main.o
	@cc main.o $(objs_static) -o main $(CFLAGS)

dinamica : $(objs_dinamic) main.o
	@cc main.o $(objs_dinamic) -o main -O3 -march=native -g $(CFLAGS)


# objetos
main.o : $(source_static) $(source_dinamic)
	@cc -c main.c $(CFLAGS)

lista_estatica.o : lista_estatica.h
	@cc -c lista_estatica.c $(CFLAGS)

lista_dinamica.o : lista_dinamica.h
	@cc -c lista_dinamica.c $(CFLAGS)

fila_estatica.o : fila_estatica.h
	@cc -c fila_estatica.c $(CFLAGS)

fila_dinamica.o : fila_dinamica.h
	@cc -c fila_dinamica.c $(CFLAGS)

pilha_estatica.o : pilha_estatica.h
	@cc -c pilha_estatica.c $(CFLAGS)

pilha_dinamica.o : pilha_dinamica.h
	@cc -c pilha_dinamica.c $(CFLAGS)


run : main.o
	@./main

commit :
	@git commit -a && git push

zip :
	@zip makefile main.c $(source_static) $(source_dinamic)

clean :
	@rm $(objs) *~ alg1.zip
