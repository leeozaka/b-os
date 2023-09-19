//Faça uma função em C, que receba 6 valores inteiros representando um horário inicial (HH,MM,SS) 
//e  horário final (HH,MM,SS) e retorne a diferença em segundos. 
#include <stdio.h>

int calc (int h1, int m1, int s1, int h2, int m2, int s2)
{
    int res;
    return ((h2*3600+m2*60+s2)-(h1*3600+m1*60+s1));
}

int main()
{   
    int h1, m1, s1, h2, m2, s2;
    scanf(" %d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
    printf("%d", calc(h1, m1, s1, h2, m2, s2));
}