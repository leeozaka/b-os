#include <strings.h>
#include <stdio.h>

int main()
{
    char um[20], dois[20];
    strcpy(um, "bia"); strcpy(dois, "aaaaaaaaaaaaaa");
    int res = stricmp(um, dois);
    printf("%d", res);
}