#include<stdio.h>
#include "matriz.h"
#include "leitura.h"
#include "ferramentas.h"

#define TAM_MATRIZ 50
#define TAM_VETOR 50

/*
Exemplo de matriz com especificação de gramática
[estado   posição_alfabeto   dir_ou_esq]
q0 [  1  2  1] [ -1 -1 -1] [ -1 -1 -1] [  2  3  1] [ -1 -1 -1]
q1 [  1  0  1] [  3  3  0] [ -1 -1 -1] [  1  3  1] [ -1 -1 -1]
q2 [ -1 -1 -1] [  4  3  1] [ -1 -1 -1] [  2  3  1] [  4  4  0]
q3 [  3  0  0] [ -1 -1 -1] [  0  2  1] [  3  3  0] [ -1 -1 -1]
q4 [ -1 -1 -1] [ -1 -1 -1] [ -1 -1 -1] [ -1 -1 -1] [ -1 -1 -1]
*/

// Esvazia a matriz, colocando todos os elementos iguais à -1
// Entrada: matriz que contêm as transições de cada estado
// Saída: nenhuma
void esvaziarMatriz (int matrizEstados [][TAM_MATRIZ][3]){
    for (int i = 0 ; i < TAM_MATRIZ ; i++){
        for (int j = 0 ; j < TAM_MATRIZ ; j++){
            for (int k = 0 ; k < TAM_MATRIZ ; k++){
                matrizEstados[i][j][k] = -1;
            }
        }
    }
}

// Imprime a matriz que contêm as transições de cada estado
// Entrada: matriz que contêm as transições de cada estado
// Saída: nenhuma
void imprimirMatriz (int matrizEstados [][TAM_MATRIZ][3]){
    for (int i = 0 ; i < TAM_MATRIZ ; i++){
        for (int j = 0 ; j < TAM_MATRIZ ; j++){
            printf("[");
            for (int k = 0 ; k < 3 ; k++){
                printf("%3d", matrizEstados[i][j][k]);
            }
            printf("] ");
        }
        printf("\n");
    }
}

// Imprime a cadeia de símbolos que está no começo do processamento da palavra
// Entrada: ponteiro para a string resultante, ponteiro para string de símbolos a serem testados,
//      ponteiro para a posição do estado inicial da cadeia
// Saída: nenhuma
void montarStringInicial (char * stringFinal, char * cadeia, int * posicaoEstado){
    int i;
    stringFinal[0] = '*';
    stringFinal[1] = '0';
    *posicaoEstado = 1;
    for (i = 0 ; cadeia[i] ; i++){
        stringFinal[i+2] = cadeia[i];
    }
    stringFinal[i+2] = '$';
    stringFinal[i+3] = '\0';
    for (int j = 0 ; stringFinal[j] ; j++){
        if (j == *posicaoEstado) printf("[q%c]", stringFinal[j]);
        if (j != *posicaoEstado) printf("%c", stringFinal[j]);
    }
    printf("\n");
}

// Faz o processamento da palavra e imprime o aceitamento dela
// Entrada: matriz de estados, cadeia de símbolos modificada, posição inicial de leitura da palavra, arquivo com especificações
//      da gramática, alfabeto da gramática, conjunto de estados finais e quantidade de estados finais
// Saída: nenhuma
void montarStringFinal (int matrizEstados [][TAM_MATRIZ][3], char * stringFinal, int * posicaoEstado, char * arquivo, char * alfabeto, int * estadosFinais, int tamEstadoFinal){
    int linha, coluna;

    while(1){
        linha = converterCharInteiro(stringFinal[*posicaoEstado]);
        coluna = posicaoAlfabeto(alfabeto, stringFinal[*posicaoEstado+1]);

        if (matrizEstados[linha][coluna][0] == -1){
            printf("REJEITA\n\n");
            break;
        }

        if (coluna == -1){
            printf("REJEITA\n\n");
            break;
        }

        stringFinal[*posicaoEstado] = converterInteiroChar(matrizEstados[linha][coluna][0]);
        stringFinal[*posicaoEstado+1] = alfabetoPosicao(alfabeto, matrizEstados[linha][coluna][1]);
        if (matrizEstados[linha][coluna][2] == 1){
            permutar(&stringFinal[*posicaoEstado], &stringFinal[*posicaoEstado+1]);
            (*posicaoEstado)++; 
        }
        if (matrizEstados[linha][coluna][2] == 0){
            permutar(&stringFinal[*posicaoEstado], &stringFinal[*posicaoEstado-1]);
            (*posicaoEstado)--; 
        }
        for (int j = 0 ; stringFinal[j] ; j++){
            if (j == *posicaoEstado) printf("[q%c]", stringFinal[j]);
            if (j != *posicaoEstado) printf("%c", stringFinal[j]);
        }

        printf("\n");        

        if (eh_final(estadosFinais, tamEstadoFinal, stringFinal[*posicaoEstado]) && matrizEstados[matrizEstados[linha][coluna][0]][matrizEstados[linha][coluna][1]][0] == -1){
            printf("ACEITA\n\n");
            break;
        }
    }
}