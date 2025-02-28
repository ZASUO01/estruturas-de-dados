## Objetivo

Este trabalho consiste em analisar o desempenho de diferentes algoritmos de ordenação em
diferentes cenários, descritos a seguir. Esta análise consiste em comparar os algoritmos
considerando três métricas de desempenho: número de comparações de chaves, o número de
cópias de registros realizadas, e o tempo total gasto para ordenação (tempo de processamento e
não o tempo de relógio). As entradas são conjuntos de elementos com chaves aleatoriamente
geradas.

## Descrição

Foi comparado o desempenho de diferentes variações do Quicksort para
ordenar um conjunto de N registros armazenados em um vetor. Essas variações foram ainda compradas 
com o Heapsort e Mergesort.
Cada registro contém:

 - Um inteiro, que é a chave para ordenação
 - Quinze cadeias de caracteres (strings), cada uma com 200 caracteres
 - 10 números reais

As variações do Quicksort a serem implementadas e avaliadas são:
- Quicksort Recursivo.
- Quicksort Mediana(k): esta variação do Quicksort recursivo escolhe o pivô para partição
como sendo a mediana de k elementos do vetor, aleatoriamente escolhidos.
- Quicksort Seleção(m): esta variação modifica o Quicksort Recursivo para utilizar o
algoritmo de Seleção para ordenar partições com tamanho menor ou igual a m.
- Quicksort Iterativo: esta variação escolhe o pivô como o elemento do meio (como
apresentado em sala de aula), mas não é recursiva, utilizando uma pilha para armazenar
partições a serem processadas posteriormente. 
- Quicksort Empilha Inteligente: esta variação do Quicksort processa primeiro a menor
partição.


## Avaliação

Cada algoritmo foi aplicado a entradas aleatórias com diferentes
tamanhos N = 1000, 5000, 10000, 50000, 100000, 500000 e 1000000.
Os valores médios de 5 execuções foram contabilizados.

# Execução

Para executar cada algorítmo deve-se rodar:

```sh
# compilar o programa
make

# program [algname] -v version -s seed -k optional -m optional -i input -o output  
./bin/main quicksort -v 1 -s 10 -i input.txt -o output.txt

# gerar graficos
make plot
```



