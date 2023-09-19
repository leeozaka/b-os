//Retorne no 3º vetor os elementos que estão no 1º vetor, mas não estão no 2º. 
//Os elementos que irão compor o 3º vetor não devem ser repetidos, mas podem estar repetidos no 1º e no 2º (Subtração de Conjuntos);
//Retorne no 3º vetor os elementos que são comuns entre o 1º e o 2º vetor. 
//Os elementos que irão compor o 3º vetor não devem ser repetidos, mas podem estar repetidos no 1º e no 2º (Intersecção de Conjuntos);
//Suponha que o 1º e o 2º vetor estão ordenados, retorne no 3º vetor todos os elementos do 1º e do 2º vetor, 
//conservando a ordenação dos elementos no 3º vetor. A inserção de novos elementos no 3º vetor deve ser feita sempre pelo FIM e não pelo MEIO. 
//O número de comparações para cada inserção deve ser mínimo. Esse processo de juntar duas listas ordenadas chama-se MERGE.

#include <stdio.h>
#include <time.h>
#include <math.h>

#define TF 7
#define MAXLEN 100

int caseone (int vet1, int vet2[],int TL)
{
    int pass, i, find,TL2=0;
    find=0;
    for (i=0; i<TL; i++)
    {
        if (vet1 == vet2[i]) find++;
    }
    if (find == 0) return vet1;
    else return NULL;
}

int main()
{
    //int vet1[TF], vet2[TF], vet3[TF], TL;
    int vet1[]={1, 3, 5, 7, 9, 10, 11}, vet2[]={0, 2, 4, 6, 8, 10, 12},vet3[TF], TL;

    /*srand((unsigned)time(NULL));
    for(int i=0;i<TF;i++)
    {
        vet1[i]=(rand()%MAXLEN);
        vet2[i]=(rand()%MAXLEN);
    }
    */

    TL=0;
    for (int i=0; i<TF; i++)
    {
        if(caseone(vet1[i], vet2, TF)!=NULL)
        {
            vet3[TL]=vet1[i];TL++;
        }
    }
    for (int i=0; i<TL; i++)
    {
        printf ("%d ", vet3[i]);
    }
    printf("\n");
    //system("PAUSE");

}