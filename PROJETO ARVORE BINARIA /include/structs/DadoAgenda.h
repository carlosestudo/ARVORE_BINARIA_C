
typedef struct DadoAgenda{
    char *nome;
    struct tm data;
    struct tm hora;  
    struct DadoAgenda *esquerda;
    struct DadoAgenda *direita;   
} dadoAgenda;

typedef dadoAgenda *evento;