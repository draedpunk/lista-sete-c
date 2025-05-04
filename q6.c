// Even or Odd
// even: first the even in ascending order (n%2 == 0)
// odd:  odd in descending order (n%2 != 0)
#include <stdio.h>
#include <stdlib.h>

void ordenar_positivos(int *positivos, int tam_positivo){

    for (int p = 0; p < tam_positivo-1; p++){
        for (int q = 0; q < tam_positivo - 1 - p; q++){

            if(positivos[q] > positivos[q+1]){
               int temp_positivo = positivos[q];
               positivos[q] = positivos[q+1];
               positivos[q+1] = temp_positivo;
            }
        }
    }

}

void ordenar_negativos(int *negativos, int tam_negativo){

    for (int p = 0; p < tam_negativo-1; p++){
        for (int q = 0; q < tam_negativo - 1 - p; q++){

            if(negativos[q] < negativos[q+1]){
               int temp_negativo = negativos[q];
               negativos[q] = negativos[q+1];
               negativos[q+1] = temp_negativo;
            }
        }
    }

}

void printar_resultados(int *positivos, int *negativos, int tam_positivo, int tam_negativo){

    for (int i = 0; i < tam_positivo; i++){
        printf("%d\n", positivos[i]);
    }
    for (int i = 0; i < tam_negativo; i++){
        printf("%d\n", negativos[i]);
    }

}
 
int main() {
 
    int qtd_numeros;
    scanf("%d\n", &qtd_numeros);

    
    int *positivos = malloc(qtd_numeros * sizeof(int));
    int *negativos = malloc(qtd_numeros * sizeof(int));

    if (positivos == NULL || negativos ==NULL){
        printf("erro na alocacao de memoria!!\n");
        return 1;
    }
    int numero;
    int tam_positivo =0;
    int tam_negativo= 0;

    for (int i = 0; i < qtd_numeros; i++){
        scanf("%d\n", &numero);

        if (numero % 2 == 0){
            // par
            positivos[tam_positivo++] = numero;

        } else {
            // impar
            negativos[tam_negativo++] = numero;

        }
    }

    ordenar_positivos(positivos, tam_positivo);
    ordenar_negativos(negativos, tam_negativo);

    printar_resultados(positivos, negativos, tam_positivo, tam_negativo);
    
    free(positivos);
    free(negativos);
    return 0;
}