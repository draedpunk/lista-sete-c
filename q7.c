// Head or Tail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int jogadas;
    
    while (scanf("%d", &jogadas) && jogadas != 0) {
        int *conjunto_jogadas = (int *)malloc(jogadas * sizeof(int));
        int mary = 0, john = 0;

        for (int i = 0; i < jogadas; i++) {
            scanf("%d", &conjunto_jogadas[i]);
            if (*(conjunto_jogadas + i) == 0) {
                mary++;
            } else {
                john++;
            }
        }
        printf("Mary won %d times and John won %d times\n", mary, john);
        free(conjunto_jogadas);
    }

    return 0;
}
