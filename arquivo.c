#include "headers.h"

/* Função que "deleta" paciente em disco */
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

/* Função que insere paciente em disco */
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

/* Função que reconstroi a árvore a partir do arquivo */
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