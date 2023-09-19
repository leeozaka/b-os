#include <stdio.h>

int main()
{
    int vet[20], i, TL=20, delete;
    delete = 5;
    for (i=0;i<20;i++)
    vet[i]=i;

    i=0;
    while (i<20 && delete!=vet[i])
    {
        i++;
    }
    if (delete==vet[i])
    {
        for(;i<20;i++)
        {
            vet[i]=vet[i+1];
        }
        TL--;
    }
    for (i=0; i<TL; i++)
    {
        printf("%d ", vet[i]);
    }
    return 0;
}
