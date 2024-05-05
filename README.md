# Implementação de Máquina de Turing com Fita Limitada
Este repositório contém implementações em linguagem C de ferramentas para simular uma Máquina de Turing com Fita Limitada. As funcionalidades incluem conversão entre caracteres e inteiros, manipulação de arquivos de entrada, leitura e montagem de dados da especificação da máquina, além da estruturação e manipulação da matriz de estados.

## Ferramentas
Ferramentas.h
Este arquivo contém funções para converter caracteres em inteiros e vice-versa, permutar valores de caracteres, buscar a posição de uma letra no alfabeto, verificar se um estado é final e outras funcionalidades úteis.

## Leitura.h
Aqui estão definidas funções para ler informações de arquivos de entrada, contar o número de linhas, extrair estados finais, alfabeto e estados, além de guardar e montar os dados da matriz de transição.

## Matriz.h
Este arquivo contém funções para esvaziar e imprimir a matriz de estados, bem como para montar a cadeia de entrada inicial e processar a palavra, determinando se é aceita ou rejeitada pela máquina.

## Uso
Compile os arquivos .c fornecidos utilizando um compilador C, como o GCC. Certifique-se de incluir os arquivos .h necessários. Após a compilação, execute o programa e forneça o nome do arquivo de entrada contendo as especificações da Máquina de Turing com Fita Limitada. Insira as palavras que deseja testar e observe a saída do programa para verificar se as palavras são aceitas ou rejeitadas pela máquina.

## Exemplo de Arquivo de Entrada
Um exemplo de arquivo de entrada pode ser:

```
Q=5
F={q4}
alfabeto={a,b,X,Y}
(q0,a)=(q1,X,D)
(q0,Y)=(q2,Y,D)
(q1,a)=(q1,a,D)
(q1,Y)=(q1,Y,D)
(q1,b)=(q3,Y,E)
(q3,a)=(q3,a,E)
(q3,Y)=(q3,Y,E)
(q3,X)=(q0,X,D)
(q2,Y)=(q2,Y,D)
(q2,b)=(q4,Y,D)
(q2,$)=(q4,$,E)
(q4,Y)=(q4,Y,D)
(q4,$)=(q4,$,E)
```
Este arquivo contém a especificação de uma Máquina de Turing com Fita Limitada, incluindo o número de estados, os estados finais, o alfabeto, e as transições entre os estados.

## Autor
Este código foi escrito por Francisco Del`Gaudio.






