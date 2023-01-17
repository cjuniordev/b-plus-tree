#include "headers.h"

void leArquivo()
{
    Paciente p;
    FILE *arq = fopen("bin/arvore.bin", "rb+");
      
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    while (fread(&p, sizeof(Paciente), 1, arq))
        imprimePacienteArquivo(p);

    fclose(arq);
}

void deletaArquivo(int id)
{
    FILE *arq = fopen("bin/arvore.bin", "rb+");
    Paciente p;

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    int i = 0;

    while (fread(&p, sizeof(Paciente), 1, arq)) {
        if (p.id == id) {
            fseek(arq, sizeof(Paciente) * i, SEEK_SET);

            p.deletado = TRUE;        
            fwrite(&p, sizeof(Paciente), 1, arq);
        };

        i++;
    }
    

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

No *reconstroiArv()
{
    Paciente p;
    FILE *arq = fopen("bin/arvore.bin", "rb");
    No *arv = NULL;
      
    if (arq == NULL) {
        return arv;
    }

    while(fread(&p, sizeof(Paciente), 1, arq) == 1)
    {
        if (!p.deletado)  {
            arv = insere(arv, &p, TRUE);   
        }
    }

    fclose(arq);

    return arv;
}