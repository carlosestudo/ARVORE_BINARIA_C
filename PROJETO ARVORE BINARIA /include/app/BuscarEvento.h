
void buscaEventos(arvore minhaRaiz, int selecao, struct tm* infoTempo){

    // Inicializa a lista para armazenar os resultados da busca.
    dadoAgenda *listaResultado = NULL;
    struct tm dado;
        dado.tm_mday = 1; 
        dado.tm_mon = 1;
        dado.tm_hour = 0;
        dado.tm_min = 0;
        dado.tm_sec = 0;

    switch(selecao){

        case BUSCA_DIA:
            printf("%d", infoTempo->tm_mon);
            printf("\nDigite o dia dd: ");
            scanf("%d", &dado.tm_mday);  
            dado.tm_mon = infoTempo->tm_mon;  
            dado.tm_year = infoTempo->tm_year;        
            listaResultado = buscaEspecificaArvore(minhaRaiz, listaResultado,dado, BUSCA_DIA); 
            break;
        case BUSCA_MES:
            printf("\nDigite o mês e o ano mm/yyyy: ");
            scanf("%d/%d", &dado.tm_mon, &dado.tm_year);
            dado.tm_year -= 1900; // ajusta o ano para struct tm
            listaResultado = buscaEspecificaArvore(minhaRaiz, listaResultado, dado, BUSCA_MES); 
            break;
        case BUSCA_ANO:
            printf("\nDigite o ano yyyy: ");
            scanf("%d", &dado.tm_year);
            dado.tm_year -= 1900;
            listaResultado = buscaEspecificaArvore(minhaRaiz, listaResultado, dado, BUSCA_ANO); 
            break;
        default:
            printf("\nNo proximo sistema pretendo desenvolver um .h para retornar erros\n");
        break; 
    }

    if(listaResultado != NULL){
        exibirLista(listaResultado);
    }else{
        printf("===== DATA NÃO CONSTA NA LISTA =====");
    }
        

}