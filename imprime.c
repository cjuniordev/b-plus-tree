#include "headers.h"

void enfileira(No **fila, No *no) 
{
    if ((*fila) == NULL) {
        *fila = no;
        (*fila)->prox = NULL;
        return;
    }


    No *aux = (*fila);

    while(aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = no;
    no->prox = NULL;
}

No *desenfileira(No **fila)
{
    No *aux = (*fila);
    (*fila) = (*fila)->prox;
    aux->prox = NULL;

    return aux;
}

int posicaoParaFolha(No *arv, No *filho)
{
    int i = 0;
    No *aux = filho;
    while (aux != arv) {
        aux = aux->pai;
        i++;
    }

    return i;
}

void imprimeArvore(No *arv) {
    No *aux = NULL;
    int i = 0;
    int nivel = 0;
    int proxNivel = 0;
    char extra = '*';

    if (arv == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    No *fila = NULL;
    enfileira(&fila, arv);
    
    while (fila != NULL) {
        aux = desenfileira(&fila);

        if (aux->pai != NULL && aux == aux->pai->ponts[0]) {
            proxNivel = posicaoParaFolha(arv, aux);

            if (proxNivel != nivel) {
                nivel = proxNivel;
                printf("\n");
            }
        }

        if(aux->folha == TRUE)
            extra = '*';
        else
            extra = ' ';
        

        for (i = 0; i < aux->quantChaves; i++) {
            printf("%d%c ", aux->chaves[i], extra);
        }

        if (aux->folha == FALSE) {
            for (i = 0; i <= aux->quantChaves; i++)
                enfileira(&fila, aux->ponts[i]);
        }
        
        printf("| ");
    }

    printf("\n");
}

void imprimePaciente(Paciente *p)
{
    printf("ID: %d\n", p->id);
    printf("Ano de Nascimento: %d\n", p->anoNascimento);
    puts(p->nome);
    puts(p->endereco);
    puts(p->nomeMae);
    puts(p->nomePai);
    puts(p->cpf);
}

void imprimeNoIntervalo(No *arv, int inicio, int fim)
{
    int tam = (fim - inicio) + 1;
    int chaves[tam];
    void *ponts[tam];
    int quantidade = buscaIntervalo(arv, inicio, fim, chaves, ponts);
    
    if (quantidade == 0) {
        printf("Sem resultados para este intervalo!\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("%d -", chaves[i]);
    }
}