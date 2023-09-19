#include <stdio.h>
#include <windows.h>

#define len 10100
#define size 10

int main( )
{
    int matriz[len][size], i, j, pos=0, volta=0;
    char black=70;

    for(i=0, pos=0;i<len; i++)
    {
        for(j=0;j<size; j++)
        {
            if (j==pos)
            {
                matriz[i][j]=1;
                if (pos==size-1) 
                {
                volta=1;
                }
                if (pos==0)
                {
                    volta=0;
                }
            }
            else matriz[i][j]=0;
        }
        if (volta==1) pos--;
        else pos++;
    }
    for (i=0;i<len;i++)
    {
        for (j=0; j<size; j++)
        {
            for (int tempo=1; tempo<100000000; tempo++);
            if (matriz[i][j]==0) printf(" ");
            else printf("%c", black);
        }
        printf("\n");
        //sleep(1); 
    }
}