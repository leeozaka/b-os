#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define TF 101

int modulo(int valores[])
{
    int i,j,val,pos, cmp=0, maior=0,num[1]; 
    for (i=0; i<TF; i++)
    {
        for(j=0,maior=0;j<TF; j++)
        {
            if (valores[i]==valores[j])
            maior++;
        }
        if (maior>cmp)
        {
            val=valores[i];
            pos=i;
        }
    }
    num[0]=val;
    num[1]=pos;
    return num;
}

int main(void)
{ 
    int valores[TF], i, num[1];
    time_t t;
    srand((unsigned) time(&t));
    for (int i=0; i<TF; i++)
    {
        valores[i]=(rand()%200);
    }
    num[1]=modulo(valores[TF]);
    printf("%d %d", num[0], num[1]);
}