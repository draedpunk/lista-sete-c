// The race of slugs
#include <stdio.h>
#include <stdlib.h>
// Uso obrigatório de uma struct para representar as 
// lesmas e suas velocidades, utilizando funções para determinar 
// a classificação da corrida, com manipulação via 
// ]ponteiros e alocação dinâmica para o vetor de lesmas.

typedef struct {
    int v_lesma_fornecida;
    int *lesmas;
} Lesmas;

void classificar_lesmas(int casos, Lesmas *mollusca, int *n1, int *n2, int *n3) {
    for (int i = 0; i< casos; i++) {
        mollusca->v_lesma_fornecida = mollusca->lesmas[i];

        if (mollusca->v_lesma_fornecida < 10) {
            (*n1)++;
        } else if(mollusca->v_lesma_fornecida >=10 && mollusca->v_lesma_fornecida < 20) {
            (*n2)++;
        } else {
            (*n3)++;
        }
    }
}

int main(){
    int casos;

    while (scanf("%d", &casos) != EOF) {
        Lesmas* mollusca = (Lesmas*) malloc(sizeof(Lesmas));
        mollusca->lesmas = (int*) malloc(casos * sizeof(int));

        for (int i=0; i < casos;i++){
            scanf("%d", &mollusca->lesmas[i]);
        }

        int nivel_um = 0; 
        int nivel_dois = 0; 
        int nivel_tres = 0;

        classificar_lesmas(casos, mollusca, &nivel_um, &nivel_dois, &nivel_tres);

        if (nivel_tres> 0){
            printf("3\n");
        } else if (nivel_dois> 0){
            printf("2\n");
        } else{
            printf("1\n");
        }

        free(mollusca->lesmas);
        free(mollusca);
    }

    return 0;
}
