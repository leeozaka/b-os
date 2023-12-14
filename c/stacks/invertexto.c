#include <stdio.h>
#include <stdlib.h>
#include <conio3.h>

typedef struct no {
    char letra;
    struct no *prox;
} No;

No *empilhar(char letra_nova, No *topo) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo) {
        novo->letra = letra_nova;
        novo->prox = topo;
        return novo;
    }
    printf("alloc error ");
    return NULL;
}

No *desempilhar(No **topo) {
    if (topo) {
        No *remover = *topo;
        *topo = remover->prox;
        return remover;
    }
    printf("alloc error");
    return NULL;
}

void invertexto(char palavra[]) {
    No *pilha = NULL;
    No *remover;
    int i = 0;
    while (palavra[i] != '\0') {
        while (palavra[i] != ' ' && palavra[i] != '\0') {
            pilha = empilhar(palavra[i], pilha);
            i++;
        }
        if (palavra[i] == ' ') i++;
        while (pilha) {
            remover = desempilhar(&pilha);
            printf("%c", remover->letra);
            free(remover);
        }
        printf(" ");
    }
    printf("\n");
    getch();
}

int main() {
    clrscr();
    char palavra[] = {"Uma grande serie de palavras para que o stack tenha trabalho de corrigir tudo"};
    invertexto(palavra);
}