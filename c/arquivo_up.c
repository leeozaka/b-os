#include <stdio.h>
#define PI 3.14159

float raio()
{
    float area, raio;
    printf("Insira o raio: ");
    scanf(" %f",&raio);
    area=PI*(raio*raio);
    printf("Raio: %.2f\n", area);
}

float div()
{
    float i, j, res;
    printf("Elemento a entrar na divisao: ");
    scanf (" %f", &i);
    printf("Elemento 2: ");
    scanf(" %f",&j);
    res=i/j;
    printf("Resposta: %.2f\n", res);
}

float soma()
{
    float i, j;
    printf("Elemento a entrar na soma: ");
    scanf(" %f", &i);
    printf("Elemento 2: ");
    scanf(" %f", &j);
    printf("%.1f\n", i+j);
}

int menu()
{
    printf("----Menu-----");
    printf("\nOpcao 1 - Soma");
    printf("\nOpcao 2 - Divisao");
    printf("\nOpcao 3: Area do Circulo");
    printf("\n");
    fflush(stdin);
    int i; scanf(" %d",&i);
    printf("\n");
    if (i>0 && i<4) return i;
    else printf("Opcao invalida");
}

int main()
{
    int i;
    do 
    {
        i=menu();
        switch (i)
        {
        case 1:
            soma();
            break;
        
        case 2:
            div();
            break;
        case 3:
            raio();
            break;

        default:
            break;
        }
    } while (i>0&&i<4);
    return 0;
}