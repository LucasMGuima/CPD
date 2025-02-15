#include <stdio.h>
#include <omp.h>

void map(int arr[], int (*func)(int));
int dobro(int val);

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    map(arr, dobro);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}

int dobro(int val){
    return val * 2;
}

void map(int arr[], int (*func)(int)){
    #pragma omp parallel for
    for(int i = 0; i < sizeof(&arr)/sizeof(&arr[0]); i++){
        arr[i] = (*func)(arr[i]);
    }
}