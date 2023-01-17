#include "headers.h"

Paciente *criaPaciente(int id, int anoNascimento, char nome[], char endereco[], char nomeMae[], char nomePai[], char cpf[])
{
    Paciente *p = (Paciente*)malloc(sizeof(Paciente));

    if (p == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    p->id = id;
    p->anoNascimento = anoNascimento;
    stpcpy(p->nome, nome);
    stpcpy(p->endereco, endereco);
    stpcpy(p->nomeMae, nomeMae);
    stpcpy(p->nomePai, nomePai);
    stpcpy(p->cpf, cpf);
    p->deletado = FALSE;

    return p;
}

No *criaNo()
{
    No *no = (No*)malloc(sizeof(No));

    if (no == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    no->chaves = malloc(sizeof(int) * (ORDEM - 1));

    if (no->chaves == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    no->ponts = malloc(sizeof(void*) * ORDEM);

    if (no->ponts == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    no->quantChaves = 0;
    no->pai = NULL;
    no->folha = FALSE;
    no->prox = NULL;

    return no;
}

No *iniciaArvore(Paciente *paciente)
{
    No *arv = criaNo();

    /* Insere dados */
    arv->quantChaves++;
    arv->pai = NULL;
    arv->chaves[0] = paciente->id;
    arv->ponts[0] = paciente;
    arv->ponts[ORDEM - 1] = NULL;
    arv->folha = TRUE;

    insereArquivo(paciente);

    return arv;
}