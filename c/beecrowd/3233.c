#include <stdio.h>

int main() {
  int N, i = 0, cont = 0;
  scanf("%d", &N);

  while (i < N) {
    int pi, ri, ci;
    scanf("%d %d %d", &pi, &ri, &ci);

    if (pi >= 0 && pi <= N) {
      if (ri >= 0 && ri <= 100) {
        if (ci > 0 && ci <= 100) {
          cont++;
        }
      }
    }

    i++;
  }

  printf("%d\n", cont);
  return 0;
}
