// Alarm Clock
//Uso obrigatório de uma struct para representar horários com hora e
// minuto e funções para calcular a diferença entre dois horários
// utilizando ponteiros e alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hora;
    int minuto;
} Horario;

int calcular_diferenca(int *hora_inicial, int *min_inicial, int *hora_final, int *min_final){

    int min_total_inicio,min_total_fim;
    min_total_inicio = (*hora_inicial * 60) + *min_inicial;
    min_total_fim = (*hora_final *60)+ *min_final;

    if (min_total_fim <= min_total_inicio){
        //deu 24h 
        min_total_fim += (24 *60);
    }

    int tempo_total_descanso;
    tempo_total_descanso = min_total_fim - min_total_inicio;
    
    return tempo_total_descanso;

}
 
int main() {
 
    while(1){
        Horario *hc = (Horario *) malloc(sizeof(Horario));
        Horario *hf = (Horario* )malloc(sizeof(Horario));

        scanf("%d %d %d %d", &hc->hora, &hc->minuto, &hf->hora, &hf->minuto);

        int hora_inicial, hora_final, min_inicial, min_final;
        hora_inicial = hc->hora;
        min_inicial = hc->minuto;
        hora_final = hf->hora;
        min_final = hf->minuto;

        if (hc->hora == 0 && hc->minuto == 0 && hf->hora == 0 && hf->minuto==0){
            free(hc);
            free(hf);
            break;
        }

        int diferenca;
        diferenca = calcular_diferenca(&hora_inicial, &min_inicial, &hora_final, &min_final);
        printf("%d\n", diferenca);
        free(hc);
        free(hf);

    }
    return 0;
}