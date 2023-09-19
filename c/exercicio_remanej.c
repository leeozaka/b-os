/* Ao ser fornecido um vetor e uma posicao, retire o elemento que esta nessa posicao e remaneje o vetor*/
#define TF 10
#include <stdio.h>
int main()
{
    int vetor[TF]={1,2,3,4,5,6,7,8,9,10};
    int i, j,TL;

    TL=sizeof(vetor)/sizeof(vetor[0]);

    printf("posicao que deseja remover de vetor1: ");
    scanf(" %d", &j);

    if(j<=TL&&j>=0)
    {
        for(i=j; i<TL; i++)
        {
            vetor[i]=vetor[i+1];
        }
        TL--;
    }
    for(i=0; i<TL; i++)
    {
        printf("%d ",vetor[i]);
    }
}