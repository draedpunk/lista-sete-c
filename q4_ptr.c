//Number Frequency
// Uso obrigatório
// de uma struct para representar números e suas frequências, utilizando
// funções para contagem e impressão, com ponteiros para manipulação e
// alocação dinâmica do vetor.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    int frequencia;
} Numeros;

void contar_aparicoes(int c, Numeros *conj_numeros) {
    for (int i = 0; i < c; i++) {
        int contado = 0;
        
        for (int j = 0; j < i; j++) {
            if (conj_numeros[i].numero == conj_numeros[j].numero) {
                contado = 1;
                break;
            }
        }
        if (contado) {
            continue;
        }

        int qtd_aparicoes = 0;
        for (int j = 0; j < c; j++) {
            if (conj_numeros[i].numero == conj_numeros[j].numero) {
                qtd_aparicoes++;
            }
        }
        conj_numeros[i].frequencia = qtd_aparicoes;



        printf("%d aparece %d vez(es)\n", conj_numeros[i].numero, conj_numeros[i].frequencia);

    }
}

int main() {
    int casos;
    scanf("%d", &casos);

    Numeros *num = malloc(casos * sizeof(Numeros));

    if (num == NULL) {
        printf("Erro na alocacao de memoria!!\n");
        return 1;
    }

    for (int i = 0; i < casos; i++) {
        scanf("%d", &num[i].numero);
        num[i].frequencia = 0;
    }

    contar_aparicoes(casos, num);
    free(num);
    return 0;
}
