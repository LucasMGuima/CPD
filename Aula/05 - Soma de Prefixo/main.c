#include <stdio.h>
#include ".\src\main.h"

int main(){
    int in[] = {2, 3, 1, 3, 1, 4, 2, 1};
    int length = sizeof(in) / sizeof(in[0]);
    int out[length];

    soma_de_prefixos(in, out, length);
    int *out = soma_de_prefixos_paralela(in, length);

    printf("Soma de Prefixos, subida na árvore\n");
    for(int i = 0; i < 2*length; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
    printf("Divisão e Consquista\n\tMenor elemento: %d\n", menor_elemento(in, 0, length-1));
    menor_elemento_compc(in, 0, length-1);
    printf("Divisão e Consquista, alterando vetor\n\tMenor elemento: %d\n", in[0]);
    printf("Menor elemento, com P processadores: %d\n", menor_elemento_p(in, 0, length-1, 2, length));

    return 0;
}