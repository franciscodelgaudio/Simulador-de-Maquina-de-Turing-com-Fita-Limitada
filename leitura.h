#ifndef LEITURA_H
#define LEITURA_H

#define TAM_MATRIZ 50
#define TAM_VETOR 50

// Lê uma linha específica de um arquivo e a armazena em um array de caracteres
// Entrada: string onde a linha do arquivo será armazenada, número da linha que deve ser lida no arquivo,
//      nome do arquivo a ser lido
// Saída: 0
int guardarLinhaArquivo(char * palavra, int linha, char * arquivo);

// Conta o número de linhas em um arquivo
// Entrada: nome do arquivo a ser lido
// Saída: número de linhas
int contarLinhaArquivo (char * arquivo);

// Extrai os estados finais da linha que contém tal especificação e guarda num vetor
// Entrada: vetor para estados finais, posição atual no array e nome do arquivo a ser lido
// Saída: nenhuma
void guardarEstadoFinal (int estadosFinais[TAM_VETOR], int * j, char * arquivo);

// Extrai o alfabeto da linha que contém tal especificação e guarda num array de char
// Entrada: ponteiro para char, posição atual no array e nome do arquivo a ser lido
// Saída: nenhuma
void guardarAlfabeto (char * alfabeto, int * j, char * arquivo);

// Extrai os estados da linha que contém tal especificação e guarda num vetor
// Entrada: ponteiro para inteiro e o nome do arquivo a ser lido
// Saída: nenhuma
void guardarEstados(int * estados, char * arquivo);

// Lê todas as informações da especificação da gramática e guarda ponteiros relacionados com a matriz de transição
// Trata uma linha do arquivo por vez
// Entrada: número da linha na matriz, número da coluna na matriz, ponteiro para o estado de transição,
//      ponteiro para a direção da transição, nome do arquivo a ser lido e número da linha a ser lida no arquivo
// Saída: nenhuma
void guardarDadosMatriz (int * linhaMatriz, int * colunaMatriz, int * estadoTransicao, int * posicaoAlfabetoMatriz, int * direcao, char * arquivo, int linhaArquivo, char * alfabeto);

// Preenche a matriz de estados com as especificações da gramática
// Entrada: matriz onde será tudo armazenado, número da linha, número da coluna, estado de transição atual,
//      posição dentro do array de alfabeto, direção da transição, nome do arquivo a ser lido e símbolos do alfabeto
// Saída: nenhuma
void montarEstruturaMatriz (int matrizEstados[][TAM_MATRIZ][3], int * linhaMatriz, int * colunaMatriz, int * estadoTransicao, int * posicaoAlfabetoMatriz, int * direcao, char * arquivo, char * alfabeto);

#endif