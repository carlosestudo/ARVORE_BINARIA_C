typedef struct {
    int codigo;
    char descricao[100];
} OpcaoMenu;

OpcaoMenu opcoesListarMenu[] = {
    {CABECALHO_MENU,"MENU INICIAL"},
    {1, "ADICIONAR EVENTO"},
    {2, "CONSULTAR EVENTO"},
    {3, "DELETAR EVENTO"},
    {ENCERRA, "Sair"}  
};

OpcaoMenu opcoesListarEventos[] = {
    {CABECALHO_MENU,"CONSULTAR EVENTOS"},
    {1, "TODOS OS EVENTOS REGISTRADOS"},
    {2, "EVENTOS DO DIA"},
    {3, "EVENTOS DO MES"},
    {4, "EVENTO DO ANO"},
    {ENCERRA, "VOLTAR"}
};

