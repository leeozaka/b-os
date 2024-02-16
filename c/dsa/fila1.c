#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  int idade;
  char *nome;
} Data;

typedef struct no {
  Data dado;
  struct no *prox;
} No;

typedef struct fila {
  No *inicio;
  No *fim;
  int tamanho;
} Fila;

Fila *criarFila() {
  Fila *f = (Fila *)calloc(1, sizeof(Fila));
  return f;
}

void push(Fila **f, Data dados) {
  No *aux;
  No *novo = (No *)calloc(1, sizeof(No));
  novo->dado = dados;
  novo->prox = NULL;
  if ((*f)->tamanho == 0) {
    (*f)->inicio = novo;
    (*f)->fim = novo;
    (*f)->tamanho++;
    return;
  }

  if (dados.idade > 29) {
    if ((*f)->inicio->dado.idade < 30) {
      novo->prox = (*f)->inicio;
      (*f)->inicio = novo;
      (*f)->tamanho++;
      return;
    }

    aux = (*f)->inicio;
    while (aux->prox && aux->prox->dado.idade > 29)
      aux = aux->prox;
    novo->prox = aux->prox;
    aux->prox = novo;
    (*f)->tamanho++;
    return;
  }

  (*f)->fim->prox = novo;
  (*f)->fim = novo;
  (*f)->tamanho++;
}

void pop(Fila **f) {
  if ((*f)->tamanho == 0) {
    printf("Fila vazia\n");
    return;
  }

  No *aux = (*f)->inicio;
  (*f)->inicio = (*f)->inicio->prox;
  free(aux);
  (*f)->tamanho--;
}

void exibeFila(Fila *f) {
  No *aux = f->inicio;
  No *aux2 = f->inicio;
  printf("Tamanho: %d\n", f->tamanho);

  while (aux != NULL) {
    printf("%d ", aux->dado.idade);
    if (aux->prox != NULL)
      printf("-> ");
    aux = aux->prox;
  }
  printf("\n");

  while (aux2 != NULL) {
    printf("%s ", aux2->dado.nome);
    if (aux2->prox != NULL)
      printf("-> ");
    aux2 = aux2->prox;
  }
  printf("\n");
}

int main() {
  Fila *f = criarFila();

  push(&f, (Data){.idade = 37, .nome = "Joao"});
  push(&f, (Data){.idade = 25, .nome = "Ana"});
  push(&f, (Data){.idade = 21, .nome = "Maria"});
  push(&f, (Data){.idade = 36, .nome = "Claudia"});

  exibeFila(f);
  pop(&f);
  exibeFila(f);
}
