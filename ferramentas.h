#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H

#define TAM_MATRIZ 50
#define TAM_VETOR 50

// Converte um caractere numérico em seu valor inteiro correspondente
// Entrada: caracter
// Saída: número correspondente
int converterCharInteiro(char c);

// Converte um valor inteiro em seu caractere correspondente
// Entrada: número inteiro
// Saída: caracter correspondente
char converterInteiroChar (int n);

// Troca os valores de duas variáveis do tipo char
// Entrada: ponteiro para os caracteres a serem trocados
// Saída: nenhuma
void permutar (char * x, char * y);

// Busca a posição de uma letra no alfabeto especificado
// Entrada: array de caracteres representando o alfabeto e a letra a ser encontrada
// Saída: posição da letra no alfabeto ou -1 se não for encontrada
int posicaoAlfabeto(char * alfabeto, char letra);

// Retorna a letra correspondente a uma determinada posição no alfabeto
// Entrada: o alfabeto e a posição desejada
// Saída: a letra correspondente ou -1 se a posição não existir
char alfabetoPosicao (char * alfabeto, int posicaoCorrespondente);

// Verifica se um determinado estado é um estado final
// Entrada: um array de inteiros representando os estados finais,
//      o tamanho desse array e o estado a ser verificado
// Saída: 1 se o estado for um estado final e 0 caso contrário
int eh_final(int * estadosFinais, int tamEstadoFinal, char estadoFinal);

#endif