#include <stdio.h>

#define x 12
#define y 12

int main() {
  char caractere;
  double M[x][y], soma = 0;
  int elementos_lidos = 0;

  scanf("%c", &caractere);
  // preencher
  for (int i = 0; i < x; i++) {
    for (int ii = 0; ii < y; ii++) {
      scanf(" %lf", &M[i][ii]);
    }
  }

  for (int i = x - 1; i > (x / 2); i--) {
    for (int j = x - i; j < x - (x - i); j++) {
      soma += M[i][j];
      elementos_lidos++;
    }
  }

  switch (caractere) {
  case 'S':
    printf("%.1f\n", soma);
    break;

  case 'M':
    soma /= elementos_lidos;
    printf("%.1f\n", soma);
  }
  return 0;
}
