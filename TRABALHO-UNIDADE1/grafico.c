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
    fprintf(gp, "set fit quiet\n"); // Esconde logs detalhados do ajuste
    fprintf(gp, "set terminal png size 1024,768 font 'Arial,12'\n");
    fprintf(gp, "set xtics rotate by -45 offset -1,0 font ',10'\n");
    fprintf(gp, "set xlabel 'Tamanho do Vetor (N)' font ',14'\n");
    fprintf(gp, "set key top left\n");

    const char *caminho_csv = "'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/resultados.csv'";

    // 1. BUSCA BINÁRIA - O(log n)
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/01_busca_binaria.png'\n");
    fprintf(gp, "set title 'Busca Binaria: O(log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Media de Tempo (Microssegundos)' font ',14'\n");
    fprintf(gp, "f_bin(x) = a_bin * log(x) + b_bin\n");
    fprintf(gp, "fit f_bin(x) %s using 1:($3*10) via a_bin, b_bin\n", caminho_csv);
    fprintf(gp, "plot %s using 1:($3*10) with points pt 7 lc rgb 'purple' title 'Empirico', f_bin(x) with lines lw 3 lc rgb 'black' title 'Teorico O(log n)'\n", caminho_csv);

    // 2. BUSCA SEQUENCIAL - O(n)
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/02_busca_sequencial.png'\n");
    fprintf(gp, "set title 'Busca Sequencial: O(n)' font ',18'\n");
    fprintf(gp, "f_seq(x) = a_seq * x + b_seq\n");
    fprintf(gp, "fit f_seq(x) %s using 1:($2*10) via a_seq, b_seq\n", caminho_csv);
    fprintf(gp, "plot %s using 1:($2*10) with points pt 7 lc rgb 'orange' title 'Empirico', f_seq(x) with lines lw 3 lc rgb 'black' title 'Teorico O(n)'\n", caminho_csv);

    // 3. MERGE SORT - O(n log n)
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/04_merge_sort.png'\n");
    fprintf(gp, "set title 'Merge Sort: O(n log n)' font ',18'\n");
    fprintf(gp, "set ylabel 'Tempo Total (Segundos)' font ',14'\n");
    fprintf(gp, "f_merge(x) = a_mer * x * log(x) + b_mer\n");
    fprintf(gp, "fit f_merge(x) %s using 1:5 via a_mer, b_mer\n", caminho_csv);
    fprintf(gp, "plot %s using 1:5 with points pt 7 lc rgb 'blue' title 'Empirico', f_merge(x) with lines lw 3 lc rgb 'black' title 'Teorico O(n log n)'\n", caminho_csv);

    // 4. QUICK SORT - O(n log n)
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/05_quick_sort.png'\n");
    fprintf(gp, "set title 'Quick Sort: O(n log n)' font ',18'\n");
    fprintf(gp, "f_quick(x) = a_qui * x * log(x) + b_qui\n");
    fprintf(gp, "fit f_quick(x) %s using 1:6 via a_qui, b_qui\n", caminho_csv);
    fprintf(gp, "plot %s using 1:6 with points pt 7 lc rgb 'green' title 'Empirico', f_quick(x) with lines lw 3 lc rgb 'black' title 'Teorico O(n log n)'\n", caminho_csv);

    // 5. BUBBLE SORT - O(n^2)
    fprintf(gp, "set output 'C:/Users/gabriel/Documents/GitHub/EDB-I/TRABALHO-UNIDADE1/03_bubble_sort.png'\n");
    fprintf(gp, "set title 'Bubble Sort: O(n^2)' font ',18'\n");
    fprintf(gp, "f_bub(x) = a_bub * x**2 + b_bub * x + c_bub\n");
    fprintf(gp, "fit f_bub(x) %s using 1:4 via a_bub, b_bub, c_bub\n", caminho_csv);
    fprintf(gp, "plot %s using 1:4 with points pt 7 lc rgb 'red' title 'Empirico', f_bub(x) with lines lw 3 lc rgb 'black' title 'Teorico O(n^2)'\n", caminho_csv);

    _pclose(gp);
}