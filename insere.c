 #include "headers.h"

No *insereFolha(No *pagina, Paciente *novo)
{
    int indice = 0; // indice que indica onde deverá ocorrer a inserção

    // Percorre vetor até encontar sua posição
    while (indice < pagina->quantChaves && pagina->chaves[indice] < novo->id)
        indice++;

    // Desloca as posições para a nova chave ser inserida
    for (int i = pagina->quantChaves; i > indice; i--) {
        pagina->chaves[i] = pagina->chaves[i - 1];
        pagina->ponts[i] = pagina->ponts[i - 1];
    }    

    // Como deslocamos as chaves para a direita, a posição 'indice' estará 'vazia'
    pagina->chaves[indice] = novo->id;
    pagina->ponts[indice] = novo;
    pagina->quantChaves++;

    insereArquivo(novo);

    return pagina;
}

No *inserePai(No *arv, No *folha, No *novaFolha, int chavePromovida)
{
    No *novoPai = folha->pai;

    if (novoPai == NULL) {
        No *novaRaiz = criaNo();
        folha->pai = novaRaiz;
        novaFolha->pai = novaRaiz;
        novaRaiz->chaves[0] = chavePromovida;
        novaRaiz->quantChaves++;
        novaRaiz->ponts[0] = folha;
        novaRaiz->ponts[1] = novaFolha;
        return novaRaiz;
    }

    /* Percorre a página pai até achar o indíce em que o filho à esquerda deve ser inserido */
    int indiceAEsquerda = 0;
    while (indiceAEsquerda <= novoPai->quantChaves && novoPai->ponts[indiceAEsquerda] != folha)
        indiceAEsquerda++;

    /* Se após a cisão não houve infração de limites, somente insere */
    if (novoPai->quantChaves < ORDEM - 1) {
        for (int i = novoPai->quantChaves; i > indiceAEsquerda; i--) {
           novoPai->ponts[i + 1] = novoPai->ponts[i];
           novoPai->chaves[i] = novoPai->chaves[i - 1];
        }
        novoPai->ponts[indiceAEsquerda + 1] = novaFolha;
        novoPai->chaves[indiceAEsquerda] = chavePromovida;
        novoPai->quantChaves++;
        return novoPai;
    }

    /* Se não, realiza mais uma cisão */
    return cisaoInterna(arv, novoPai, novaFolha, indiceAEsquerda, chavePromovida);
}

No *cisaoInterna(No *arv, No *pagina, No *folhaDireita, int indiceAEsquerda, int chave)
{
    int *novasChaves = malloc(ORDEM * sizeof(int));
    No **novosPonts = malloc((ORDEM + 1) * sizeof(No *));

    if (novasChaves == NULL || novosPonts == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    /* Reorganiza ordem dos ponteiros */
    for (int i = 0, j = 0; i < pagina->quantChaves + 1; i++, j++) {
        if (j == indiceAEsquerda + 1) j++;
        novosPonts[j] = pagina->ponts[i];
    }

    /* Reorganiza ordem das chaves */
    for (int i = 0, j = 0; i < pagina->quantChaves; i++, j++) {
        if (j == indiceAEsquerda) j++;
        novasChaves[j] = pagina->chaves[i];
    }

    /* Insere chave em sua posição correta e o filho a direita */
    novosPonts[indiceAEsquerda + 1] = folhaDireita;
    novasChaves[indiceAEsquerda] = chave;

    int qtChavesAposCisao = tetoDaMetade(ORDEM);
    No *novaPagina = criaNo();
    int i, j;

    /* Copia os dados para a página original */
    for (i = 0; i < (qtChavesAposCisao - 1); i++) {
        pagina->ponts[i] = novosPonts[i];
        pagina->chaves[i] = novasChaves[i];
        pagina->quantChaves++;
    }
    pagina->ponts[i] = novosPonts[i];

    int chavePromovida = novasChaves[qtChavesAposCisao - 1];

    /* Copia os dados para a nova página */
    for (++i, j = 0; i < ORDEM; i++, j++) {
        novaPagina->ponts[j] = novosPonts[i];
        novaPagina->chaves[j] = novasChaves[i];
        novaPagina->quantChaves++;
    }
    novaPagina->ponts[j] = novosPonts[i];
    novaPagina->pai = pagina->pai;

    /*  UNUSED
        No *novoFilho;
        for (i = 0; i <= novaPagina->quantChaves; i++) {
            novoFilho = novaPagina->ponts[i];
            novoFilho->pai = novaPagina;
        }
    */

    free(novosPonts);
    free(novasChaves);

    return inserePai(arv, pagina, novaPagina, chavePromovida);
}

No *cisaoNaFolha(No *arv, No *folha, Paciente *novo)
{
    No *novaPaginaFolha = criaNo(); // inicializa nova página folha
    novaPaginaFolha->folha = TRUE;

    int *novasChaves = (int*)malloc(sizeof(int) * ORDEM);
    void **novosPonts = (void**)malloc(sizeof(void*) * ORDEM);

    if (novaPaginaFolha == NULL || novasChaves == NULL || novosPonts == NULL) {
        printf("Erro na alocação.\n");
        exit(0);
    }

    /* Percorre todo array até achar uma posição vazia  */
    int indice = 0;
    while (indice < ORDEM - 1 && folha->chaves[indice] < novo->id)
        indice++;

    /* Reorganiza ordem das chaves */
    for (int i = 0, j = 0; i < folha->quantChaves; i++, j++) {
        if (j == indice) j++;
        novasChaves[j] = folha->chaves[i];
        novosPonts[j] = folha->ponts[i];
    }

    novasChaves[indice] = novo->id;
    novosPonts[indice] = novo;
    folha->quantChaves = 0;
    int qtChavesAposCisao = tetoDaMetade(ORDEM-1);

    /*  Mantem as primeiras chaves na folha original */
    for (int i = 0; i < qtChavesAposCisao; i++) {
        folha->chaves[i] = novasChaves[i];
        folha->ponts[i] = novosPonts[i];
        folha->quantChaves++;
    }

    /* Copia as chaves as ultimas chaves para a nova folha  */
    for (int i = qtChavesAposCisao, j = 0; i < ORDEM; i++, j++) {
        novaPaginaFolha->chaves[j] = novasChaves[i];
        novaPaginaFolha->ponts[j] = novosPonts[i];
        novaPaginaFolha->quantChaves++;
    }

    novaPaginaFolha->ponts[ORDEM - 1] = folha->ponts[ORDEM - 1];
    folha->ponts[ORDEM - 1] = novaPaginaFolha;

    /* Limpa os ponteiros */
    for (int i = folha->quantChaves; i < ORDEM - 1; i++)
        folha->ponts[i] = NULL;

    for (int i = novaPaginaFolha->quantChaves; i < ORDEM - 1; i++)
        novaPaginaFolha->ponts[i] = NULL;

    novaPaginaFolha->pai = folha->pai;
    int promovida = novaPaginaFolha->chaves[0];

    free(novasChaves);
    free(novosPonts);

    insereArquivo(novo);

    return inserePai(arv, folha, novaPaginaFolha, promovida);
}

No *insere(No *arv, Paciente *novo)
{
    Paciente *p = busca(novo->id, arv, NULL);

    if (p != NULL) {
        printf("Paciente já cadastrado.\n");
        return arv;
    }

    if (arv == NULL)
        return iniciaArvore(novo);

    No *paginaFolha = buscaPaginaFolha(novo->id, arv);

    // Verifica se a página não está cheia
    if (paginaFolha->quantChaves < ORDEM) {
        insereFolha(paginaFolha, novo);
        return arv;
    }

    return cisaoNaFolha(arv, paginaFolha, novo);
}

int tetoDaMetade(int numero)
{
    if (numero % 2 == 0)
        return numero / 2;

    return numero / 2 + 1;
}