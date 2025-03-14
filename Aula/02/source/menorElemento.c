#include <stdio.h>
#include <omp.h>

int main(){
    int arr [] = {3, 4, 1, 3, 6};
    int M [5][5] = {};
    int arr_x [5] = {};
    int min = 0;

    #pragma omp parallel for
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        #pragma omp parallel for
        for(int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++){
            if(arr[i] > arr[j]){
                M[i][j] = 1;
            }else{
                M[i][j] = 0;
            }
        }
    }

    #pragma omp parallel for
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        arr_x[i] = 0;
    }

    #pragma omp parallel for
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        #pragma omp parallel for
        for(int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++){
            if(M[i][j] == 1) arr_x[i] = 1;
        }
    }

    #pragma omp parallel for
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr_x[i] == 0) min = arr[i];
    }

    printf("Menor valor: %d\n", min);

    return 0;
}