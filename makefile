# Makefile da geral

objs = main.o lista_estatica.o lista_dinamica.o fila_estatica.o fila_dinamica.o pilha_estatica.o pilha_dinamica.o
objs_static = fila_estatica.o pilha_estatica.o lista_estatica.o
objs_dinamic = fila_dinamica.o pilha_dinamica.o lista_dinamica.o

static = fila_estatica.c fila_estatica.h pilha_estatica.c pilha_estatica.h lista_estatica.c lista_estatica.h
dinamic = fila_dinamica.c fila_dinamica.h pilha_dinamica.c pilha_dinamica.h lista_dinamica.c lista_dinamica.h

# Programa final: versao estatica
estatica : $(static)
	@cc main.o $(objs_static) -o main -O3 -march=native

dinamica : $(dinamic)
	@cc main.o $(objs_dinamic) -o main -O3 -march=native


# objetos
main.o : $(static) $(dinamic)
lista_estatica.o : lista_estatica.h
lista_dinamica.o : lista_dinamica.h
fila_estatica.o : fila_estatica.h
fila_dinamica.o : fila_dinamica.h
pilha_estatica.o : pilha_estatica.h
pilha_dinamica.o : pilha_dinamica.h



commit :
	@git commit -a && git push

zip :
	@zip makefile main.c $(static) $(dinamic)

clean :
	@rm $(objs) *~ alg1.zip
