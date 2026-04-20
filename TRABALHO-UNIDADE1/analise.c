#include <stdio.h>
#include "algoritimosdebusca.h"
#include "algoritimosort.h"


int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    printf("Digite o vetor de tamanho n(%d): \n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    mergeSort(v, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }


    return 0;
}