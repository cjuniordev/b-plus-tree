#include "headers.h"

int main() {
    No *raiz = NULL;
    Paciente *paciente = criaPaciente(5, 1990);
    Paciente *paciente2 = criaPaciente(6, 1991);
    Paciente *paciente3 = criaPaciente(3, 1991);

    raiz = insere(raiz, paciente);
    raiz = insere(raiz, paciente2);
    raiz = insereFolha(raiz, paciente3);

    printf("%d\n", raiz->chaves[0]);

   /*  printf("%d\n", raiz->chaves[0]);
    printf("%d\n", raiz->chaves[1]); */

   /*  Paciente *p = busca(2, raiz);

    if (p == NULL)
        printf("Paciente não encontrado\n");
    else
        printf("%d\n", p->anoNascimento); */

/*     imprimeArvore(raiz, 0); */
}   