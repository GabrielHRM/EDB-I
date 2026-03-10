#include <stdio.h>

//Fatorial por recursão de cauda
int fatRC(int n, int ac){
    if(n == 1){
        return ac;
    }else{
        return fatRC(n-1, ac*n);
    }
}

//Fatorial por iteração a partir da recursão em cauda
int fatIT(int n, int ac){
    while(n>0){
        ac*=n;
        n--;
    }
    return ac;
}

int main(){
    int op;
    /*digite 1, ou 2 para escolher entre recursão em cauda(1) ou
    Iterativo a partir da recursão em cauda(2)*/
    scanf("%d", &op);
    //digite 1 número inteiro positivo
    int n, resposta, ac = 1;
    scanf("%d", &n);

    switch(op){
        case 1:
            resposta = fatRC(n, ac);
            printf("%d", resposta);
            break;
        case 2:
            resposta = fatIT(n, ac);
            printf("%d", resposta);
            break;
        default:
            break;
    }
    return 0;
}