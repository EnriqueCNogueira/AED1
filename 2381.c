#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Mergesort(int p, int r, char v[100][21], char aux[100][21]);
void Intercala(int p, int q, int r, char v[100][21], char aux[100][21]);

void Mergesort(int p, int r, char v[100][21], char aux[100][21]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v, aux);
        Mergesort(q, r, v, aux);
        Intercala(p, q, r, v, aux);
    }
}

void Intercala(int p, int q, int r, char v[100][21], char aux[100][21]) {
    int i = p, j = q, k = 0;

    while (i < q && j < r) {
        if (strcmp(v[i], v[j]) <= 0) {
            strcpy(aux[k++], v[i++]);
        } else {
            strcpy(aux[k++], v[j++]);
        }
    }

    while (i < q) {
        strcpy(aux[k++], v[i++]);
    }
    while (j < r) {
        strcpy(aux[k++], v[j++]);
    }

    for (i = p, k = 0; i < r; i++, k++) {
        strcpy(v[i], aux[k]);
    }
}

int main() {
    int quant, ind;
    char nome[100][21];
    char aux[100][21];

    if (scanf("%d %d", &quant, &ind) != 2 || quant < 1 || quant > 100 || ind < 1 || ind > quant) {
        printf("Erro: entrada inválida.\n");
        return 1;
    }

    for (int i = 0; i < quant; i++) {
        if (scanf("%20s", nome[i]) != 1) {
            printf("Erro: nome inválido.\n");
            return 1;
        }
    }

    Mergesort(0, quant, nome, aux);

    ind -= 1;

    if (ind >= 0 && ind < quant) {
        printf("%s\n", nome[ind]);
    } else {
        printf("Erro: índice fora do intervalo.\n");
        return 1;
    }

    return 0;
}
