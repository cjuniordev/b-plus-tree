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
    char nome[200];
    char endereco[500];
    char nomeMae[200];
    char nomePai[200];
    char cpf[20];
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
Paciente *busca(int chave, No *arv, No **paginaFolha);
int buscaIntervalo(No *arv, int inicio, int fim, int chaves[], void *ponts[]);

/* Funções de criação */
Paciente *criaPaciente(int id, int anoNascimento, char nome[], char endereco[], char nomeMae[], char nomePai[], char cpf[]);
No *criaNo();
No *iniciaArvore(Paciente *paciente);

/* Funções de inserção */
No *insereFolha(No *pagina, Paciente *novo);
No *inserePai(No *arv, No *folha, No *novaFolha, int chavePromovida);
No *cisaoNaFolha(No *arv, No *folha, Paciente *novo);
No *cisaoInterna(No *arv, No *pagina, No *folhaDireita, int indiceAEsquerda, int chave);
No *insere(No *arv, Paciente *novo);
int tetoDaMetade(int numero);

/* Funções de impressão e auxiliares */
void enfileira(No **fila, No *no);
No *desenfileira(No **fila);
int posicaoParaFolha(No *arv, No *filho);
void imprimeArvore(No *arv);
void imprimePaciente(Paciente *p);
void imprimePacienteArquivo(Paciente p);
void imprimeNoIntervalo(No *arv, int inicio, int fim);

/* Funções auxiliares */
No *cadastrar(No *arv);
void buscar(No *arv);
No *remover(No *arv);
void imprimir(No *arv);
void menuImprimirIntervalo(No *arv);
void limpaBuffer();

/* Arquivos */
void insereArquivo(Paciente *p);
void leArquivo();
No *reconstroiArv();

/* Funções de deleção */

#endif