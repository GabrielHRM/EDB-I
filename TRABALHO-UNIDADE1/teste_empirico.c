#include "teste_empirico.h"
#include "algoritimosdebusca.h"
#include "algoritimosort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

/*struct para guardar os resultados do tamanho do vetor 
e o tempo que cada algoritimo levou para passar po ele*/
typedef struct{
    int n;
    double tempo;
}Resultado;

//Função para salvar o tepo de execução
void teste_tempo(int *v){
    /*Define a prioridade do processo atual (GetCurrentProcess())
     para o nível mais alto possível no Windows (REALTIME_PRIORITY_CLASS).*/
    SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

    //Variavel para precisão grafica do quick e merge sort já que eles são muito eficientes
    int temp_merge_quick = 10;

    /*Inicializa o gerador de números pseudoaleatórios */
    srand(time(NULL));
    //Vetor para arazenar os tamanhos dos vetores que irão conter os dados a sere analisados
    long int tamanhos[40];
    //Número de tamanhos dos vetores
    int n = 40;
    //Valor minimo e maximo para calculo de incremento progressivo dos tamanhos dos vetores de dados
    long int min = 10000, max = 200000;
    //variaveis temporais para cada tempo de execução de cada algoritimo
    clock_t s1, s2, s3, s4, s5, e1, e2, e3, e4, e5;
    //Variaveis para o calculo do tempo total de execução
    double ttk1, ttk2, ttk3, ttk4 = 0, ttk5;

    //5 vetores que irão armazenar o vetor original(v) para serem utilizados nos algoritmos de ordenação
    int *v_copia1 = (int *)malloc(max * sizeof(int));
    int *v_copia2 = (int *)malloc(max * sizeof(int));
    int *v_copia3 = (int *)malloc(max * sizeof(int));
    int *v_copia4 = (int *)malloc(max * sizeof(int));
    int *v_copia5 = (int *)malloc(max * sizeof(int));

    //Vetores que irão armazenar o tamnho dos vetores em cada incrementação e seus tempos de execução
    Resultado buscasequencial[n];
    Resultado buscabinaria[n];
    Resultado bubbles[n];
    Resultado merges[n];
    Resultado quicks[n];

    //Incremento progressivo dos tamanhos dos vetores de dados
    long incremento = (max - min) / (n - 1);

    /*Vetor para criar chaves aleatorias, que estejam dentro do vetor da incrementação atual,
     para os algoritimos de busca sequencial e binaria*/
    int chaves_de_teste[100000];

    //Aumento progressivo do tamanho dos vetores(de 10000 até 200000)
    for(int i = 0; i < n; i++){
        tamanhos[i] = min + (i * incremento);
    }

    for(int i = 0; i < n; i++){
        //Variavel que assumi o valor do tamanho do vetor da iteração atual
        int n_testes = tamanhos[i];

        //Copia o vetor original para 3 outros vetores
        for(int j = 0; j < n_testes; j++){
            //Vetor original inicialmente vazio, que é então preenchido comnumeros aleatorios
            v[j] = (rand() * rand()) % 100000;
            v_copia1[j] = v[j];
            v_copia2[j] = v[j];
            v_copia3[j] = v[j];
            v_copia4[j] = v[j];
            v_copia5[j] = v[j];
        }

        //Gerador de 100000 chaves distintas
        for(int k = 0; k < 100000; k++){
            chaves_de_teste[k] = v[(rand() * rand()) % n_testes];
        }

        /*-------Busca Sequencial-------*/
        //Para uma melhor precisão gráfica, a busca sequencial é chamada 100000 vezes
        s1 = clock();
        for(int k = 0; k < 100000; k++){
            busca_sequencial(v, n_testes, chaves_de_teste[k]);
        }
        e1 = clock();
        ttk1 = ((double)e1 - s1) / CLOCKS_PER_SEC;
        buscasequencial[i].n = n_testes;
        buscasequencial[i].tempo = ttk1;
        /*-----------------------------*/

        /*-------Busca Binaria-------*/
        //Ordenação inicial para a busca binária
        quickSort(v, 0, n_testes - 1);
        //Para uma melhor precisão gráfica, a busca binária é chamada 100000 vezes
        s2 = clock();
        for(int k = 0; k < 100000; k++){
            busca_binaria(v, n_testes, chaves_de_teste[k]);
        }
        e2 = clock();
        ttk2 = ((double)e2 - s2) / CLOCKS_PER_SEC;
        buscabinaria[i].n = n_testes;
        buscabinaria[i].tempo = ttk2;
        /*---------------------------*/

        /*-------Bubble Sort-------*/
        s3 = clock();
        bubble_sort(v_copia1, n_testes);
        e3 = clock();
        ttk3 = ((double)e3 - s3) / CLOCKS_PER_SEC;
        bubbles[i].n = n_testes;
        bubbles[i].tempo = ttk3;
        /*-------------------------*/

        /*-------Merge Sort-------*/
        ttk4 = 0;
        for(int z = 0; z < temp_merge_quick; z++){
            for(int x = 0; x < n_testes; x++){
                v_copia4[x] = v_copia2[x];
            }
            s4 = clock();
            mergeSort(v_copia4, 0, n_testes - 1);
            e4 = clock();
            ttk4 += ((double)e4 - s4) / CLOCKS_PER_SEC;
        }
        merges[i].n = n_testes;
        /*Média das 10 execuções dentro da iteração atual 
        para se ter uma execução temporal mais precisa no merge sort*/
        merges[i].tempo = ttk4/temp_merge_quick;
        /*-------------------------*/

        /*-------Quick Sort-------*/
        ttk5 = 0;
        for(int z = 0; z < temp_merge_quick; z++){
            for(int x = 0; x < n_testes; x++){
                v_copia5[x] = v_copia3[x];
            }
            s5 = clock();
            quickSort(v_copia5, 0, n_testes - 1);
            e5 = clock();
            ttk5 += ((double)e5 - s5) / CLOCKS_PER_SEC;
        }
        quicks[i].n = n_testes;
        /*Média das 10 execuções dentro da iteração atual 
        para se ter uma execução temporal mais precisa no quick sort*/
        quicks[i].tempo = ttk5/temp_merge_quick;
        /*-------------------------*/
        /*-------------------------*/

    }

    // --- CÓDIGO PARA CRIAR O ARQUIVO CSV ---
    FILE *arq = fopen("resultados.csv", "w"); // Cria ou sobrescreve o arquivo
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    // Cabeçalho (Primeira linha do Excel/Gnuplot)
    fprintf(arq, "N;BuscaSeq;BuscaBin;Bubble;Merge;Quick\n");

    // Loop para gravar cada um dos 60 resultados salvos nas structs
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
    free(v_copia4);
    free(v_copia5);
}