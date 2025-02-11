#include <stdio.h>
#include <omp.h>

int main(){
    int vetor [] = {2, 3, 1, 0, 10, 22, 6, 7, 8, 20, 10, 2, 0, 0};
    int maior = 0;
    int maior_local = 0;

    #pragma omp parallel for private(maior_local)
    for(int i=1; i < sizeof(vetor)/sizeof(vetor[0]); i++){
        if(maior_local < vetor[i]){
            maior_local = vetor[i];
        }

        #pragma omp critical
        if(maior_local > maior){
            maior = maior_local;
        }
    }

    printf("Maior valor: %d\n", maior);

    return 0;
}