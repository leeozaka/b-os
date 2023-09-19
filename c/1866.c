#include <stdio.h>

int main()
{
    int run, cas;
    scanf("%d", &run);
    for (int i = 0; i<run; i++)
    {
        scanf ("%d", &cas);
        fflush(stdin);
        if (cas%2==0) printf("0\n");
        else printf("1\n");
    }

    return 0;
}