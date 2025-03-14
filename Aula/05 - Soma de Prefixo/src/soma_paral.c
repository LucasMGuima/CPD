#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include ".\main.h"

int* soma_de_prefixos_paralela(int *in, int n){
    int *B = (int*)malloc(2*n*sizeof(int)); // Vetor auxiliar
    int *out = (int*)malloc(2*n*sizeof(int)); // Vetor de saída, as n porisções finais teram a soma dos prefixos

    // Vetor A é copiado para a segunda metade do vetor B
    #pragma omp parallel for
    for(int i = 0; i < n; i++){
        B[n + i] = in[i];
    }

    // Passo 1: Subida na árvore
    // Soma os valores de A de dois em dois e coloca na primeira metade de B
    for(int j = (log2(n) - 1); j >= 0; j--){
        #pragma omp parallel for
        for(int i = (int)pow(2,j); i <= (int)pow(2,j+1)-1; i++){
            B[i] = B[2*i] + B[2*i + 1];
        }
    }

    // Passo 2: Descida na árvore
    out[1] = B[1];

    for(int j = 1; j <= log2(n); j++){
        #pragma omp parallel for
        for(int i = (int)pow(2,j); i <= (int)pow(2,j+1)-1; i++){
            if((i%2) == 0){
                out[i] = out[i/2] - B[i+1]; // Filho esquerdo
            } else {
                out[i] = out[(i-1)/2]; // Filho direito
            }
        }
    }

    return out;
}