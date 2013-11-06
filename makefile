# Makefile da geral

objs = alg1.o lista_est.o lista_din.o fila_est.o fila_din.o pilha_est.o pilha_din.o

source = alg1.c makefile \
		 lista_est.c lista_din.c fila_est.c fila_din.c pilha_est.c pilha_din.c \
		 lista_est.h lista_din.h fila_est.h fila_din.h pilha_est.h pilha_din.h

lista_estatica.o : lista_estatica.h
lista_dinamica.o : lista_dinamica.h
fila_est.o : fila_est.h
fila_din.o : fila_din.h

commit :
	@git commit -a && git push

zip :
	@zip alg1 $(source)

clean :
	@rm $(objs) *~ alg1.zip
