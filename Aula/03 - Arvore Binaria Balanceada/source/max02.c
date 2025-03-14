#include <stdio.h>
#include <math.h>
#include <omp.h>

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}

int MAX(int arr[], int n, int p){
    int b[p*2];
    for(int i = 0; i < p; i++){
        b[p+1] = arr[i * (int)floor(n/p)];
        for(int j = 0; j < (int)floor(n/p); i++){
            if(arr[i * (int)floor(n/p) + j] > b[p+i]){
                b[p+i] = arr[i * (int)floor(n/p) + j];
            }
        }
    }

    for(double j = (log2(n)-1); j > 0; j--){
        for(int i = pow(2, j); i < pow(2,j+1); i++){
            b[i] = max(b[2*i], b[2*i + 1]);
        }
    }

    return b[0];
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
    return 0;
}