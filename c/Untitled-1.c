#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define buffer 1002

int main() {
  int run, i = 0, j = 0;
  int index;
  int size;

  char str[buffer], straux[buffer], aux;
  scanf_s("%d", &run);

  while (i < run) {
    fflush(stdin);
    fgets(str, buffer, stdin);
    size_t ln = strlen(str) - 1;
    if (*str && str[ln] == '\n')
      str[ln] = '\0';
    size = strlen(str);

    for (int index = 0; index < size; ++index) {
      if (isalpha(str[index]))
        str[index] = str[index] + 3;
    }

    j = 0;
    for (int index = size - 1; index >= 0; j++, --index) {
      straux[j] = str[index];
    }
    straux[j] = '\0';

    for (index = size / 2; index < size; ++index) {
      --straux[index];
    }

    printf("%s\n", straux);
    ++i;
  }
  return 0;
}
