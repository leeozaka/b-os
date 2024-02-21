#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *stream = fopen("ex1.txt", "r");
  assert(stream != NULL);

  char *c = (char*)calloc(1, sizeof(char));
  *c = (char)fgetc(stream);

  while (*c != EOF) {
    if (*c == '\n') {
      fputc('\n', stdout);
      *c = fgetc(stream);
      continue;
    }

    if (islower(*c)) {
      *c = toupper(*c);
      if (*c == 'A' || *c == 'E' || *c == 'I' || *c == 'O' || *c == 'U') {
        *c = '@'; 
      }
    }

    if (isspace(*c)){
      *c = '_';
    }

    fputc(*c, stdout);
    *c = fgetc(stream);
  }

  free(c);
  fclose(stream);
  return 0;
}
