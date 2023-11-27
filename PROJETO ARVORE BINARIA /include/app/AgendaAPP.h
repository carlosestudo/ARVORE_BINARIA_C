
arvore menuPrincipal(arvore *minhaRaiz, int** PtrContadorBalanceamento, struct tm* infoTempo){

    evento meuEvento = NULL;
    int selecao = 0;
   
    // Exibe o menu, e mostra as opções dinamicamente.
    exibirMenu(opcoesListarMenu, sizeof(opcoesListarMenu) / sizeof(OpcaoMenu));
    scanf("%i", &selecao);

    do{
        switch(selecao){
            case 1:
                limparBuffer();
                printf("\n========== NOVO EVENTO ==========\n");
                meuEvento = adicionaEvento(meuEvento, infoTempo);// Chama a função para adicionar um novo evento
                minhaRaiz = criarArvore(minhaRaiz, meuEvento);// Adiciona o evento à árvore

                if(minhaRaiz != NULL){
                    printf("\n\n===== EVENTO ADICIONADO COM SUCESSO =====\n\n");                   
                    (**PtrContadorBalanceamento)++; // Atualiza o contador de balanceamento da árvore (que vai até 5)
                }
                break;
            case 2:
                limparBuffer();
                exibirMenu(opcoesListarEventos, sizeof(opcoesListarEventos) / sizeof(OpcaoMenu));
                scanf("%i", &selecao);
                
                switch(selecao){

                    case 1: 
                        printf("\n====== LISTA DE EVENTOS =====\n");
                        exibirEvento(minhaRaiz);                                                
                        break;
                    case 2:
                        printf("\n====== EVENTOS DO DIA =====\n");
                        buscaEventos(minhaRaiz, BUSCA_DIA, infoTempo);
                        break;
                    case 3:
                        printf("\n====== EVENTOS DO MES =====\n");
                        buscaEventos(minhaRaiz, BUSCA_MES, infoTempo);
                        break;
                    case 4:
                        printf("\n====== EVENTOS DO ANO =====\n");
                        buscaEventos(minhaRaiz, BUSCA_ANO, infoTempo);
                    case 0:
                        break;
                    default:
                        printf("algo deu errado");
                    break; 
                    
                }
                break;
            case 3:
                deletarEventoAPP(minhaRaiz);
                break;
            case 0:
                // UTILIZA O BREAK PARA SAIR DO LOOP
                break;
            default:
                printf("\nALGO DEU ERRADO NO CASE MENU PRINCIPAL");
                break;
        }
    }while(selecao == 0);
    
    // Retorna a raiz da árvore após as operações do menu
    return minhaRaiz;
}



