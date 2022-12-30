#include "headers.h"

No *cadastrar(No *arv)
{
    int id, nascimento;
    char nome[200], endereco[500], nomeMae[200], nomePai[200], cpf[20];

    printf("Insira o ID do paciente: ");
    scanf("%d", &id);

    printf("Insira o ano de nascimento: ");
    scanf("%d", &nascimento);

    fflush(stdin);
    printf("Insira o nome: ");
    fgets(nome, 200, stdin);

    fflush(stdin);
    printf("Insira o endereco: ");
    fgets(endereco, 500, stdin);

    fflush(stdin);
    printf("Insira o nome da mae: ");
    fgets(nomeMae, 200, stdin);

    fflush(stdin);
    printf("Insira o nome do pai: ");
    fgets(nomePai, 200, stdin);

    fflush(stdin);
    printf("Insira o CPF: ");
    fgets(cpf, 20, stdin);

    Paciente *p = criaPaciente(id, nascimento, nome, endereco, nomeMae, nomePai, cpf);
    insere(arv, p);

    printf("Paciente cadastrado com sucesso.\n");

    return arv;

}

void buscar(No *arv)
{
    if (arv == NULL)
    {
        printf("Nao existe pacientes cadastrados.\n");
        return;
    }

    int id;

    printf("Insira o ID do paciente: ");
    scanf("%d", &id);

    Paciente *p = busca(arv, id);

    imprimePaciente(p);
}

No *remover(No *arv)
{
    if (arv == NULL)
    {
        printf("Nao existe pacientes cadastrados.\n");
        return arv;
    }

    int id;
    printf("Insira o ID do paciente: ");
    scanf("%d", &id);

    // chama funcao de remocao

    return arv;
}

void imprimir(No *arv)
{
    if (arv == NULL)
    {
        printf("Nao existe pacientes cadastrados.\n");
        return;
    }

    imprimeArvore(arv);
}
        
void imprimirIntervalo(No *arv)
{
    if (arv == NULL)
    {
        printf("Nao existe pacientes cadastrados.\n");
        return;
    }

    int inicio, fim;
    printf("Insira o id de inicio: ");
    scanf("%d", &inicio);

    printf("Insira o id de fim: ");
    scanf("%d", &fim);

    // chama funcao de impressao no intervalo
}