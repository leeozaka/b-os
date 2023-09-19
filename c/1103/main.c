#include <stdio.h>

int main()
{
    int h1, h2, m1, m2, res, find; 
    
    scanf ("%d %d %d %d", &h1, &m1, &h2, &m2);
    while (h1+h2+m1+m2!=0)
    {
        if (h2<h1 || (h2==h1&&m2<m1)) h2+=24;
        printf("%d\n", (((h2*60+m2)-(h1*60+m1))));
        scanf ("%d %d %d %d", &h1 ,&m1 ,&h2, &m2);
    }
}