#include <math.h>
#include <stdio.h>

int potencia2(short int expoente) {
  int resposta = 1;
  if (expoente == 0)
    return 1;
  while (expoente--) {
    resposta += resposta;
  }
  return resposta;
}

int maiorTamanho(int t) {
  int maiorNumero = potencia2(t + t - 2);
  int digitos = 1;
  while (maiorNumero > 9) {
    maiorNumero /= 10;
    digitos++;
  }
  return digitos;
}

int main() {
  int N, caracteres;

  while (N > 0) {
    scanf("%d", &N);

    caracteres = maiorTamanho(N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%*d", caracteres, (int)pow((double)2, j + i));
      }
      printf("\n");
    }

    printf("\n");
    scanf("%d", &N);
  }
  return 0;
}
