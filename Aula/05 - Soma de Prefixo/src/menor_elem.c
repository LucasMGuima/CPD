#include <omp.h>
#include <math.h>
#include ".\main.h"

int menor_elemento(int* in, int ini, int end){
    if(ini == end){
        return in[ini];
    }

    int meio = floor((ini+end)/2);
    int esq, dir;
    #pragma omp parallel
    {
        esq = menor_elemento(in, ini, meio);
        dir = menor_elemento(in, meio+1, end);
    }
    return esq < dir ? esq : dir;
}

int menor_elemento_compc(int* in, int ini, int end){
    if(ini == end){
        return in[ini];
    }

    int meio = floor((ini+end)/2);
    #pragma omp parallel
    {
        in[ini] = menor_elemento_compc(in, ini, meio);
        in[meio+1] = menor_elemento_compc(in, meio+1, end);
    }

    return in[ini] < in[meio+1] ? in[ini] : in[meio+1];
}

int min_serial(int* in, int ini, int end){
    for(int k = ini + 1; k <= end; k++){
        if(in[k] < in[ini]){
            in[ini] = in[k];
        }
    }
    return in[ini];
}

int menor_elemento_p(int *in, int ini, int end, int p, int n){
    if((ini-end+1) < (2*n)/p){
        return min_serial(in, ini, end);
    }

    int meio = floor((ini+end)/2);
    #pragma omp parallel
    {
        in[ini] = menor_elemento_p(in, ini, meio, p, n);
        in[meio+1] = menor_elemento_p(in, meio+1, end, p, n);
    }
    return in[ini] < in[meio+1] ? in[ini] : in[meio+1];
}