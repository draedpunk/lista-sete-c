// Triangle
// Uso obrigatório de uma struct para representar lados de segmentos, 
// utilizando funções para verificação de formação de triângulo, 
// com ponteiros e alocação dinâmica dos lados. 
#include <stdio.h>

typedef struct {
    int lado1;
    int lado2;
    int lado3;
} Triangulo;

int verificar_triangulo(Triangulo *t) {

    int pode_formar_triangulo = 0;

    if (t->lado1 + t->lado2 > t->lado3 && t->lado2 + t->lado3 > t->lado1 &&  t->lado1 + t->lado3 > t->lado2){
            pode_formar_triangulo= 1;
        }

    return pode_formar_triangulo;
}

int main() {
    int *lados = malloc(4 * sizeof(int));

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    Triangulo *t1 = (Triangulo*) malloc(sizeof(Triangulo));
    Triangulo *t2 = (Triangulo*) malloc(sizeof(Triangulo));
    Triangulo *t3 = (Triangulo*) malloc(sizeof(Triangulo));
    Triangulo *t4 = (Triangulo*) malloc(sizeof(Triangulo));

    t1->lado1 = a; t1->lado2 = b; t1->lado3 = c; // trangulo 1
    t2->lado1 = a; t2->lado2 = b; t2->lado3 = d; // triangulo 2
    t3->lado1 = a; t3->lado2 = c; t3->lado3 = d; // triangulo 3
    t4->lado1 = b; t4->lado2 = c; t4->lado3 = d; // triangulo 4

    if (verificar_triangulo(t1) ||verificar_triangulo(t2)  || verificar_triangulo(t3) ||verificar_triangulo(t4)) {
        printf("S\n");

    } else {
        printf("N\n");
    }

    return 0;
}
