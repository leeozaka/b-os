#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
typedef struct no No;

struct fila {
  int size;
  No *primeiro;
  No *ultimo;
};

struct no {
  int elemento;
  No *prox;
};

Fila *create_fila() {
  Fila *new_fila = (Fila *)malloc(sizeof(Fila));
  new_fila->size = 0;
  new_fila->primeiro = NULL;
  new_fila->ultimo = NULL;
  return new_fila;
}

void push_to_fila(Fila *fila, int numero) {
  No *new_element = (No *)calloc(1, sizeof(No));
  if (new_element) {
    new_element->elemento = numero;
    if (!fila->primeiro) {
      fila->primeiro = new_element;
      fila->ultimo = new_element;
    } else {
      fila->ultimo->prox = new_element;
      fila->ultimo = new_element;
    }
    fila->size++;
  }
}

void remove_from_fila(Fila *fila) {
  No *remove_element = (No *)calloc(1, sizeof(No));
  No *aux = (No *)calloc(1, sizeof(No));
  if (remove_element) {
    remove_element = fila->primeiro;
    fila->primeiro = remove_element->prox;
    free(remove_element);
    fila->size--;
  }
}

int main() {
  Fila *fila1 = create_fila();
  No *aux;
  for (int i = 0; i < 10; i++)
    push_to_fila(fila1, i + 1);

  aux = fila1->primeiro;
  printf("\t%d tam \n", fila1->size);
  while (aux) {
    printf("%d ", aux->elemento);
    aux = aux->prox;
  }

  remove_from_fila(fila1);
  remove_from_fila(fila1);

  aux = fila1->primeiro;
  printf("\n\t%d new_tam\n", fila1->size);
  while (aux) {
    printf("%d ", aux->elemento);
    aux = aux->prox;
  }

  return 0;
}
