#include <stdio.h>
#include <stdlib.h>

/* Função que insere o elemento na heap (considerando índice 1) */
void InsereEmHeap (int m, int v[]) {
    int f = m + 1;
    while (f > 1 && v[f/2] < v[f]) {  // condição completa
        int t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f = f/2;
    }
}

/* Função que reestrutura a heap após a remoção do elemento */
void SacodeHeap (int m, int v[]) {
    int t, f = 2;
    while (f <= m) {  // condição completa
        if (f < m && v[f] < v[f+1])
            f++;  // seleciona o maior filho
        if (v[f/2] >= v[f])
            break;
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f *= 2;
    }
}

/* Heapsort que utiliza as funções anteriores */
void Heapsort (int n, int v[]) {
    int m;
    // Constrói a heap (usando índice 1 até n)
    for (m = 1; m < n; m++)
        InsereEmHeap(m, v);
    // Ordena: troca a raiz com o último elemento e reestrutura a heap
    for (m = n; m > 1; m--) {  // condição completa
        int t = v[1];
        v[1] = v[m];
        v[m] = t;
        SacodeHeap(m - 1, v);
    }
}

int main() {
    int n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Como as funções utilizam índices a partir de 1, aloca-se vetor de tamanho n+1
    int *v = (int *)malloc((n + 1) * sizeof(int));
    if (v == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    printf("Digite os elementos do vetor:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    Heapsort(n, v);

    printf("Vetor ordenado:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    return 0;
}
