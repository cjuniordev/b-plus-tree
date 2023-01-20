#include "headers.h"

// Busca e retorna uma página folha que pode conter a chave
No *buscaPaginaFolha(int chave, No *arv)
{
    if (arv == NULL)
        return arv;

    No *aux = arv;

    // Enquanto não for folha
    while (aux->folha == FALSE) {
        int i = 0;
        // Percorre todo o vetor de chaves
        while(i < aux->quantChaves) {
            if (chave < aux->chaves[i]) break;
            
            i++;
        }

        // vai para a próxima página
        aux = (No *)aux->ponts[i];
    }

    return aux;
}

// Busca uma chave na arvore e o retorna, caso exista
Paciente *busca(int chave, No *arv, No **paginaFolha)
{
    if (arv == NULL) {
        if (paginaFolha != NULL) {
            (*paginaFolha) = NULL;
        }   
        return NULL;
    }

    // Encontrar a página folha
    No *pagina = buscaPaginaFolha(chave, arv);

    int i = 0;
    
    //  Percorre toda a página até acabarem as chaves ou 
    //  encontrar uma chave menor ou igual a chave que buscamos
    for (i = 0; i < pagina->quantChaves; i++) {
        if (pagina->chaves[i] == chave) break;
    }

    if (paginaFolha != NULL) {
        (*paginaFolha) = pagina;
    }   

    if (i == pagina->quantChaves) return NULL;
    
    return (Paciente*)pagina->ponts[i];
}

int buscaIntervalo(No *arv, int inicio, int fim, int chaves[], void *ponts[])
{
    int quantidade = 0;

    No *no = buscaPaginaFolha(inicio, arv);

    imprimeArvore(arv);
    
    /* Se não encontra o nó, não existe intervalo */
    if (no == NULL) return 0;

    int i = 0;

    /* Percorre toda a página até encontrara a posição em que se encontra a chave que buscamos */
    while (i < no->quantChaves && no->chaves[i] < inicio) {
        i++;
    }
    
    /* Se a posição execede o tamanho da pagina, encerra  */
    if (i == no->quantChaves) return 0;

    while (no != NULL) {
        /* Percorre todo o resto do página até encontrar o fim e incrementa a quantidade de itens no intervalo */      
        while(i < no->quantChaves && no->chaves[i] <= fim) {
            chaves[quantidade] = no->chaves[i];
            ponts[quantidade] = no->ponts[i];
            quantidade++;
            i++;
        }

        /* Vai para a próxima página e zera o iterador */
        no = no->ponts[ORDEM - 1];

        i = 0;
    }

    return quantidade;
}
