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

    // Silencia os logs matemáticos do comando 'fit' no terminal
    fprintf(gp, "set fit quiet\n");

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
    fprintf(gp, "set key top left\n"); // Posição da legenda

    const char *caminho_csv = "'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/resultados.csv'";

    // ---------------------------------------------------------
    // 1. BUSCA BINÁRIA (Ajuste para curva Logarítmica)
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/01_busca_binaria.png'\n");
    fprintf(gp, "set title 'Busca Binaria: O(log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Media de Tempo por Busca (Microssegundos)' font ',14'\n");
    
    // Função logarítmica para o ajuste
    fprintf(gp, "f_bin(x) = a_bin * log(x) + b_bin\n");
    fprintf(gp, "fit f_bin(x) %s using 1:($3*10) via a_bin, b_bin\n", caminho_csv);
    
    fprintf(gp, "plot %s using 1:($3*10) with points pt 7 ps 1.5 lc rgb 'purple' title 'Tempo Empirico', \\\n", caminho_csv);
    fprintf(gp, "     f_bin(x) with lines lw 3 lc rgb 'black' title 'Ajuste Teorico O(log n)'\n");

    // ---------------------------------------------------------
    // 2. BUSCA SEQUENCIAL
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/02_busca_sequencial.png'\n");
    fprintf(gp, "set title 'Busca Sequencial: O(n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Media de Tempo por Busca (Microssegundos)' font ',14'\n");
    // Voltei a legenda original para o sequencial e bubble também para padronizar
    fprintf(gp, "plot %s using 1:($2*10) with linespoints pt 7 ps 1.5 lw 3 lc rgb 'orange' title 'Tempo Empirico'\n", caminho_csv);

    // ---------------------------------------------------------
    // 3. BUBBLE SORT
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/03_bubble_sort.png'\n");
    fprintf(gp, "set title 'Bubble Sort: O(n^2)' font ',18'\n");
    fprintf(gp, "set ylabel 'Tempo Total (Segundos)' font ',14'\n");
    fprintf(gp, "plot %s using 1:4 with linespoints pt 7 ps 1.5 lw 3 lc rgb 'red' title 'Tempo Empirico'\n", caminho_csv);

    // ---------------------------------------------------------
    // 4. MERGE SORT (Ajuste para curva N log N)
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/04_merge_sort.png'\n");
    fprintf(gp, "set title 'Merge Sort: O(n log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Tempo Total (Segundos)' font ',14'\n");
    
    // Função N log N para o ajuste
    fprintf(gp, "f_merge(x) = a_merge * x * log(x) + b_merge\n");
    fprintf(gp, "fit f_merge(x) %s using 1:5 via a_merge, b_merge\n", caminho_csv);

    fprintf(gp, "plot %s using 1:5 with points pt 7 ps 1.5 lc rgb 'blue' title 'Tempo Empirico', \\\n", caminho_csv);
    fprintf(gp, "     f_merge(x) with lines lw 3 lc rgb 'black' title 'Ajuste Teorico O(n log n)'\n");

    // ---------------------------------------------------------
    // 5. QUICK SORT (Ajuste para curva N log N)
    // ---------------------------------------------------------
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/05_quick_sort.png'\n");
    fprintf(gp, "set title 'Quick Sort: O(n log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Tempo Total (Segundos)' font ',14'\n");
    
    // Função N log N para o ajuste
    fprintf(gp, "f_quick(x) = a_quick * x * log(x) + b_quick\n");
    fprintf(gp, "fit f_quick(x) %s using 1:6 via a_quick, b_quick\n", caminho_csv);

    fprintf(gp, "plot %s using 1:6 with points pt 7 ps 1.5 lc rgb 'green' title 'Tempo Empirico', \\\n", caminho_csv);
    fprintf(gp, "     f_quick(x) with lines lw 3 lc rgb 'black' title 'Ajuste Teorico O(n log n)'\n");

    // Fecha o Gnuplot
    _pclose(gp);
    printf("Os 5 graficos foram gerados com sucesso com os ajustes teoricos!\n");
}