#include <stdio.h>
#include "algoritimosdebusca.h"

int busca_sequencial(int v[], int n, int chave){
    int i;
    for(i = 0; i < n; i++){
        if(v[i] == chave){
            return i;
        }
    }
    return -1;
}


int busca_binaria(int v[], int n, int chave){
    int inicio = 0;
    int fim = n-1;
    int i;

    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        if(v[meio] == chave){
            return meio;
        }else if(chave < v[meio]){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }
    return -1;
}