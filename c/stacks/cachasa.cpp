#include <stdio.h>
#include <stdlib.h>

void inverte(FILE *origem, FILE * destino) {
    char linha[101];
    if (!feof(origem)){
        fgets(linha,100,origem);
        inverte(origem,destino);
        fprintf(destino,linha);
    }
}


int main() {
    FILE * arquivo = fopen ("texto.txt", "r+");
    FILE * destino = fopen ("saida.txt", "w");
    inverte(arquivo, destino);
}