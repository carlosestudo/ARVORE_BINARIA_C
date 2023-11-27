// Calcula a altura da arvore
int altura(arvore minhaArvore) {
    if (minhaArvore == NULL) {
        return 0;
    }

    int alturaEsquerda = altura(minhaArvore->esquerda);
    int alturaDireita = altura(minhaArvore->direita);

    // A altura do nó é o máximo entre a altura da subárvore esquerda e direita + 1
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

// Calcula o fator de balanceamento
int balanceamento(arvore minhaArvore) {
    if (minhaArvore == NULL) {
        return 0;
    }

    int alturaEsquerda = altura(minhaArvore->esquerda);
    int alturaDireita = altura(minhaArvore->direita);

    // Retorna a diferença de altura entre a subárvore esquerda e direita
    return alturaEsquerda - alturaDireita;
}

// Encontra o nó do meio da lista.
dadoAgenda* encontrarMeio(dadoAgenda* listaArvore) {
    if (listaArvore == NULL) {
        return NULL;
    }

    dadoAgenda* rapido = listaArvore;
    dadoAgenda* lento = listaArvore;

    // Avançar o ponteiro "rapido" duas vezes mais rápido que o ponteiro "lento"
    while (rapido != NULL && rapido->direita != NULL) {
        rapido = rapido->direita->direita;
        lento = lento->direita;
    }
    return lento;
}

// Copia os dados da arvore para mandar pra lista.
dadoAgenda* criarNovoNo(arvore minhaRaiz) {  
    dadoAgenda *novoNo = (dadoAgenda *)malloc(sizeof(dadoAgenda));
    novoNo->nome = minhaRaiz->dado->nome;
    novoNo->data = minhaRaiz->dado->data;
    novoNo->hora = minhaRaiz->dado->hora;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Cria a lista com os elementos da arvore com os dados copiados
void adicionaListaEmOrdem(arvore minhaRaiz, dadoAgenda **arvoreLista) {
    if (minhaRaiz != NULL) {
        adicionaListaEmOrdem(minhaRaiz->direita, arvoreLista);

        dadoAgenda *novoNo = criarNovoNo(minhaRaiz);

        if (*arvoreLista == NULL) {
            *arvoreLista = novoNo;
        } else {
            novoNo->direita = *arvoreLista;
            novoNo->esquerda = NULL;
            (*arvoreLista)->esquerda = novoNo;
            *arvoreLista = novoNo;
        }

        adicionaListaEmOrdem(minhaRaiz->esquerda, arvoreLista);
    }
}

// Retorna a lista já encadeada.
dadoAgenda* criaListaEventosOrdem(arvore minhaRaiz) {
    dadoAgenda *arvoreLista = NULL;
    adicionaListaEmOrdem(minhaRaiz, &arvoreLista);
    return arvoreLista;
}

// Realiza o balanceamento da arvore.
arvore* balancearArvore(arvore minhaRaiz){

    dadoAgenda *lista = criaListaEventosOrdem(minhaRaiz);
    dadoAgenda *meio = encontrarMeio(lista);
    liberarArvore(minhaRaiz);
    minhaRaiz = NULL;

    dadoAgenda *intermediaria = meio->direita; 

    while (meio != NULL) {
        minhaRaiz = criarArvore(minhaRaiz, meio);
        meio = meio->esquerda;
    }

    while (intermediaria != NULL) {
        minhaRaiz = criarArvore(minhaRaiz, intermediaria);
        intermediaria = intermediaria->direita;
    }


    return minhaRaiz;

}
