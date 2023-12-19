// João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

#include <bits/stdc++.h>

#define maxsize 1001

struct no {
    char elemento;
    no *prox;
};

no *push(no *topo, char novo_char) {
    no *novo_topo = (no *)malloc(sizeof(no));
    if (!novo_topo) return NULL;
    novo_topo->elemento = novo_char;
    novo_topo->prox = topo;
    return novo_topo;
}
void pop(no **topo) {
    no *remover = (no *)malloc(sizeof(no));
    if (!remover) return;

    remover = *topo;
    *topo = remover->prox;
    free(remover);
}

int main() {
    no *pilha = NULL;
    int i = 0, pares = 0, n;

    scanf("%d", &n);

    for (int run = 0; run < n; run++) {
        fflush(stdin);
        std::string input;
        std::cin >> input;
        i = 0;

        for (auto input : input) {
            if (input == '<') {
                pilha = push(pilha, input);
            }
            if (input == '>' && pilha) {
                pop(&pilha);
                pares++;
            }
        }

        printf("%d\n", pares);
        pares = 0;
        while (pilha) {
            pop(&pilha);
        }
    }
}