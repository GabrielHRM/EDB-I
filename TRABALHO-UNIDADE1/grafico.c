#include "grafico.h"
#include <stdio.h>
#include <stdlib.h>

void gerar_grafico_gnuplot() {
    // _popen para Windows, popen para Linux
    FILE *gp = _popen("gnuplot -persistent", "w"); 
    if (gp == NULL) {
        printf("Erro ao abrir o Gnuplot. Verifique o PATH.\n");
        return;
    }

    fprintf(gp, "set title 'Comparativo de Algoritmos - i5-13420H'\n");
    fprintf(gp, "set xlabel 'Tamanho N'\n");
    fprintf(gp, "set ylabel 'Tempo (s)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set datafile separator ';'\n");
    
    // Comando para plotar todas as colunas do CSV que você gerou
    fprintf(gp, "plot 'resultados.csv' using 1:2 with lines lw 2 title 'Busca Seq', "
                "'resultados.csv' using 1:3 with lines lw 2 title 'Busca Bin', "
                "'resultados.csv' using 1:4 with lines lw 2 title 'Bubble', "
                "'resultados.csv' using 1:5 with lines lw 2 title 'Merge', "
                "'resultados.csv' using 1:6 with lines lw 2 title 'Quick'\n");

    _pclose(gp);
}