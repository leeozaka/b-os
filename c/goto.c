#include<stdio.h>

int main()
{
    int run=3, pass=0;
    incremento: pass++;
    if(pass<3) goto incremento;

    printf ("%d", pass);
}
