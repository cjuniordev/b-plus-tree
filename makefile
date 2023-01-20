OBJS	= cria.o insere.o main.o busca.o imprime.o auxiliares.o arquivo.o deleta.o
SOURCE	= cria.c insere.c main.c busca.c imprime.c auxiliares.c arquivo.c deleta.c
HEADER	= headers.h
OUT		= bin/bplus
CC	 	= gcc
FLAGS	= -c -Wall -Werror -Wextra

all: $(OBJS)
	$(CC) -o $(OUT) $(OBJS)

cria.o: cria.c $(HEADER)
	$(CC) $(FLAGS) cria.c 

insere.o: insere.c $(HEADER)
	$(CC) $(FLAGS) insere.c 

main.o: main.c $(HEADER)
	$(CC) $(FLAGS) main.c 

busca.o: busca.c $(HEADER)
	$(CC) $(FLAGS) busca.c 

imprime.o: imprime.c $(HEADER)
	$(CC) $(FLAGS) imprime.c 

auxiliares.o: auxiliares.c $(HEADER)
	$(CC) $(FLAGS) auxiliares.c 

arquivo.o: arquivo.c $(HEADER)
	$(CC) $(FLAGS) arquivo.c 

deleta.o: deleta.c $(HEADER)
	$(CC) $(FLAGS) deleta.c 

clean:
	rm -rf $(OBJS) $(OUT)