#include <stdio.h>

//Multiplicação por recursão de cauda
int multRC(int a, int b, int ac){
    if(b == 0){
        return ac;
    }else{
        return multRC(a, b-1, ac+a);
    }
}

//Multiplicaçãoo por iteração a partir da recursão em cauda
int multIT(int a, int b, int ac){
    while(b>0){
        ac+=a;
        b--;
    }
    return ac;
}


int main(){
    int op;
    /*digite 1, ou 2 para escolher entre recursão em cauda(1) ou
    iterativo a partir da recursão em cauda(2)*/
    scanf("%d", &op);
    //digite 2 numeros inteiros positivos para a multiplicação
    int a, b, resposta, ac = 0;
    scanf("%d %d", &a, &b);

    switch(op){
        case 1:
            resposta = multRC(a, b, ac);
            printf("%d", resposta);
            break;
        case 2:
            resposta = multIT(a, b, ac);
            printf("%d", resposta);
            break;
        default:
            break;
    }
    return 0;
}