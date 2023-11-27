evento adicionaEvento(evento meuEvento, struct tm* infoTempo) {
   
    // Aloca memória para a estrutura evento
    meuEvento = (evento)malloc(sizeof(dadoAgenda)); // Aloca memória para a estrutura evento
    
    // Recebe o nome do evento e aloca.
    printf("Digite o nome do evento: ");
    meuEvento->nome = malloc(100); 
    fgets(meuEvento->nome, 100, stdin);
    meuEvento->nome[strlen(meuEvento->nome) - 1] = '\0';

    // Recebe a data do evento e aloca.
    printf("Digite a data do evento (dd/mm/aaaa): ");
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    meuEvento->data.tm_mday = dia;
    meuEvento->data.tm_mon = mes - 1;
    meuEvento->data.tm_year = ano - 1900;


    // Recebe a hora do evento e aloca.
    printf("Digite a hora do evento (hh:mm): ");
    int hora, minuto;
    scanf("%d:%d", &hora, &minuto);
    meuEvento->hora.tm_hour = hora;
    meuEvento->hora.tm_min = minuto;
    

    meuEvento->data.tm_hour = 0;
    meuEvento->data.tm_min = 0;
    meuEvento->data.tm_sec = 0;

    // Limpa buffer de momoria
    limparBuffer();

    return meuEvento;
}