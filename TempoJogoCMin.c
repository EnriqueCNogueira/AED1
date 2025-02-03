#include <stdio.h>

int main()
{
    int hora_inicio, minuto_inicio, hora_fim, minuto_fim;
    int duracao_horas, duracao_minutos;

    scanf("%d %d %d %d", &hora_inicio, &minuto_inicio, &hora_fim, &minuto_fim);

    int inicio_total = hora_inicio * 60 + minuto_inicio;
    int fim_total = hora_fim * 60 + minuto_fim;

    if (fim_total > inicio_total) {
        duracao_minutos = fim_total - inicio_total;
    } else {
        duracao_minutos = (24 * 60 - inicio_total) + fim_total;
    }

    duracao_horas = duracao_minutos / 60;
    duracao_minutos %= 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_horas, duracao_minutos);

    return 0;
}
