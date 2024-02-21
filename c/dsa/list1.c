#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  char *name;
  int age;
} Data;

typedef struct node {
  struct node *next;
  struct node *prev;
  Data data;
} Node;

typedef struct list {
  Node *head;
  int size;
} List;

List *newList() {
  List *list = (List *)calloc(1, sizeof(List));
  list->head = NULL;
  list->head->next = NULL;
  list->head->prev = NULL;
  list->head->data = (Data){.name = NULL, .age = 0};

  list->size = 0;
  return list;
}

void list_push(List **list, Data data) {
  Node *new = (Node *)calloc(1, sizeof(Node));
  new->data = data;
  new->next = NULL;
  new->prev = NULL;

  if ((*list)->head == NULL) {
    (*list)->head = new;
    (*list)->size++;
    return;
  }
}

int main(int argc, char *argv[]) {
  List *list = newList();
  list_push(&list, (Data){.name = "John", .age = 25});
}
