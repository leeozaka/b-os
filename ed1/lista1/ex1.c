// Gere uma espécie de criptografia, que ao receber um arquivo texto, retorne em
// outro arquivo o texto codificado. Invente sua técnica!

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline char hash(char c, uint32_t token) { return (c + token); }
inline char unhash(char c, int token) { return (c - token); }

int main() {
  FILE *stream = fopen("ex1.txt", "r");
  assert(stream != NULL);

  FILE *stream2 = fopen("ex1_cript.txt", "w");
  FILE *stream3 = fopen("ex1_decript.txt", "w");
  char *token = (char *)calloc(64, sizeof(char));

  fputs("Digite a chave para criptografar: ", stdout);
  scanf("%s", token);

  uint32_t value = 0;
  while (*token) {
    value += *token++;
  }

  char c;
  while ((c = fgetc(stream)) != EOF) {
    fputc(hash(c, value), stream2);
  }

  fclose(stream);
  fclose(stream2);

  fputs("Digite a chave para descriptografar: ", stdout);
  scanf("%s", token);

  value = 0;
  while (*token) {
    value += *token++;
  }

  stream2 = fopen("ex1_cript.txt", "r");
  while ((c = fgetc(stream2)) != EOF) {
    fputc(unhash(c, value), stream3);
  }

  fclose(stream2);
  fclose(stream3);
  return 0;
}
