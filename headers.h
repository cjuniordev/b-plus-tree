#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define ORDEM 4

/* Estrutura de um paciente */
typedef struct paciente {
    int id;
    int anoNascimento;
    char nome[200];
    char endereco[500];
    char nomeMae[200];
    char nomePai[200];
    char cpf[20];
    int deletado;
} Paciente;

/* Estrutura de um nó da arvore */
typedef struct no {
    int *chaves;
    int quantChaves;
    void **ponts;
    int folha;
    struct no *pai;
    struct no *prox;
} No;

/* 
 * Função que recebe uma chave e uma árvore e retorna a página folha que contem a chave
 */
No *buscaPaginaFolha(int chave, No *arv);

/* 
 * Função que recebe uma chave e uma árvore e retorna o paciente que contem a chave,
 * o parametro paginaFolha é passado por referência e recebe a página folha que contem a chave
 */
Paciente *busca(int chave, No *arv, No **paginaFolha);

/* 
 * Função que recebe uma chave e uma árvore e retorna a quantidade de elementos neste invervalo
 */
int buscaIntervalo(No *arv, int inicio, int fim, int chaves[], void *ponts[]);

/* 
 * Função que recebe os dados do paciente e retorna um ponteiro para um paciente
 */
Paciente *criaPaciente(int id, int anoNascimento, char nome[], char endereco[], char nomeMae[], char nomePai[], char cpf[]);

/* 
 * Função que retorna um ponteiro para um nó
 */
No *criaNo();

/* 
 * Funçao que cria uma nova árvore com um paciente
 */
No *iniciaArvore(Paciente *paciente);

/* 
 * Insere paciente numa folha
 */
No *insereFolha(No *pagina, Paciente *novo, int remontando);

/* 
 * Função auxiliar para a cisão, insere a chave promovida no pai
 */
No *inserePai(No *arv, No *folha, No *novaFolha, int chavePromovida);

/* 
 * Realiza a cisão de uma folha
 */
No *cisaoNaFolha(No *arv, No *folha, Paciente *novo, int remontando);

/* 
 * Realiza a cisão de um nó interno
 */
No *cisaoInterna(No *arv, No *pagina, No *folhaDireita, int indiceAEsquerda, int chave);

/* 
 * Insere um paciente numa árvore
 */
No *insere(No *arv, Paciente *novo, int remontando);

/* 
 * Função auxiliar que calcula e retona o teto de ordem / 2
 */
int tetoDaMetade(int numero);

/* 
 * Enfileira um nó numa fila
 */
void enfileira(No **fila, No *no);

/* 
 * Desenfileira um nó numa fila
 */
No *desenfileira(No **fila);

/* 
 * Procura e retorna a posição em que a raiz tem que descer para chegar na folha passada por parâmetro
 */
int posicaoParaFolha(No *arv, No *filho);

/* 
 * Imprime a árvore
 */
void imprimeArvore(No *arv);

/* 
 * Imprime um paciente
 */
void imprimePaciente(Paciente *p);

/* 
 * Imprime a arvore em um certo intervalo
 */
void imprimeNoIntervalo(No *arv, int inicio, int fim);

/* 
 * Função auxiliar, uma "interface" para o usuário inserir um paciente
 */
No *cadastrar(No *arv);

/* 
 * Função auxiliar, uma "interface" para o usuário buscar um paciente
 */
void buscar(No *arv);

/* 
 * Função auxiliar, uma "interface" para o usuário remover um paciente
 */
No *remover(No *arv);

/* 
 * Função auxiliar, uma "interface" para o usuário imprimir a arvore
 */
void imprimir(No *arv);

/* 
 * Função auxiliar, uma "interface" para o usuário imprimir um intervalo
 */
void menuImprimirIntervalo(No *arv);

/* 
 * Função auxiliar que limpa o buffer do teclado
 */
void limpaBuffer();

/* 
 * Função que insere um paciente no arquivo
 */
void insereArquivo(Paciente *p);

/* 
 * Função que reconstroi a arvore a partir do arquivo
 */
No *reconstroiArv();

/* 
 * Função que "remove" um paciente do arquivo
 */
void deletaArquivo(int indice);

/* 
 * Função que deleta um paciente da arvore e do disco
 */
No *deletar(No *arv, int chave);

/* 
 * Função que deleta o no da arvore
 */
No *deletaNo(No *arv, No *pagina, int chave, void *pont);

/* 
 * Função de redistribuição dos nós
 */
No *redistribuicao(No *arv, No *n, No *irmao, int indiceIrmao, int indiceDescida, int descida);

/* 
 * Função de concatenção dos nós
 */
No *concatenar(No *arv, No *pagina, No *irmao, int indiceIrmao, int descida);

/* 
 * Função que prepara a arvore para a remoção, encontra a posição da chave e reorganiza os ponteiros
 */
No *preparaRemocao(No *n, int chave, No *pont);

/* 
 * Função auxiliar, busca o indice do irmao do no passado por parametro
 */
int buscaIndiceIrmao(No *no);

/* 
 * Função que troca a raiz da arvore quando todas as chaves são removidas
 */
No *mudaRaiz(No *arv);

#endif