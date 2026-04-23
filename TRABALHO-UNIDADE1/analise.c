#include "teste_empirico.h"
#include "algoritimosdebusca.h"
#include "algoritimosort.h"
#include "grafico.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    //Vetor inicial original vazio
    int *v = (int *)malloc(200000 * sizeof(int));

    teste_tempo(v);

    gerar_grafico_gnuplot();

    free(v);
    
    return 0;
}