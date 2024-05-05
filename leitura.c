#include <stdio.h>
#include "leitura.h"
#include "ferramentas.h"

#define TAM_MATRIZ 50
#define TAM_VETOR 50

// Lê uma linha específica de um arquivo e a armazena em um array de caracteres
// Entrada: string onde a linha do arquivo será armazenada, número da linha que deve ser lida no arquivo,
//      nome do arquivo a ser lido
// Saída: 0
int guardarLinhaArquivo(char * palavra, int linha, char * arquivo){
    FILE * f;
    f = fopen(arquivo, "r");
    int cont=0;
    while(cont!=linha){
        fgets(palavra, 100, f);
        cont++;
    }
    fclose(f);
    return 0;
}

// Conta o número de linhas em um arquivo
// Entrada: nome do arquivo a ser lido
// Saída: número de linhas
int contarLinhaArquivo (char * arquivo) {
    FILE *f = fopen(arquivo, "r");
    int count = 0;
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    fclose(f);
    return count + 1;
}

// Extrai os estados finais da linha que contém tal especificação e guarda num vetor
// Entrada: vetor para estados finais, posição atual no array e nome do arquivo a ser lido
// Saída: nenhuma
void guardarEstadoFinal (int estadosFinais[TAM_VETOR], int * j, char * arquivo){
    char strEstadoFinal [TAM_VETOR];

    guardarLinhaArquivo(strEstadoFinal, 2, arquivo);

    for (int i = (*j) = 0 ; strEstadoFinal[i] ; i++){
        if (strEstadoFinal[i] == 'q'){
            estadosFinais[*j] = converterCharInteiro(strEstadoFinal[i+1]);
            (*j)++;
        }
    }
}

// Extrai o alfabeto da linha que contém tal especificação e guarda num array de char
// Entrada: ponteiro para char, posição atual no array e nome do arquivo a ser lido
// Saída: nenhuma
void guardarAlfabeto (char * alfabeto, int * j, char * arquivo){
    char strAlfabeto[TAM_VETOR];

    guardarLinhaArquivo(strAlfabeto, 3, arquivo);

    for (int i = (*j) = 0 ; strAlfabeto[i] ; i++){
        if (strAlfabeto[i] == '{' || strAlfabeto[i] == ','){
            alfabeto[(*j)] = strAlfabeto[i+1];
            (*j)++;
        }
    }
    alfabeto[*j] = '$';
    alfabeto[*j+1] = '\0';
}

// Extrai os estados da linha que contém tal especificação e guarda num vetor
// Entrada: ponteiro para inteiro e o nome do arquivo a ser lido
// Saída: nenhuma
void guardarEstados(int * estados, char * arquivo){
    char strAlfabeto[TAM_VETOR];
    guardarLinhaArquivo(strAlfabeto, 1, arquivo);

    for (int i = 0 ; i <= 2 ; i++){
        if(i == 2) *estados = converterCharInteiro(strAlfabeto[2]);
    }
}

// Lê todas as informações da especificação da gramática e guarda ponteiros relacionados com a matriz de transição
// Trata uma linha do arquivo por vez
// Entrada: número da linha na matriz, número da coluna na matriz, ponteiro para o estado de transição,
//      ponteiro para a direção da transição, nome do arquivo a ser lido e número da linha a ser lida no arquivo
// Saída: nenhuma
void guardarDadosMatriz (int * linhaMatriz, int * colunaMatriz, int * estadoTransicao, int * posicaoAlfabetoMatriz, int * direcao, char * arquivo, int linhaArquivo, char * alfabeto){
    char strEstados [TAM_VETOR];

    guardarLinhaArquivo(strEstados, linhaArquivo, arquivo);

    for (int i = 0 ; strEstados[i] ; i++){
        switch (i)
        {
        case 2:
            *linhaMatriz = converterCharInteiro(strEstados[i]);
            break;
        
        case 4:
            *colunaMatriz = posicaoAlfabeto(alfabeto, strEstados[i]);
            break;

        case 9:
            *estadoTransicao = converterCharInteiro(strEstados[i]);
            break;

        case 11:
            *posicaoAlfabetoMatriz = posicaoAlfabeto(alfabeto, strEstados[i]);
            break;

        case 13:
            if (strEstados[i] == 'D') *direcao = 1;
            else if (strEstados[i] == 'E') *direcao = 0;
            
        default:
            break;
        }
    }
}

// Preenche a matriz de estados com as especificações da gramática
// Entrada: matriz onde será tudo armazenado, número da linha, número da coluna, estado de transição atual,
//      posição dentro do array de alfabeto, direção da transição, nome do arquivo a ser lido e símbolos do alfabeto
// Saída: nenhuma
void montarEstruturaMatriz (int matrizEstados[][TAM_MATRIZ][3], int * linhaMatriz, int * colunaMatriz, int * estadoTransicao, int * posicaoAlfabetoMatriz, int * direcao, char * arquivo, char * alfabeto){
    for (int j = 4 ; j <= contarLinhaArquivo(arquivo) ; j++){
        guardarDadosMatriz(linhaMatriz, colunaMatriz, estadoTransicao, posicaoAlfabetoMatriz, direcao, arquivo, j, alfabeto);

        //printf("Linha[%d] Coluna[%d] = Estado [%d], Letra[%d], Direcao[%d]\n", *linhaMatriz, *colunaMatriz, *estadoTransicao, *posicaoAlfabetoMatriz, *direcao);

        for (int i = 0 ; i < 3 ; i++){
            if (i == 0) matrizEstados[*linhaMatriz][*colunaMatriz][i] = *estadoTransicao;
            if (i == 1) matrizEstados[*linhaMatriz][*colunaMatriz][i] = *posicaoAlfabetoMatriz;
            if (i == 2) matrizEstados[*linhaMatriz][*colunaMatriz][i] = *direcao;
        }
    }
}