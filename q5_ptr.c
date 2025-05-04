// Sort by Length
// Uso obrigatório de uma struct
// para representar palavras e seu tamanho, utilizando funções para
// ordenação e exibição, com manipulação via ponteiros e alocação dinâmica
// para o vetor de palavras.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int tamanho;
    char palavra[51];
    int posicao_palavra;
} Palavras;

void ordenar_palavras(Palavras *p, int qtd_palavras) {
    for (int i = 0; i < qtd_palavras - 1; i++) {
        for (int j = i + 1; j < qtd_palavras; j++) {
            if (p[i].tamanho < p[j].tamanho || 
                (p[i].tamanho == p[j].tamanho && p[i].posicao_palavra > p[j].posicao_palavra)) {
                Palavras t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

void exibir_palavras(Palavras *p, int qtd_palavras) {
    for (int i = 0; i < qtd_palavras; i++) {
        printf("%s", p[i].palavra);
        if (i < qtd_palavras - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int casos;
    scanf("%d", &casos);
    getchar();

    char todas_palavras[201];

    for (int i = 0; i < casos; i++) {
        scanf(" %[^\n]", todas_palavras);

        Palavras *p = malloc(50 * sizeof(Palavras));
        if (p == NULL) {
            fprintf(stderr, "errro");
            return 1;
        }

        int qtd_palavras = 0;

        char *palavra_separada = strtok(todas_palavras, " ");
        while (palavra_separada != NULL && qtd_palavras < 50) {
            strncpy(p[qtd_palavras].palavra, palavra_separada, 50);
            p[qtd_palavras].palavra[50 - 1] = '\0';

            p[qtd_palavras].tamanho = strlen(p[qtd_palavras].palavra);
            p[qtd_palavras].posicao_palavra = qtd_palavras;

            qtd_palavras++;
            palavra_separada = strtok(NULL, " ");
        }

        ordenar_palavras(p, qtd_palavras);
        exibir_palavras(p, qtd_palavras);

        free(p);
    }

    return 0;
}
