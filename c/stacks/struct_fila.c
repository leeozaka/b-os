#include <stdio.h>
#include <stdlib.h>

typedef struct no no;
typedef struct fila fila;

struct no {
    int num;
    no* prox;
};

struct fila {
    no* primeiro;
    no* ultimo;
    int size;
};

void criar_fila(fila* fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->size = 0;
}

void new_element(fila* fila, int elemento) {
    no* novo = (no*)calloc(1, sizeof(no));
    if (novo) {
        novo->num = elemento;
        novo->prox = NULL;
        if (fila->primeiro == NULL) {
            fila->primeiro = novo;
            fila->ultimo = novo;
        } else {
            fila->ultimo->prox = novo;
            fila->ultimo = novo;
        }
        fila->size++;
    } else
        printf("allc error\n");
}

void remove_fila(fila* fila) {
    no* remove = (no*)calloc(1, sizeof(no));
    if (remove) {
        if (fila->primeiro) {
            remove = fila->primeiro;
            fila->primeiro = remove->prox;
            fila->size--;
            free(remove);
        }
    }
}
void imprimir(fila* fila) {
    no* aux = fila->primeiro;
    while (aux) {
        printf("%d", aux->num);
        printf("%s", aux->prox ? " -> " : ".");
        aux = aux->prox;
    }
}

int main() {
    fila fila;
    int N;
    criar_fila(&fila);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        new_element(&fila, i + 1);
    }

    imprimir(&fila);

    remove_fila(&fila);
    printf("\n");
    imprimir(&fila);

    remove_fila(&fila);
    printf("\n");
    imprimir(&fila);
    
    remove_fila(&fila);
    printf("\n");
    imprimir(&fila);

    remove_fila(&fila);
    printf("\n");
    imprimir(&fila);

    return 0;
}