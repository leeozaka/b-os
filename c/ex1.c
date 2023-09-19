#include <stdio.h>
#include <time.h>

#define TF 12 

int main()
{
    int matriz1[TF][TF], i, j,menor,media,posx,posy, cont2=0;
    int aux=2,cont;

    time_t tempo; //preenchimento aleatorio com seed definida
    srand((unsigned) time(&tempo));
    
    for(i=0;i<TF;i++)
    {
        for(j=0;j<TF;j++)
        {
            matriz1[i][j]=(rand()%1000);
        }
    }

    menor=matriz1[0][11];posx=0;posy=11;//menor elemento começa de linha 0
    media=menor;
    for(j=1;j<TF;j++) //leitura de todas as linhas 
    {   
        for(i=TF-1,cont=TF-aux;i>=cont;i--) //condicional para ler apenas os elementos relevantes
        {
            media+=matriz1[j][i];
            if(matriz1[j][i]<menor)
            {
                menor=matriz1[j][i];
                posx=j;posy=i;
            }
        }
        aux++;
    }
    j=1;
    while(j<TF) //contador de casas sublinhadas
    {
        cont2+=j;
        j++;
    }
    media=media/cont2;
    printf("%d em %d %d c/ media %d\n", menor, posx, posy, media); 
}