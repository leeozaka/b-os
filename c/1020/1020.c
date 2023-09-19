#include <stdio.h>
#include <string.h>
#define SIZE 102

int main()
{
    char res[SIZE], cmp[SIZE], delete, dump;
    int make, len, j, i, nmr, tlres, aux;

    //FILE *read = fopen("read_debug.txt", "r");
    //FILE *write = fopen("write_debug.txt", "w");

    //fscanf(read, "%c %s%c", &delete, &cmp, &dump);
    scanf("%c", &delete);
    fflush(stdin);
    do
    {
        strcpy(res, "0");
        //fgets(cmp, SIZE, read);
        gets(cmp);

        len = strlen(cmp);
        //cmp[len]='\0';
        for(i=0, tlres=0; i<len; i++)
        {
            if (cmp[i]!=delete&&cmp[i]!='\0')
            {
                res[tlres]=cmp[i];
                tlres++;
            }
        }
        if(tlres>0) res[tlres]='\0';
        for (i=0;res[i]=='0';i++);
        for (j=0;res[i]!='\0';i++)
        {
            if (res[j]!='0')j++;
            res[j]=res[i];
        }
        if(j>0) res[j]='\0';
        /*for (i = 0; i < len;)
        {
            if (delete == cmp[i])
            {
                for (j = i; j < len; j++)
                {
                    cmp[j] = cmp[j + 1];
                }
                len--;
            }
            else i++; 
        }
        */

        /*for(i=0, nmr=0;i<len-1; i++)
        {
            nmr+=cmp[i]-48;
        }
        */
        printf("%s\n", res);
        //fprintf(write, "%s\n", res);
        /*if (nmr == 0){
            fprintf(write, "%d\n", nmr);
            //printf("%d\n", nmr);
        } else {   
            fputs(cmp, write);
            //puts(cmp);
        } */
        //fscanf(read, "%c %s%c", &delete, &cmp, &dump);
        scanf("%c", &delete);
        fflush(stdin);
        nmr=0;
    } while (delete != '0');
    //fprintf(write,"%d\n",nmr);
    printf("0\n");
    //fclose(write);fclose(read);
    return 0;
}