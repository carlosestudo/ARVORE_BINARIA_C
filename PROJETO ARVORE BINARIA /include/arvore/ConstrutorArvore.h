// Função para criar um novo nó da árvore
dadoArvore* criaNo(evento dado) {
    dadoArvore* novoNo = (dadoArvore*)malloc(sizeof(dadoArvore));
    if (novoNo != NULL) {
        novoNo->dado = dado;
        novoNo->timestamp = mktime(&dado->data);  
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

// Função auxiliar para construir a árvore binária de busca.
dadoArvore* construtorArvore(dadoArvore* minhaRaiz, dadoArvore* novoNo) {

    if (minhaRaiz == NULL) {
        return novoNo;
    }

    double diff = difftime(novoNo->timestamp, minhaRaiz->timestamp);

    if (diff < 0) {
        minhaRaiz->esquerda = construtorArvore(minhaRaiz->esquerda, novoNo);
    } else if (diff > 0) {
        minhaRaiz->direita = construtorArvore(minhaRaiz->direita, novoNo);
    } else {  
        printf("Erro: Nó com timestamp igual encontrado\n");
    }

    return minhaRaiz;
}

// Função para criar uma árvore binária de busca com base nos dados de um evento.
arvore criarArvore(arvore minhaArvore, evento dado) {
    return construtorArvore(minhaArvore, criaNo(dado));
}