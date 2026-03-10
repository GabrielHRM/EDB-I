#include <stdio.h>

//Soma por recursão de cauda
int somaRC(int a, int b, int ac){
    if(b==0){
        return ac;
    }else{
        if(b>0){
            return somaRC(a, b-1, ac+1);
        }else{
            return somaRC(a, b+1, ac-1);
        }
    }
}

//Soma por iteração a partir da recursão em cauda
int somaIT(int a, int b, int ac){
    if(b>=0){
        while(b>0){
            ac+=1;
            b--;
        }
    }else{
        while(b<0){
            ac-=1;
            b++;
        }
    }
    return ac;
}


int main(){
    int op;
    /*digite 1, ou 2 para escolher entre recursão em cauda(1) ou
    iterativo a partir da recursão em cauda(2)*/
    scanf("%d", &op);
    //digite 2 numeros inteiros para a adição(soma)
    int a, b, resposta;
    scanf("%d %d", &a, &b);
    int ac = a;

    switch(op){
        case 1:
            resposta = somaRC(a, b, ac);
            printf("%d", resposta);
            break;
        case 2:
            resposta = somaIT(a, b, ac);
            printf("%d", resposta);
            break;
        default:
            break;
    }
    return 0;
}