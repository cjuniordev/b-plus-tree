#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define ORDEM 2

/* Estruturas */
typedef struct paciente {
    int id;
    int anoNascimento;
} Paciente;

typedef struct no {
    int *chaves;
    int quantChaves;
    void **ponts;
    int folha;
    struct no *pai;
    struct no *prox;
} No;

/* Cabeçalhos das funções */

/* Funções de busca */
No *buscaPaginaFolha(int chave, No *arv);
Paciente *busca(int chave, No *arv);

/* Funções de criação */
Paciente *criaPaciente(int id, int anoNascimento);
No *criaNo();
No *iniciaArvore(Paciente *paciente);

/* Funções de inserção */
No *insereFolha(No *pagina, Paciente *novo);
No *inserePai(No *arv, No *folha, No *novaFolha, int chavePromovida);
No *cisaoNaFolha(No *arv, No *folha, Paciente *novo);
No *cisaoInterna(No *arv, No *pagina, No *folhaDireita, int indiceAEsquerda, int chave);
No *insere(No *arv, Paciente *novo);
int tetoDaMetade(int numero);

/* Funções de impressão */
void imprimeArvore(No *arv, int nivel);

#endif