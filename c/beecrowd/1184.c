#include <stdio.h>

#define x 12
#define y 12

int main() {
  char caractere;
  float M[x][x], soma = 0;

  scanf("%c", &caractere);
  // preencher
  for (int i = 0; i < x; i++) {
    for (int ii = 0; ii < y; ii++) {
      scanf(" %f", &M[i][ii]);
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < i; j++) {
      soma += M[i][j];
    }
  }

  switch (caractere) {
  case 'S':
    printf("%.1f\n", soma);
    break;
  case 'M':
    soma /= 66;
    printf("%.1f\n", soma);
  }
  return 0;
}
