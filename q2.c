//Average 3
#include <stdio.h>
#include <stdlib.h>

void calcular_media(float *nota1, float *nota2, float *nota3, float *nota4, float *nota5){
    float media, nova_media;
    media = ((*nota1 * 2) + (*nota2 * 3) + (*nota3 * 4) + (*nota4 * 1))/10.0;

    printf("Media: %.1f\n", media);
    if (media >= 7.0){
        printf("Aluno aprovado.\n");

    } else if (media >= 5.0 && media <= 6.9){
        printf("Aluno em exame.\n");
        scanf("%f", &(*nota5));
        printf("Nota do exame: %.1f\n", *nota5);

        nova_media = (media + (*nota5))/2.0;
        if (nova_media >= 5.0){
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", nova_media);

    } else {
        printf("Aluno reprovado.\n");
    }
}

int main(){
    float n1,n2, n3, n4, n5;
    scanf("%f %f %f %f", &n1,&n2, &n3, &n4);

    calcular_media(&n1, &n2,&n3,&n4, &n5);
    

    return 0;
}