#include <stdio.h>
#include <omp.h> // OpenMP

int main(int argc, char** argv){
    #pragma omp parallel // Marca a parte a ser "paralelizada"
    {
        printf("Núcleo %d: Olá.\n", omp_get_thread_num());
    }
    return 0;
}