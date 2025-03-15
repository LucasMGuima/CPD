#ifndef MAIN_H
#define MAIN_H

// Function prototypes

// Algoritmo sequencial
void soma_de_prefixos(int *in, int *out, int n);

// Soma de prefixos paralela
// Aplica súbida e descida na arvora para calcular a soma de prefixos
int* soma_de_prefixos_paralela(int *in, int n);

// Soam de prefixos em paralelo, de maneira não otimizada
void soma_de_prefixos_nOtima(int *in, int ini, int end);

// Encontra o menor elemento do vetor
// Aplica divisão e consquista para encontra o menor elemento do vetor
int menor_elemento(int *in, int ini, int end);

// Aplicia a divisão e consquista mas altera o vetor inicial,
// o primeiro elemento vira o menor elemento do vetor, no final da operação
int menor_elemento_compc(int *in, int ini, int end);

// Recursão onde o numero de processadores p é muito menor que n
int menor_elemento_p(int *in, int ini, int end, int p, int n);
#endif