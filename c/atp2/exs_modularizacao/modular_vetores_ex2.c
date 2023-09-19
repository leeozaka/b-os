// Faça uma função que ao serem passados como parâmetros um vetor (máximo 100 elementos) e o seu tamanho lógico, retorne a soma de seus elementos.
#include <stdio.h>
#include <locale.h>
#define TF 100

int pass (int vet[], int TL)
{
    int soma=0;
    for (int i=0; i<TL; i++)
    {
        soma+=vet[i];
    }
    return soma;
}

int main()
{
    setlocale(LC_ALL, "pt-BR");

    int vet[TF], TL=0, i;
    do{
        scanf(" %d",&TL);
    } while(TL<0 && TL>100);

    for (i=0; i<TL; i++)
    {
        scanf(" %d", &vet[i]);
    }
    printf("%d", pass(vet,TL));
}