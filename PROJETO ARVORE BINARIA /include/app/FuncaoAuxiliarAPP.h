//limpa buffer de memoria
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para mostrar o menu.
void exibirMenu(OpcaoMenu opcoes[], int numOpcoes) {
   
    for (int i = 0; i < numOpcoes; i++) {
        
        if(opcoes[i].codigo == CABECALHO_MENU){
            printf("\n========= %s =========\n", opcoes[i].descricao);
        }else if(opcoes[i].codigo == ENCERRA){

            printf("0 -> %s\n", opcoes[i].descricao);

        }else{
            printf("%d -> %s\n", opcoes[i].codigo, opcoes[i].descricao);
        }
    }     
    printf("======================================\n");
    printf("SELECIONE: ");
}

// Função para exibir o evento.
void exibirLista(dadoAgenda *listaResultado){

    while(listaResultado != NULL){

        printf("\n||======================================||\n");
        printf("||          Detalhes do Evento          ||\n");
        printf("||======================================||\n");

        // Exibe os detalhes do evento
        printf("   Evento: %s\n", listaResultado->nome);
        printf("   Data: %02d/%02d/%04d\n", listaResultado->data.tm_mday, listaResultado->data.tm_mon + 1, listaResultado->data.tm_year + 1900);
        printf("   Hora: %02d:%02d\n", listaResultado->hora.tm_hour, listaResultado->hora.tm_min);

        printf("||======================================||\n");

        listaResultado = listaResultado->direita;
    }
}