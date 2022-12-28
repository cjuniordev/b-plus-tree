#include "headers.h"

// Busca e retorna uma página folha que pode conter a chave
No *buscaPaginaFolha(int chave, No *arv)
{
    // TODO: use this logic to implement print function
    if (arv == NULL)
        return NULL;

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
        aux = aux->ponts[i];
    }

    return aux;
}

// Busca uma chave na arvore e o retorna, caso exista
Paciente *busca(int chave, No *arv)
{
    if (arv == NULL)
        return NULL;

    // Encontrar a página folha
    No *pagina = NULL;
    pagina = buscaPaginaFolha(chave, arv);

    int i = 0;
    
    //  Percorre toda a página até acabarem as chaves ou 
    //  encontrar uma chave menor ou igual a chave que buscamos
    while (i < pagina->quantChaves && chave > pagina->chaves[i]) {
        i++;
    }

    if (i >= pagina->quantChaves) return NULL;
    if (pagina->chaves[i] != chave) return NULL;
    
    return (Paciente*)pagina->ponts[i];
}