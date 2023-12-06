#include <stdio.h>
#include <stdlib.h>

typedef struct nome {
    char nome[50];
} Pessoa;

typedef struct no {
    Pessoa info;
    struct no *proximo;
} No;

No *push(No *topo) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        printf("Digite o nome: ");
        scanf("%s", &novo->info.nome);
        novo->proximo = topo;
        return novo;
    } else {
        printf("mem !alloc");
    }
    return NULL;
}

void pop (No **topo) {
    if (*topo != NULL) {
        No *pop = *topo;
        *topo = pop->proximo;
        free(pop);
    } 
}

int main() {
    No *topo = NULL;

    int i = 0;
    while (i < 3) {
        topo = push(topo);
        i++;
    }

    pop(&topo);

    while (topo != NULL) {
        printf("\n%s", topo->info.nome);
        topo = topo->proximo;
    }
    
    printf("\n\n\n");
    system("pause");
    system("cls");
    return 0;
}