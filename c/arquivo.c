/* Area do circulo: PI*Raio^2 */
#include <stdio.h>
#define PI 3.14159265358979323846

float soma(float raio)
{
    return PI*raio*raio;
}

int main()
{
    printf("Area do Circulo: Digite o Raio a ser calculado: ");
    float raio; scanf(" %f", &raio);
    printf("Area do Circulo: %f\n", soma(raio));
    system("pause");
}