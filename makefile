OBJS	= cria.o insere.o main.o busca.o imprime.o auxiliares.o arquivo.o deleta.o
SOURCE	= cria.c insere.c main.c busca.c imprime.c auxiliares.c arquivo.c deleta.c
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

main.o: main.c
	gcc $(FLAGS) main.c 

busca.o: busca.c
	gcc $(FLAGS) busca.c 

imprime.o: imprime.c
	gcc $(FLAGS) imprime.c 

auxiliares.o: auxiliares.c
	gcc $(FLAGS) auxiliares.c 

arquivo.o: arquivo.c
	gcc $(FLAGS) arquivo.c 

deleta.o: deleta.c
	gcc $(FLAGS) deleta.c 

clean:
	rm -rf $(OBJS) $(OUT)