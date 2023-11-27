
arvore removerNo(arvore minhaRaiz, struct tm dado) {
    if (minhaRaiz == NULL) {
        return NULL;
    }
    time_t timestampDado = mktime(&dado);
    // Se a data e hora do nó atual for maior que a data e hora do dado, vá para a subárvore esquerda
    if ((timestampDado - minhaRaiz->timestamp) < 0) {
        minhaRaiz->esquerda = removerNo(minhaRaiz->esquerda, dado);
    }
    // Se a data e hora do nó atual for menor que a data e hora do dado, vá para a subárvore direita
    else if ((timestampDado - minhaRaiz->timestamp) > 0) {
        minhaRaiz->direita = removerNo(minhaRaiz->direita, dado);
    }
    // Se encontramos o nó a ser removido
    else {
        // Caso 1: Nó sem filhos ou com apenas um filho
        if (minhaRaiz->esquerda == NULL) {
            arvore temp = minhaRaiz->direita;
            free(minhaRaiz);
            return temp;
        } else if (minhaRaiz->direita == NULL) {
            arvore temp = minhaRaiz->esquerda;
            free(minhaRaiz);
            return temp;
        }
        // Caso 2: Nó com dois filhos
        arvore temp = menorNo(minhaRaiz->esquerda); // Encontrar o sucessor in-order
        minhaRaiz->dado = temp->dado;
        minhaRaiz->timestamp = temp->timestamp;
        minhaRaiz->direita = removerNo(minhaRaiz->direita, temp->dado->data);
    }
    return minhaRaiz;
}
