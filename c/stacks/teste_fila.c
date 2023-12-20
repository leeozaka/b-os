#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

struct no {
    int num;
    no* prox;
};

// null then 1 then \/
// 1 -> 2 -> 3 -> null

void new_element(no** fila, int element) {
    no* novo = (no*)calloc(1, sizeof(no));
    no* aux;
    if (novo) {
        novo->num = element;
        novo->prox = NULL;
        if (*fila == NULL)
            *fila = novo;
        else {
            aux = *fila;
            while (aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
    } else
        printf("allc error\n");
}
void remove_fila(no** fila) {
    no* remove = (no*)calloc(1, sizeof(no));
    if (remove) {
        remove = *fila;
        *fila = remove->prox;
        free(remove);
    }
}

int main() {
    no* fila = NULL;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        new_element(&fila, i + 1);
    }

    no* aux = fila;
    while (aux) {
        printf("%d", aux->num);
        printf("%s", aux->prox ? " -> " : ".");
        aux = aux->prox;
    }
    printf("\n\n");

    remove_fila(&fila);
    remove_fila(&fila);
    remove_fila(&fila);

    aux = fila;
    while (aux) {
        printf("%d", aux->num);
        printf("%s", aux->prox ? " -> " : ".");
        aux = aux->prox;
    }
}