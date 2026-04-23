#include "grafico.h"
#include <stdio.h>
#include <stdlib.h>

void gerar_grafico_gnuplot() {
    FILE *gp = _popen("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" -persistent", "w"); 

    if (gp == NULL) {
        printf("Erro ao abrir o Gnuplot.\n");
        return;
    }

    fprintf(gp, "set datafile separator ';'\n");
    fprintf(gp, "set grid\n");

    // Configura o Gnuplot para exportar imagens PNG em alta resolução (1024x768)
    fprintf(gp, "set terminal png size 1024,768 font 'Arial,12'\n");

    // Configurações visuais gerais para gráficos grandes
    fprintf(gp, "set lmargin 12\n");
    fprintf(gp, "set rmargin 5\n");
    fprintf(gp, "set bmargin 5\n");
    fprintf(gp, "set tmargin 5\n");
    fprintf(gp, "set xtics rotate by -45 offset -1,0 font ',10'\n");
    fprintf(gp, "set ytics font ',10'\n");
    fprintf(gp, "set xlabel 'Tamanho do Vetor (N)' font ',14'\n");

    const char *caminho_csv = "'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/resultados.csv'";

    // ---------------------------------------------------------
    // 1. BUSCA BINÁRIA
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/01_busca_binaria.png'\n");
    fprintf(gp, "set title 'Busca Binaria: O(log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Media de Tempo por Busca (Microssegundos)' font ',14'\n");
    fprintf(gp, "plot %s using 1:($3*10) with linespoints pt 7 ps 1.5 lw 3 lc rgb 'purple' notitle\n", caminho_csv);

    // ---------------------------------------------------------
    // 2. BUSCA SEQUENCIAL
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/02_busca_sequencial.png'\n");
    fprintf(gp, "set title 'Busca Sequencial: O(n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Media de Tempo por Busca (Microssegundos)' font ',14'\n");
    fprintf(gp, "plot %s using 1:($2*10) with linespoints pt 7 ps 1.5 lw 3 lc rgb 'orange' notitle\n", caminho_csv);

    // ---------------------------------------------------------
    // 3. BUBBLE SORT
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/03_bubble_sort.png'\n");
    fprintf(gp, "set title 'Bubble Sort: O(n^2)' font ',18'\n");
    fprintf(gp, "set ylabel 'Tempo Total (Segundos)' font ',14'\n");
    fprintf(gp, "plot %s using 1:4 with linespoints pt 7 ps 1.5 lw 3 lc rgb 'red' notitle\n", caminho_csv);

    // ---------------------------------------------------------
    // 4. MERGE SORT
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/04_merge_sort.png'\n");
    fprintf(gp, "set title 'Merge Sort: O(n log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Tempo Total (Segundos)' font ',14'\n");
    fprintf(gp, "plot %s using 1:5 with linespoints pt 7 ps 1.5 lw 3 lc rgb 'blue' notitle\n", caminho_csv);

    // ---------------------------------------------------------
    // 5. QUICK SORT
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/05_quick_sort.png'\n");
    fprintf(gp, "set title 'Quick Sort: O(n log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Tempo Total (Segundos)' font ',14'\n");
    fprintf(gp, "plot %s using 1:6 with linespoints pt 7 ps 1.5 lw 3 lc rgb 'green' notitle\n", caminho_csv);

    // Fecha o Gnuplot
    _pclose(gp);
    printf("Os 5 graficos foram gerados com sucesso na pasta do projeto!\n");
}