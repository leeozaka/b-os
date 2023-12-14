#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *proximo;
} No;

No *push(No *topo, int x) {
    No *aux = (No *)malloc(sizeof(No));
    if (aux) {
        aux->num = x;
        aux->proximo = topo;
        return aux;
    } else {
        printf("alloc error\n");
    }
    return NULL;
}

No *pop(No **topo) {
    No *remover = (No *)malloc(sizeof(No));

    if (remover) {
        remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else {
        printf("erro alocacao\n");
    }
    return NULL;
}

void exibepilha(No *topo) {
    printf("Pilha: \n");
    while (topo) {
        printf("\t%d\n", topo->num);
        topo = topo->proximo;
    }
}

void fatorial(int x) {
    No *remover, *estrutura = NULL;

    while (x > 1) {
        estrutura = push(estrutura, x);
        x--;
    }

    exibepilha(estrutura);

    while (estrutura) {
        remover = pop(&estrutura);
        x = x * remover->num;
        free(remover);
    }
    printf("Resultado: %d", x);
}

int main() {
    int numero;

    system("cls");
    printf("Numero: ");
    scanf("%d", &numero);
    fatorial(numero);
}