#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 26

typedef struct TrieNode TrieNode;

struct TrieNode {
  int quant;
  TrieNode *children[N];
};

TrieNode *make_trienode(char data) {
  TrieNode *node = (TrieNode *)calloc(1, sizeof(TrieNode));
  for (int i = 0; i < N; i++)
    node->children[i] = NULL;
  node->quant = 0;
  return node;
}

TrieNode *insert_trie(TrieNode *root, char *word) {
  TrieNode *temp = root;

  for (int i = 0; word[i] != '\0'; i++) {
    int idx = (int)word[i] - 'a';
    if (temp->children[idx] == NULL) {
      temp->children[idx] = make_trienode(word[i]);
    }
    temp->quant++;
    temp = temp->children[idx];
  }
  return root;
}

int search_trie(TrieNode *root, char *word) {
  TrieNode *temp = root;

  for (int i = 0; word[i] != '\0'; i++) {
    int position = word[i] - 'a';
    if (temp->children[position] == NULL)
      return 0;
    temp = temp->children[position];
  }
  if (temp != NULL)
    return temp->quant;
  return 0;
}

int main() {
  TrieNode *root = make_trienode('\0');
  int run;
  char arg1[5];
  char arg2[22];
  scanf("%d", &run);
  for (int i = 0; i < run; i++) {
    scanf("%s%s", &arg1, &arg2);
    if (!strcmp(arg1, "add"))
      root = insert_trie(root, arg2);
    else
      printf("%d\n", search_trie(root, arg2));
  }

  return 0;
}
