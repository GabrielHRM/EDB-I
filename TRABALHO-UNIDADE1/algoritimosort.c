#include <stdio.h>
#include "algoritimosort.h"

void bubble_sort(int v[], int n){
    int i, temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j+1]) {
                // Troca os elementos de posição
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void intercalar(int v[], int inicio1, int inicio2, int fim2){
    int fim1 = inicio2 - 1, i = inicio1, j = inicio2, k = 0;

    int tamanho = fim2 - inicio1 + 1;
    int tmp[tamanho];


    while(i <= fim1 && j <=fim2){
        if(v[i] <= v[j]){
            tmp[k] = v[i];
            i++;
        }else{
            tmp[k] = v[j];
            j++;
        }
        k++;
    }

    while(i <= fim1){
        tmp[k] = v[i];
        i++;
        k++;
    }

    while(j <= fim2){
        tmp[k] = v[j];
        j++;
        k++;
    }

    for (int p = 0; p < k; p++) {
        v[inicio1 + p] = tmp[p];
    }
}


void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // Divide o vetor recursivamente
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        // Intercala as metades ordenadas
        intercalar(v, inicio, meio + 1, fim);
    }
}

// Função auxiliar para trocar dois elementos
void trocar(int v[], int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

// Função Particionar baseada exatamente na sua lógica
int particionar(int v[], int esquerda, int direita) {
    int pivo = v[direita];
    int i = esquerda;
    int j = direita - 1;

    // WHILE j ≥ i
    while (j >= i) {
        // WHILE v[i] < pivo && j ≥ i
        while (i <= direita - 1 && v[i] < pivo) {
            i = i + 1;
        }
        // WHILE v[j] > pivo && j ≥ i
        while (j >= esquerda && v[j] > pivo) {
            j = j - 1;
        }

        if (j >= i) {
            // Swap v[i], v[j]
            trocar(v, i, j);
            i = i + 1;
            j = j - 1;
        }
    }

    // Swap v[i], v[direita]
    trocar(v, i, direita);
    
    return i; // Retorna a posição do pivô
}

// Função principal recursiva Quick Sort
void quickSort(int v[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Encontra o índice de partição
        int p = particionar(v, esquerda, direita);

        // Ordena os elementos antes e depois da partição
        quickSort(v, esquerda, p - 1);
        quickSort(v, p + 1, direita);
    }
}