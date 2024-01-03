#include <stdio.h>
#include <string.h>

int main() {

  char tweet[500];
  scanf("%[^\n]s", tweet);

  if (strlen(tweet) <= 140) {
    printf("TWEET\n");
  } else {
    printf("MUTE\n");
  }

  return 0;
}