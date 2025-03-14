#include <stdio.h>
#include <math.h>
#include <omp.h>

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}

int MAX(int arr[], int n, int P){
    for(int i = 0; i < P; i++){
        int ini = (i - 1) * floor(n/P) + 1;
        for(int k = ini + 1; k < (ini + floor(n/P) - 1); k += 1){
            if(arr[k] > arr[ini]){
                arr[ini] = arr[k];
            }
        }
    }

    for(int k = (int)floor(log2(n/P)); k < (int)log2(n); k++){
        #pragma omp parallel for
        for(int i = 0; i < n; i += (int)pow(2, k)){
            if(i + (int)pow(2, k) <= n){
                arr[i] = max(arr[i], arr[i + (int)pow(2, k)]);
            }
        }
    }
    return arr[0];
}

int main(){
    int arr[16];
    for(int i = 0; i < 16; i++){
        arr[i] = i + 1;
    }

    int maior = MAX(arr, 16, 4);
    for(int i = 0; i < 16; i++){
        printf("%d, ", arr[i]);
    }
    printf("\nO maior valor é %d.\n", maior);
}