#include "teste_empirico.h"
#include "algoritimosdebusca.h"
#include "algoritimosort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
    int n;
    double tempo;
}Resultado;

void teste_tempo(int *v){
    srand(time(NULL));
    long int tamanhos[30];
    int n = 30;
    long int min = 10000, max = 100000;
    clock_t s1, s2, s3, s4, s5, e1, e2, e3, e4, e5;
    double ttk1, ttk2, ttk3, ttk4, ttk5;

    int *v_copia1 = (int *)malloc(max * sizeof(int));
    int *v_copia2 = (int *)malloc(max * sizeof(int));
    int *v_copia3 = (int *)malloc(max * sizeof(int));

    Resultado buscasequencial[n];
    Resultado buscabinaria[n];
    Resultado bubbles[n];
    Resultado merges[n];
    Resultado quicks[n];

    long incremento = (max - min) / (n - 1);

    int chaves_de_teste[100000];

    for(int i = 0; i < n; i++){
        tamanhos[i] = min + (i * incremento);
    }

    for(int i = 0; i < n; i++){
        int n_testes = tamanhos[i];

        for(int j = 0; j < n_testes; j++){
            v[j] = (rand() * rand()) % 100000;
            v_copia1[j] = v[j];
            v_copia2[j] = v[j];
            v_copia3[j] = v[j];
        }

        for(int k = 0; k < 100000; k++){
            chaves_de_teste[k] = v[(rand() * rand()) % n_testes];
        }

        s1 = clock();
        for(int k = 0; k < 100000; k++){
            busca_sequencial(v, n_testes, chaves_de_teste[k]);
        }
        e1 = clock();
        ttk1 = ((double)e1 - s1) / CLOCKS_PER_SEC;
        buscasequencial[i].n = n_testes;
        buscasequencial[i].tempo = ttk1;

        bubble_sort(v, n_testes);
        s2 = clock();
        for(int k = 0; k < 100000; k++){
            busca_binaria(v, n_testes, chaves_de_teste[k]);
        }
        e2 = clock();
        ttk2 = ((double)e2 - s2) / CLOCKS_PER_SEC;
        buscabinaria[i].n = n_testes;
        buscabinaria[i].tempo = ttk2;

        s3 = clock();
        bubble_sort(v_copia1, n_testes);
        e3 = clock();
        ttk3 = ((double)e3 - s3) / CLOCKS_PER_SEC;
        bubbles[i].n = n_testes;
        bubbles[i].tempo = ttk3;

        s4 = clock();
        mergeSort(v_copia2, 0, n_testes - 1);
        e4 = clock();
        ttk4 = ((double)e4 - s4) / CLOCKS_PER_SEC;
        merges[i].n = n_testes;
        merges[i].tempo = ttk4;

        s5 = clock();
        quickSort(v_copia3, 0, n_testes - 1);
        e5 = clock();
        ttk5 = ((double)e5 - s5) / CLOCKS_PER_SEC;
        quicks[i].n = n_testes;
        quicks[i].tempo = ttk5;

    }

    // --- CÓDIGO PARA CRIAR O ARQUIVO CSV ---
    FILE *arq = fopen("resultados.csv", "w"); // Cria ou sobrescreve o arquivo
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    // Cabeçalho (Primeira linha do Excel/Gnuplot)
    fprintf(arq, "N;BuscaSeq;BuscaBin;Bubble;Merge;Quick\n");

    // Loop para gravar cada um dos 15 resultados salvos nas suas structs
    for(int i = 0; i < n; i++) {
        fprintf(arq, "%d;%.15f;%.15f;%.15f;%.15f;%.15f\n", 
                buscasequencial[i].n, 
                buscasequencial[i].tempo, 
                buscabinaria[i].tempo, 
                bubbles[i].tempo, 
                merges[i].tempo, 
                quicks[i].tempo);
    }

    fclose(arq);
    free(v_copia1);
    free(v_copia2);
    free(v_copia3);
}