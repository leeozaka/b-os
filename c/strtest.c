#include<stdio.h>
#include<string.h>

#define SIZE 1100

int check (char string)
{
    char alf[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    int aux, i;
    for(i=0;i<53&&string!=alf[i];i++);
    if (i==53) return 1; else return 0;
}

int par(int i)
{
    float x;
    x=i%2; if (x==0) return 1; else return -1;
}

char P1 (char *string, int strlen)
{
    char stringaux[strlen+1];
    int j, i, aux, part;
    for(i=0; i<strlen; i++)
    {
        if (check(string[i])==0) string[i]+=3;

    }
    for (i=0, j=strlen-1; i<=strlen; i++, j--)
    {
        stringaux[i]=string[j];
        if (i==strlen) stringaux[i]='\0';
    }
    strcpy(string,stringaux);
    part=par(strlen);
    if(part==1)
    {                          
        for(i=(strlen/2);i<strlen;i++)
        {
           if (string[i]!=32) string[i]-=1;
        }
    } else if (part==-1)
    {
        for(i=((strlen-1)/2);i<strlen;i++)
        {
            if (string[i]!=32) string[i]-=1;
        }
    }
}

int main()
{
    char string[SIZE]; 
    int i, step=0;
    long run;
    
    FILE *fp = fopen("debug.txt", "r");
    FILE *fz = fopen("out.txt", "w");

    fscanf(fp,"%li",&run);
    //scanf("%li", &run);
    fflush(stdin);
    while (step<run)
    {
        //fscanf (fp, "%s", string);
        fgets(string, SIZE, fp);
        //gets(string);
        //fflush(stdin);
        i=strlen(string);
        P1(string, i);
        //printf("%s\n", string);
        fputs(string, fz);
        step++;
    }
    fclose(fp); fclose(fz);
    return 0;
}