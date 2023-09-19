#include <stdio.h>
#include <stdlib.h>

int main(){
    /*ptr = &a;
    printf("%x ", ptr);
    printf("%d ", *ptr); 
    *ptr = 23; 
    printf("%d ", *ptr); */ 

    /*int* v = (int*)malloc(sizeof(int) * 2);
    v[0]=1;
    v[1]=2;
    v[2]=3;
    v[3]=4;
    printf("%d %d %d %d", v[0], v[1], v[2], v[3]);
    printf(" %d",(sizeof(v)));
    printf(" %x", &v[4]); */
    int a, vet[]={};
    int * ptr;
    int ** ref;

    ref = &ptr;

    scanf("%d", &a);
    ptr = (int*)malloc(a*sizeof(int));
    if (ptr == NULL)
    {
        printf("mem_not_allocated");
    }
    else {
        for (int i=0; i<a; i++)
        {
            scanf("%d", &ptr[i]);
        }
        free(ptr);
        printf("\n");
        for (int i=0; i<a; i++)
        {
            printf(" %d", ptr[i]);
        }
        printf(" -- %d", sizeof(ptr));
        printf(" -- %x", &ref);
    }

}