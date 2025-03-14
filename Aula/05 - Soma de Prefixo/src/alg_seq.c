#include <stdio.h>
#include ".\main.h"

void soma_de_prefixos(int *in, int *out, int n){
    int soma = in[0];
    out[0] = soma;
    for(int i = 1; i < n; i++){
        out[i] = in[i] + soma;
        soma = out[i];
    }
}