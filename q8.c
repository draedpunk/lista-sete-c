// Square Matrix III
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main() {
    int x;
    while(scanf("%d", &x) && x != 0){
        
        int *matriz = (int *) malloc(x * x * sizeof(int));


        for (int i = 0; i < x; i++) {
            int valor = pow(2,i);
            for (int j = 0; j < x; j++) {
                *(matriz + i * x + j) = valor;
                valor *= 2;
            }
        }

        int max = *(matriz + x * x - 1);
        int T = 0;
        while (max > 0) {
        T++;
        max /= 10;
        }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                if (j == 0){
                    printf("%*d", T, *(matriz + i * x + j));
                }
                    
                else{
                    printf(" %*d", T, *(matriz + i * x + j));
                }
                    
            }
            printf("\n");
        }
        printf("\n");
        
        free(matriz);

    }
 
    return 0;
}