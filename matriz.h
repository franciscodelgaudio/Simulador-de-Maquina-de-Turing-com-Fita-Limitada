#ifndef MATRIZ_H
#define MATRIZ_H

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
void esvaziarMatriz (int matrizEstados [][TAM_MATRIZ][3]);

// Imprime a matriz que contêm as transições de cada estado
// Entrada: matriz que contêm as transições de cada estado
// Saída: nenhuma
void imprimirMatriz (int matrizEstados [][TAM_MATRIZ][3]);

// Imprime a cadeia de símbolos que está no começo do processamento da palavra
// Entrada: ponteiro para a string resultante, ponteiro para string de símbolos a serem testados,
//      ponteiro para a posição do estado inicial da cadeia
// Saída: nenhuma
void montarStringInicial (char * stringFinal, char * cadeia, int * posicaoEstado);

// Faz o processamento da palavra e imprime o aceitamento dela
// Entrada: matriz de estados, cadeia de símbolos modificada, posição inicial de leitura da palavra, arquivo com especificações
//      da gramática, alfabeto da gramática, conjunto de estados finais e quantidade de estados finais
// Saída: nenhuma
void montarStringFinal (int matrizEstados [][TAM_MATRIZ][3], char * stringFinal, int * posicaoEstado, char * arquivo, char * alfabeto, int * estadosFinais, int tamEstadoFinal);

#endif