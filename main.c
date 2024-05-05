#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "matriz.h"
#include "ferramentas.h"

#define TAM_MATRIZ 50
#define TAM_VETOR 50

int main () {
    int matrizEstados[TAM_MATRIZ][TAM_MATRIZ][3];
    int estadosFinais[TAM_VETOR];
    char alfabeto[TAM_VETOR], stringFinal[TAM_VETOR];
    int tamEstadoFinal, tamAlfabeto, quantEstados;
    int linhaMatriz, colunaMatriz, estadoTransicao, posicaoAlfabetoMatriz, direcao;
    int posicaoEstado;
    char nomeArquivo[TAM_VETOR], cadeia[TAM_VETOR];
    int bool = 0;

    esvaziarMatriz(matrizEstados);
    printf("0 - Sair\n");
    printf("1 - Testar cadeia de palavras\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &bool);

    if(bool) {
        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);

        guardarEstadoFinal(estadosFinais, &tamEstadoFinal, nomeArquivo);
        guardarAlfabeto(alfabeto, &tamAlfabeto , nomeArquivo);
        guardarEstados (&quantEstados, nomeArquivo);
        montarEstruturaMatriz(matrizEstados, &linhaMatriz, &colunaMatriz, &estadoTransicao, &posicaoAlfabetoMatriz, &direcao, nomeArquivo, alfabeto);
    }
    while (bool){
        printf("Digite a cadeia de palavras: ");
        scanf("%s", cadeia);
        printf("\n");

        montarStringInicial(stringFinal, cadeia, &posicaoEstado);
        montarStringFinal(matrizEstados, stringFinal, &posicaoEstado, nomeArquivo, alfabeto, estadosFinais, tamEstadoFinal);

        printf("0 - Sair\n");
        printf("1 - Continuar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &bool);
    }
    return 0;
}