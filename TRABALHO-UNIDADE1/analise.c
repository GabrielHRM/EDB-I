#include <stdio.h>
#include "algoritimosdebusca.h"
#include "algoritimosort.h"
#include <time.h>


int main(){
    //Inicializado de numeo aleatoio
    srand(time(NULL));

    int n, opcao;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    

    printf("Digite o vetor de tamanho n(%d): ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    printf("Escolha a opção de ordenação e/ou busca: ");
    scanf("%d", &opcao);

    int indiceAleatorio = rand() % n;
    int chave = v[indiceAleatorio];

    switch (opcao):
        case 1:
            clock_t start = clock();
            busca_sequencial(v, n, chave)
            clock_t end = clock();
            double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
            printf("Tempo de execucao: %f segundos, para encontra a chave: %d\n", time_taken, chave);
            break;



    return 0;
}