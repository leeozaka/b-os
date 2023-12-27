#include <stdio.h>
#include <string.h>

#define BUFFER 10

int main() {
  int N, i = 0;
  char palavra1[BUFFER], palavra2[BUFFER];

  scanf("%d", &N);
  while (i < N) {
    scanf("%s %s", &palavra1, &palavra2);

    if (!strcmp(palavra1, palavra2))
      printf("Caso #%d: De novo!\n", i+1);
    else if (!strcmp(palavra1, "pedra")) {
      if ((!strcmp(palavra2, "tesoura")) || (!strcmp(palavra2, "lagarto"))) {
        printf("Caso #%d: Bazinga!\n", i + 1);
      } else
        printf("Caso #%d: Raj trapaceou!\n", i + 1);
    } else if (!strcmp(palavra1, "papel")) {
      if (!strcmp(palavra2, "pedra") || !strcmp(palavra2, "Spock")) {
        printf("Caso #%d: Bazinga!\n", i + 1);
      } else
        printf("Caso #%d: Raj trapaceou!\n", i + 1);
    } else if (!strcmp(palavra1, "tesoura")) {
      if (!strcmp(palavra2, "papel") || !strcmp(palavra2, "lagarto")) {
        printf("Caso #%d: Bazinga!\n", i + 1);
      } else
        printf("Caso #%d: Raj trapaceou!\n", i + 1);
    } else if (!strcmp(palavra1, "lagarto")) {
      if (!strcmp(palavra2, "papel") || !strcmp(palavra2, "Spock")) {
        printf("Caso #%d: Bazinga!\n", i + 1);
      } else
        printf("Caso #%d: Raj trapaceou!\n", i + 1);
    } else if (!strcmp(palavra1, "Spock")) {
      if (!strcmp(palavra2, "tesoura") || !strcmp(palavra2, "pedra")) {
        printf("Caso #%d: Bazinga!\n", i + 1);
      } else
        printf("Caso #%d: Raj trapaceou!\n", i + 1);
    }
      i++;
  }
}