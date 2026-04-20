#include <stdio.h>
#include "algoritimosdebusca"
#include "algoritimosort"


int main(){
    int v[];
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    printf("Digite o vetor de taamnho n: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }


    return 0;
}