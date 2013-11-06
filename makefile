# Makefile da geral

objs = main.o lista_estatica.o lista_dinamica.o fila_estatica.o fila_dinamica.o pilha_estatica.o pilha_dinamica.o

source = main.c makefile \
		 lista_estatica.c lista_dinamica.c fila_estatica.c fila_dinamica.c pilha_estatica.c pilha_dinamica.c \
		 lista_estatica.h lista_dinamica.h fila_estatica.h fila_dinamica.h pilha_estatica.h pilha_dinamica.h


lista_estatica.o : lista_estatica.h
lista_dinamica.o : lista_dinamica.h
fila_estatica.o : fila_estatica.h
fila_dinamica.o : fila_dinamica.h
pilha_estatica.o : pilha_estatica.h
pilha_dinamica.o : pilha_dinamica.h

commit :
	@git commit -a && git push

zip :
	@zip alg1 $(source)

clean :
	@rm $(objs) *~ alg1.zip
