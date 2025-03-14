#include <stdio.h>
#include <omp.h>

int main(){
    int arrA [5] = {};
    int arrB [] = {1, 2, 3, 4, 5};
    int arrC [] = {5, 4, 3, 2, 1};

    #pragma omp parallel for
    for(int i = 0; i < 5; i++){
        arrA[i] = arrB[i] + arrC[i];
    }

    for(int i = 0; i < 5; i++){
        printf("%d, ", arrA[i]);
    }
    printf("\n");
    return 0;
}