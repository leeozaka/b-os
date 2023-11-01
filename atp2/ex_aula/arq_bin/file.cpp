//{ A comissão organizadora de um rallye automobilístico decidiu apurar os resultados da
// competição por meio de um processamento eletrônico. Um dos programas necessários para a
// classificação das equipes competidoras é o que emite uma listagem geral do desempenho das
// equipes, atribuindo pontos segundo determinadas regras. O programa receberá como
// informações: os tempos-padrão (em minutos) para as três etapas da competição, e; um conjunto
// de linhas contendo o número da inscrição da equipe e os tempos (em minutos) que as mesmas
// despenderam ao cumprir as três diferentes etapas. Os pontos das equipes em cada uma das
// etapas são calculados pelo valor da diferença (Z) entre o tempo-padrão e o tempo despendido
// pela equipe em uma etapa. Se Z < 3 minutos atribuir 100 pontos à etapa; Se 3 <= Z <= 5
// minutos atribuir 80 pontos à etapa; Se Z > 5 minutos atribuir 80–((z-5)/5) pontos à etapa. Faça
// um módulo que ao receber o tempo padrão e o número de uma etapa retorne o total de pontos
// obtido pelas equipes. Ao final o programa deverá exibir o total de pontos de cada equipe em
// cada etapa e o total de pontos geral de cada equipe, bem como, a equipe vencedora.
//}

#include <stdio.h>
#include <stdlib.h>

struct Main
{
    int varname;
    size_t tester;
};

int main()
{
    Main str[20];
    FILE *fh = fopen ("file.bin", "wb");
    if (fh != NULL) {
        fwrite(&str,sizeof(Main),203,fh);
        fclose (fh);
    }
}