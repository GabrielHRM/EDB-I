#include "teste_empirico.h"
#include "algoritimosdebusca.h"
#include "algoritimosort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    int *v = (int *)malloc(100000 * sizeof(int));

    teste_tempo(v);

    free(v);
    
    return 0;
}