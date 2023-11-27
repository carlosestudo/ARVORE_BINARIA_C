arvore deletarEventoAPP(arvore *minhaRaiz){
   
    // Inicializa uma estrutura tm para armazenar a data do evento a ser removido.
    struct tm dado; 
    // evita lixo de memoria na struct tm
        dado.tm_hour = 0;
        dado.tm_min = 0;
        dado.tm_sec = 0;
    printf("\n====== DELETAR EVENTO =====\n");
    printf("\nDigite a data dd/mm/yyyy: ");
    scanf("%d/%d/%d", &dado.tm_mday, &dado.tm_mon, &dado.tm_year);    
    printf("%d/%d/%d",  dado.tm_mday, dado.tm_mon, dado.tm_year );
    dado.tm_mon--;  
    dado.tm_year -= 1900; 

    // Chama a função para remover o evento da árvore.
    minhaRaiz = removerNo(minhaRaiz,dado); 
               
    if(minhaRaiz != NULL){
        printf("\n\n===== EVENTO REMOVIDO COM SUCESSO =====");
    }else{
        printf("\n\nISSO NÃO ERA PARA ACONTECER!!!");
    } 
    
    // Retorna a raiz da árvore após a remoção do evento.
    return minhaRaiz; 
}