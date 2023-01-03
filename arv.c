#include "headers.h"

/* 
 [x] Criar structs
 [x] Criar funções de busca
 [x] Criar funções de criação
 [x] Criar funções de inserção
 [x] Criar funções de impressão
 [ ] Criar funções de remoção
 [ ] Adicionar dados dos funcionários
 [ ] Criar menu
 [ ] Criar funcoes de disco
 [ ] Melhorar funcao de impressão
*/

int main() {
   No *raiz = NULL;
  /*   Paciente *paciente = criaPaciente(5, 1990);
    Paciente *paciente2 = criaPaciente(6, 1991);
    Paciente *paciente3 = criaPaciente(3, 1992);
    Paciente *paciente4 = criaPaciente(4, 1993);

    raiz = insere(raiz, paciente);
    raiz = insere(raiz, paciente2);
    raiz = insere(raiz, paciente3);
    raiz = insere(raiz, paciente4);
 */
    //imprime(raiz);

    int rodando = TRUE, opcao;

    while(rodando)
    { 
        printf("\n\n        PACIENTES       \n");
        printf("0 - Cadastrar paciente\n");
        printf("1 - Buscar paciente\n");
        printf("2 - Remover paciente\n");
        printf("3 - Imprimir pacientes\n");
        printf("4 - Pacientes em um intervalo\n");
        printf("5 - Sair\n");

        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                raiz = cadastrar(raiz);
                break;
            case 1:
                buscar(raiz);
                break;
            case 2:
                // remove
                break;
            case 3:
                imprimir(raiz);
                break;
            case 4:
                // pacientes em um intervalo
                break;
            case 5:
                printf("Saindo...\n");
                rodando = FALSE;
                break;
            case 6:
                leArquivo();
                break;
            default:
                break;  
        }

    }
}