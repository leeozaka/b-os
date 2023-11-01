#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define buffer 1002

int main()
{
    int run, i = 0;
    int index;
    int size;

    char str[buffer], straux[buffer], aux;
    scanf("%d", &run);

    while (i < run)
    {
        fflush(stdin);
        // fgets(str, buffer, stdin);
        scanf("%[^\n]\n", &str);
        size = strlen(str) - 1;

        for (int index = 0; index <= size; ++index)
        {
            if (isalpha(str[index]))
                str[index] = str[index] + 3;
        }

        for (int index = 0; index < size / 2; ++index)
        {
            aux = str[index];
            str[index] = str[size - 1 - index];
            str[size - 1 - index] = aux;
        }

        for (index = size / 2; index < size; ++index)
        {
            --str[index];
        }

        printf("%s\n", str);
        ++i;
    }
    return 0;
}
