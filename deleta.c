#include "headers.h"

No *deletar(No *arv, int chave)
{
    No *folha = NULL;

    // Busca o paciente e a pagina a quem ele pertence
    Paciente *p = busca(chave, arv, &folha);

    // Se o paciente existir, deleta
    if (p != NULL && folha != NULL) {
        // Remove ele da arvore
        arv = deletaNo(arv, folha, chave, p);

        // Libera o paciente
        deletaArquivo(p->id);
        /* free(p); */
    }    

    return arv;
}

No *deletaNo(No *arv, No *pagina, int chave, void *pont)
{
    int qtMinChaves, indiceIrmao, descida, indiceDescida, capacidade;
    No *irmao = NULL;

    // busca no a ser removido
    pagina = preparaRemocao(pagina, chave, pont);

    if (pagina == arv) return mudaRaiz(arv); 

    // Quantidade minima em um pagina | (ORDEM/2) - 1
    qtMinChaves = pagina->folha ? tetoDaMetade(ORDEM -1) : tetoDaMetade(ORDEM) -1;

    // Se a página não fere a regra de quantidade minima de chaves, retorna a arvore
    if (pagina->quantChaves >= qtMinChaves) return arv;
    
    // Busca o indice do irmao
    indiceIrmao = buscaIndiceIrmao(pagina);

    // Se o indiceIrmao for negativo, é porque nosso nó é o primeiro filho do pai
    indiceDescida = (indiceIrmao == -1) ? 0 : indiceIrmao;
    descida = pagina->pai->chaves[indiceDescida];
    // recupera o irmão (de preferencia o irmao à esquerda)
    irmao = (indiceIrmao == -1) ? pagina->pai->ponts[1] : pagina->pai->ponts[indiceIrmao];

    capacidade = pagina->folha ? ORDEM : (ORDEM - 1);

    // verifica se pode concatenar o no e seu irmao
    if (irmao->quantChaves + pagina->quantChaves < capacidade)
        return concatenar(arv, pagina, irmao, indiceIrmao, descida);

    // Se não for possível concatenar, redistribui as chaves
    return redistribuicao(arv, pagina, irmao, indiceIrmao, indiceDescida, descida);
}

No *redistribuicao(No *arv, No *n, No *irmao, int indiceIrmao, int indiceDescida, int descida) {
  int i = 0;
  No *aux;

  if (indiceIrmao != -1) {

    if (!n->folha) n->ponts[n->quantChaves + 1] = n->ponts[n->quantChaves];

    // desloca as chaves e ponteiros para a direita
    for (i = n->quantChaves; i > 0; i--) {
      n->chaves[i] = n->chaves[i - 1];
      n->ponts[i] = n->ponts[i - 1];
    }

    // troca as posicoes de ponteiros para quando iremos deletar a primeira ocorrencia na pagina
    if (!n->folha) {
      n->ponts[0] = irmao->ponts[irmao->quantChaves];
      aux = (No *)n->ponts[0];
      aux->pai = n;
      irmao->ponts[irmao->quantChaves] = NULL;
      n->chaves[0] = descida;
      n->pai->chaves[indiceDescida] = irmao->chaves[irmao->quantChaves - 1];
    } 
    else {
      n->ponts[0] = irmao->ponts[irmao->quantChaves - 1];
      irmao->ponts[irmao->quantChaves - 1] = NULL;
      n->chaves[0] = irmao->chaves[irmao->quantChaves - 1];
      n->pai->chaves[indiceDescida] = n->chaves[0];
    }

  }
  else {
    // troca as posicoes de ponteiros
    if (n->folha) {
      n->chaves[n->quantChaves] = irmao->chaves[0];
      n->ponts[n->quantChaves] = irmao->ponts[0];
      n->pai->chaves[indiceDescida] = irmao->chaves[1];
    } 
    else {
      n->chaves[n->quantChaves] = descida;
      n->ponts[n->quantChaves + 1] = irmao->ponts[0];
      aux = (No *)n->ponts[n->quantChaves + 1];
      aux->pai = n;
      n->pai->chaves[indiceDescida] = irmao->chaves[0];
    }

    // realoca o vetor
    for (i = 0; i < irmao->quantChaves - 1; i++) {
      irmao->chaves[i] = irmao->chaves[i + 1];
      irmao->ponts[i] = irmao->ponts[i + 1];
    }

    if (!n->folha) irmao->ponts[i] = irmao->ponts[i + 1];
  }

  n->quantChaves++;
  irmao->quantChaves--;

  return arv;
}

No *concatenar(No *arv, No *pagina, No *irmao, int indiceIrmao, int descida) {
    int i, j, indiceDeInsercao, ultimaPos;
    No *aux;

    // Se a chave for a primeira, iremos fazer uma troca com seu irmão a direita
    if (indiceIrmao == -1) {
        aux = pagina;
        pagina = irmao;
        irmao = aux;
    }

    // indice de inserção vai ser o ultimo
    indiceDeInsercao = irmao->quantChaves;

    if (!pagina->folha) {
        // irmao recebe a chave da descida
        irmao->chaves[indiceDeInsercao] = descida;
        irmao->quantChaves++;

        ultimaPos = pagina->quantChaves;

        // insere os elementos da pagina no irmao de i+1 ate a ultima posicao
        for (i = indiceDeInsercao + 1, j = 0; j < ultimaPos; i++, j++) {
            irmao->chaves[i] = pagina->chaves[j];
            irmao->ponts[i] = pagina->ponts[j];
            irmao->quantChaves++;
            pagina->quantChaves--;
        }

        irmao->ponts[i] = pagina->ponts[j];

        // Reorganiza os ponteiros do pai
        for (i = 0; i < irmao->quantChaves + 1; i++) {
            aux = (No *)irmao->ponts[i];
            aux->pai = irmao;
        }
    }

    else { // Se for folha
      // copia os elementos da pagina para o irmao
      for (i = indiceDeInsercao, j = 0; j < pagina->quantChaves; i++, j++) {
          irmao->chaves[i] = pagina->chaves[j];
          irmao->ponts[i] = pagina->ponts[j];
          irmao->quantChaves++;
      }

      irmao->ponts[ORDEM - 1] = pagina->ponts[ORDEM - 1];
    }

    // Recursão para o pai
    arv = deletaNo(arv, pagina->pai, descida, pagina);

    free(pagina->chaves);
    free(pagina->ponts);
    free(pagina);

    return arv;
}

No *preparaRemocao(No *n, int chave, No *pont) {
    int i = 0;

    // procura a chave a ser removida (indice)
    while (n->chaves[i] != chave) i++;

    // copia as chaves para a esquerda
    for (++i; i < n->quantChaves; i++) n->chaves[i - 1] = n->chaves[i];

    // calcula quantidade de filhos
    int quantPonts = n->folha ? n->quantChaves : n->quantChaves + 1;
    
    // procura o indice do ponteiro
    i = 0;
    while (n->ponts[i] != pont) i++;

    // copia os ponteiros para a esquerda
    for (++i; i < quantPonts; i++) n->ponts[i - 1] = n->ponts[i];

    // ja que iremos remover uma chave, decrementa a quantidade de chaves
    n->quantChaves--;

    // reseta os ponteiros
    if (n->folha) {
        for (i = n->quantChaves; i < ORDEM - 1; i++) n->ponts[i] = NULL;
    }
    else {
        for (i = n->quantChaves + 1; i < ORDEM; i++) n->ponts[i] = NULL;
    }
        
    return n;
}

int buscaIndiceIrmao(No *no) {
    // Percorre todo os elementos do pai até encontrar o ponteiro para o nó
    // e retorna sua posição -1 (irmão a esquerda do nó)
    for (int i = 0; i <= no->pai->quantChaves; i++)
    {
        if (no->pai->ponts[i] == no) return (i - 1);
    }

    exit(0);
  }

No *mudaRaiz(No *arv) {
    No *novaRaiz;

    // se a raiz não estiver vazia, retorna a raiz
    if (arv->quantChaves > 0) return arv;

    // se a raiz nao for folha, a nova raiz vai ser seu primeiro filho, se for folha NULL
    if (!arv->folha) {
      novaRaiz = arv->ponts[0];
      novaRaiz->pai = NULL;
    }
    else novaRaiz = NULL;

    free(arv->chaves);
    free(arv->ponts);
    free(arv);

    return novaRaiz;
}