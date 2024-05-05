#include <stdio.h>
#include "ferramentas.h"

#define TAM_MATRIZ 50
#define TAM_VETOR 50

// Converte um caractere numérico em seu valor inteiro correspondente
// Entrada: caracter
// Saída: número correspondente
int converterCharInteiro(char c) {
    return c - '0';
}

// Converte um valor inteiro em seu caractere correspondente
// Entrada: número inteiro
// Saída: caracter correspondente
char converterInteiroChar (int n){
    return ((char)(n + '0'));
}

// Troca os valores de duas variáveis do tipo char
// Entrada: ponteiro para os caracteres a serem trocados
// Saída: nenhuma
void permutar (char * x, char * y){
    char aux = *x;
    *x = *y;
    *y = aux;
}

// Busca a posição de uma letra no alfabeto especificado
// Entrada: array de caracteres representando o alfabeto e a letra a ser encontrada
// Saída: posição da letra no alfabeto ou -1 se não for encontrada
int posicaoAlfabeto(char * alfabeto, char letra){
    for (int i = 0 ; alfabeto[i] ; i++){
        if(alfabeto[i] == letra) return i;
    }
    return -1;
}

// Retorna a letra correspondente a uma determinada posição no alfabeto
// Entrada: o alfabeto e a posição desejada
// Saída: a letra correspondente ou -1 se a posição não existir
char alfabetoPosicao (char * alfabeto, int posicaoCorrespondente){
    for (int i = 0 ; alfabeto[i] ; i++){
        if (i == posicaoCorrespondente) return alfabeto[i];
    }
    return -1;
}

// Verifica se um determinado estado é um estado final
// Entrada: um array de inteiros representando os estados finais,
//      o tamanho desse array e o estado a ser verificado
// Saída: 1 se o estado for um estado final e 0 caso contrário
int eh_final(int * estadosFinais, int tamEstadoFinal, char estadoFinal){
    for (int i = 0 ; i < tamEstadoFinal ; i++){
        if (estadoFinal == converterInteiroChar(estadosFinais[i])) return 1;
    }
    return 0;
}