/*Faça um módulo que ao ser passado como parâmetro um vetor contendo valores inteiros (máximo 100 elementos), retorne, via parâmetro, qual valor que aparece no vetor com maior freqüência e quantas vezes ele aparece. */
#define TF 100

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int regra(const void *a, const void *b){
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int turn(int arr[], size_t strsize){
    qsort(arr,strsize,sizeof(int),regra);
}


int DecToBin(size_t decimal){
    int bin=0, i=1;
    while (decimal!=0){
        bin+= (decimal % 2) * i;
        decimal = decimal/2;
        i = i*10;
    }
    return bin;
}

int GetNumber(){
    int i;
    scanf("%d", &i);
    return i;
}

void Menu(){
    char res;
    printf("Menu> A - DecToBin");
    scanf("%c", &res);
    switch (res)
    {
    case 'A':
        printf("%d",DecToBin(GetNumber()));
        break;
    }
}

int main(){
    Menu();
    return 0;
}