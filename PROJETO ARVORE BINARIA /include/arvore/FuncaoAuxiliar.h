
// execulta converções
struct tm converteTimestamp(time_t timestamp) {
    return *localtime(&timestamp);
}


// busca o menor no da arvore
arvore menorNo(arvore no) {
    arvore atual = no;

    while (atual->direita != NULL) {
        atual = atual->direita;
    }

    return atual;
}

//libera a arvore
void liberarArvore(arvore minhaRaiz) {
    
    if (minhaRaiz == NULL) {
        return;
    }
    
    liberarArvore(minhaRaiz->esquerda);
    liberarArvore(minhaRaiz->direita);

    free(minhaRaiz);
}

//exibe evento na arvore
void exibirEvento(arvore minhaArvore) {
    if (minhaArvore != NULL) {
        exibirEvento(minhaArvore->esquerda);
    
        printf("\n||======================================||\n");
        printf("||          Detalhes do Evento          ||\n");
        printf("||======================================||\n");
        printf("   Evento: %s\n", minhaArvore->dado->nome);
        printf("   Data: %02d/%02d/%04d\n", minhaArvore->dado->data.tm_mday, minhaArvore->dado->data.tm_mon + 1, minhaArvore->dado->data.tm_year + 1900);
        printf("   Hora: %02d:%02d\n", minhaArvore->dado->hora.tm_hour, minhaArvore->dado->hora.tm_min);
        printf("||======================================||\n");       
        exibirEvento(minhaArvore->direita);
    }
}

