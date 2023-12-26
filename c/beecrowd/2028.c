#include <stdio.h>

int main() {
  int N, numeros, cases = 0;

  while (scanf("%d", &N) != EOF) {
    cases++;
    numeros = 1;
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < i; j++) {
        numeros++;
      }
    }

    printf("Caso %d: %d %s\n", cases, numeros,
           numeros > 1 ? "numeros" : "numero");

    printf("0");
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < i; j++) {
        printf(" ");
        printf("%d", i);
      }
    }
    printf("\n\n");
    scanf("%d", &N);
  }

  return 0;
}
