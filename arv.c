#include "headers.h"

int main() {
    No *raiz = NULL;

    raiz = reconstroiArv();

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
                raiz = remover(raiz);
                break;
            case 3:
                imprimir(raiz);
                break;
            case 4:
                menuImprimirIntervalo(raiz);
                break;
            case 5:
                printf("Saindo...\n");
                rodando = FALSE;
                break;
            default:
                break;  
        }

    }
}