/*Dizemos que um número i inteiro positivo é perfeito, se este número for igual à soma dos seus divisores próprios. Dado um número natural, verificar se ele é perfeito ou não-perfeito. Exemplo: 6 é perfeito , pois, 1+2+3=6. */
#include <math.h>
#include <stdio.h>

bool Tester (int x){
    int i=1, soma=0;
    while(i<x)
    {
        if(x%i==0)
            soma=soma+i;
        i++;
    }
    return soma==x ? true : false;
}

int main(){
    int num; bool res;
    scanf(" %d", &num);
    Tester(num)==true ? printf("Perfeito") : printf("Nao-perfeito");

    return 0;
}
