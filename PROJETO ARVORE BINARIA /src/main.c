
#define TOLERANCIA 3600

#define CABECALHO_MENU 100
#define ENCERRA 200

#define BUSCA_DIA 1
#define BUSCA_MES 2
#define BUSCA_ANO 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "../include/structs/DadoAgenda.h"
#include "../include/structs/DadoArvore.h"
#include "../include/structs/OpcoesMenu.h"
#include "../include/app/FuncaoAuxiliarAPP.h"
#include "../include/arvore/FuncaoAuxiliar.h"
#include "../include/arvore/ConstrutorArvore.h"
#include "../include/arvore/BalanceadorArvore.h"
#include "../include/arvore/BuscarArvore.h"
#include "../include/arvore/RemoverArvore.h"
#include "../include/app/BuscarEvento.h"
#include "../include/app/DeletarEventoAPP.h"
#include "../include/app/AdicionaEvento.h"
#include "../include/app/AgendaAPP.h"



int main() {
 
    arvore *minhaArvore = NULL; 
    int contadorBalanceamento = 0;
    int* PtrContadorBalanceamento = &contadorBalanceamento;

    // Obtém hora e data do sistema
    time_t t;
    time(&t);
    struct tm* infoTempo = localtime(&t);


    // incere alguns eventos para teste
    evento meusEventos[] = {
        &(dadoAgenda) {.nome = "Reunião com o Café", .data = {.tm_year = 123, .tm_mon = 10, .tm_mday = 13, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 4, .tm_min = 04, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Conversa Animada com o Teclado", .data = {.tm_year = 123, .tm_mon = 10, .tm_mday = 13, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 12, .tm_min = 30, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Dança do Mouse", .data = {.tm_year = 123, .tm_mon = 10, .tm_mday = 14, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 18, .tm_min = 0, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Discussão entre Arquivos", .data = {.tm_year = 123, .tm_mon = 11, .tm_mday = 15, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 9, .tm_min = 45, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Aventuras da Caneta Fugitiva", .data = {.tm_year = 123, .tm_mon = 11, .tm_mday = 17, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 21, .tm_min = 5, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Treinamento de Papel Higiênico", .data = {.tm_year = 124, .tm_mon = 11, .tm_mday = 18, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 7, .tm_min = 15, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Conspiração dos Grampos", .data = {.tm_year = 124, .tm_mon = 11, .tm_mday = 19, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 14, .tm_min = 50, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Desfile dos Ícones", .data = {.tm_year = 124, .tm_mon = 11, .tm_mday = 20, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 23, .tm_min = 30, .tm_sec = 0}},
        &(dadoAgenda) {.nome = "Entrevista com a Lixeira",.data = {.tm_year = 124, .tm_mon = 11, .tm_mday = 21, .tm_hour = 0, .tm_min = 0, .tm_sec = 0}, .hora = {.tm_hour = 5, .tm_min = 10, .tm_sec = 0}},
       
    };

    size_t tamanhoArray = sizeof(meusEventos) / sizeof(meusEventos[0]);

    for (size_t i = 0; i < tamanhoArray; i++){
        arvore novoNo = criaNo(meusEventos[i]);
        minhaArvore = construtorArvore(minhaArvore,novoNo);
    }

    minhaArvore = balancearArvore(minhaArvore);
       
        while(1){
           minhaArvore = menuPrincipal(minhaArvore, &PtrContadorBalanceamento, infoTempo);
            if(contadorBalanceamento >= 5){
                minhaArvore = balancearArvore(minhaArvore);
                contadorBalanceamento = balanceamento(minhaArvore);
            }
        }
        liberarArvore(minhaArvore);

   
    return 0;
}
 