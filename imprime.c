#include "headers.h"

void imprimeArvore(No *arv, int nivel)
{
    if (arv == NULL)
        return;

    int i = 0;
  
    for (i = arv->quantChaves-1; i >= 0 ; i--) {

        printf("Chave: %d | Nivel: %d | i: %d\n", arv->chaves[i], nivel, i);
        // printf("%d | %d\n", arv->chaves[i + 1], nivel);

        for (int j = 0; j < nivel; j++) {
            printf("    \n");
        }

        // printf("%d\n", arv->chaves[i]); 
    }

    imprimeArvore(arv->ponts[i+1], nivel + 1);
}