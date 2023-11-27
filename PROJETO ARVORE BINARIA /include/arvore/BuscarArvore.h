// Adiciona novo no no inicio da lista.
void adicionaInicioLista(arvore minhaRaiz, dadoAgenda **arvoreLista) {
    if (minhaRaiz != NULL) {
        dadoAgenda *novoNo = criarNovoNo(minhaRaiz);

        if (*arvoreLista == NULL) {
            *arvoreLista = novoNo;
        } else {
            novoNo->direita = *arvoreLista;
            novoNo->esquerda = NULL;
            (*arvoreLista)->esquerda = novoNo;
            *arvoreLista = novoNo;
        }
    }
}

// Cria a lista encadeada.
dadoAgenda* criaListaBusca(arvore minhaRaiz, dadoAgenda *listaResultado) {
    adicionaInicioLista(minhaRaiz, &listaResultado);
    return listaResultado;
}


// Função para realizar uma busca específica na árvore e criar uma lista encadeada com os resultados.
dadoAgenda* buscaEspecificaArvore(arvore minhaRaiz, dadoAgenda *listaResultado, struct tm dado, int selecao) {
    
    if (minhaRaiz == NULL) {
        return listaResultado;
    }

    struct tm dataConvertida = converteTimestamp(minhaRaiz->timestamp);
    time_t dadoConvertido = mktime(&dado);
    double diff = difftime(dadoConvertido, minhaRaiz->timestamp);

    listaResultado = buscaEspecificaArvore(minhaRaiz->esquerda, listaResultado, dado, selecao);

    switch (selecao) {
        case BUSCA_DIA:
            if (labs(diff) < TOLERANCIA) {
                listaResultado = criaListaBusca(minhaRaiz, listaResultado);
            }
            break;
        case BUSCA_ANO:
            if (dataConvertida.tm_year == dado.tm_year) {
                listaResultado = criaListaBusca(minhaRaiz, listaResultado);
            }
            break;
        case BUSCA_MES:
            if (dataConvertida.tm_mon == dado.tm_mon && dataConvertida.tm_year == dado.tm_year) {
                listaResultado = criaListaBusca(minhaRaiz, listaResultado);
            }
            break;
    }
    
    listaResultado = buscaEspecificaArvore(minhaRaiz->direita, listaResultado, dado, selecao);
  

    return listaResultado;
}

