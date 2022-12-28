OBJS	= cria.o insere.o arv.o busca.o imprime.o
SOURCE	= cria.c insere.c arv.c busca.c imprime.c
HEADER	= headers.h
OUT		= bin/bplus
CC	 	= gcc
FLAGS	= -c -Wall -Werror -Wextra

all: $(OBJS)
	gcc -o $(OUT) $(OBJS)

cria.o: cria.c headers.h
	gcc $(FLAGS) cria.c 

insere.o: insere.c
	gcc $(FLAGS) insere.c 

arv.o: arv.c
	gcc $(FLAGS) arv.c 

busca.o: busca.c
	gcc $(FLAGS) busca.c 

imprime.o: imprime.c
	gcc $(FLAGS) imprime.c 

clean:
	rm -rf $(OBJS) $(OUT)