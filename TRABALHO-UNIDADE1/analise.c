#include <stdio.h>
#include "algoritimosdebusca.h"
#include "algoritimosort.h"
#include <time.h>
#include <stdlib.h>


int main(){
    //Inicializado de numeo aleatoio
    srand(time(NULL));

    clock_t start, end;
    double time_taken;
    
    int n, opcao;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    

    printf("Digite o vetor de tamanho n(%d): ", n);
    for(int i = 0; i < n; i++){
        v[i] = rand() % 100000;
    }

    printf("Escolha a opção de ordenação e/ou busca: ");
    scanf("%d", &opcao);

    int chave = v[rand() % n];

    switch (opcao){
        case 1: {
            int repeticoes = 1000000;
            start = clock();

            for(int r = 0; r<repeticoes; r++){
                busca_sequencial(v, n, chave);
            }

            end = clock();
            time_taken = ((double)end - start) / CLOCKS_PER_SEC;

            printf("Tempo de execucao: %.10f segundos, para encontra a chave: %d\n", time_taken/repeticoes, chave);
            break;
        }
    }
        



    return 0;
}