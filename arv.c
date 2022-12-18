#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0;
#define TRUE 1;

/* Paciente */
typedef struct paciente {
    int id;
    int anoNascimento;
} Paciente;

/* Nó interno */
typedef struct no {
    int *chaves;
    int quantChaves;
    void **ponts;
    int folha;
    struct no *pai;
    struct no *prox;
} No;

Paciente *criaPaciente(int id, int anoNascimento)
{
    Paciente *p = (Paciente*)malloc(sizeof(Paciente));

    if (p == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    p->id = id;
    p->anoNascimento = anoNascimento;

    return p;
}

No *iniciaArvore(int ordem, Paciente *paciente)
{
    No *arv = (No*)malloc(sizeof(No));

    if (arv == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    /* Insere os dados */
    arv->chaves[0] = paciente->id;
    arv->quantChaves++;
    arv->pai = NULL;
    arv->ponts[0] = paciente;
    arv->ponts[ordem - 1] = NULL;
    arv->folha = TRUE;

    return arv;
}

No *buscaPagina(int chave, No *arv)
{
    if (arv == NULL)
        return NULL;

    No *aux = arv;

    /* Enquanto não for folha */
    while (aux->folha == 0) {
        int i = 0;
        /* Percorre todo o vetor de chaves */
        while(i < aux->quantChaves) {
            if (chave < aux->chaves[i]) break;
            
            i++;
        }

        /* vai para a próxima página */
        aux = aux->ponts[i];
    }

    return aux;
}

No *buscaChave(int chave, No *arv, int ordem)
{
    if (arv == NULL)
        return NULL;

    /* Encontrar a página folha */
    No *pagina = NULL;
    pagina = buscaPagina(chave, arv);

    int i = 0;

    /* 
        Percorre toda a página até acabarem as chaves ou 
        encontrar uma chave menor ou igual a chave que buscamos
    */
    while (i < pagina->quantChaves && chave > pagina->chaves[i]) {
        i++;
    }

    if (i >= pagina->quantChaves)
        return NULL;

    if (pagina->chaves[i] != chave)
        return NULL;
    
    return (Paciente *)pagina->ponts[i];
}

int main() {

}