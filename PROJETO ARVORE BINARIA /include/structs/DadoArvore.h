typedef struct DadoArvore {
    evento dado;
    time_t timestamp;
    struct DadoArvore *esquerda;
    struct DadoArvore *direita;
} dadoArvore;

typedef dadoArvore *arvore;


