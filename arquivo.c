#include "headers.h"

void leArquivo()
{
    Paciente p;
    FILE *arq = fopen("bin/arvore.bin", "r");
      
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    while (fread(&p, sizeof(Paciente), 1, arq))
        imprimePacienteArquivo(p);

    fclose(arq);
}

void insereArquivo(Paciente *p)
{
    FILE *arq = fopen("bin/arvore.bin", "ab+");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    fwrite(p, sizeof(Paciente), 1, arq);
    fclose(arq);
}