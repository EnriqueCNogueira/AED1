#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **hashTable;
    int *counts;
    int m;
} HashTable;

void freeHashTable(HashTable *ht) {
    for (int i = 0; i < ht->m; i++) {
        free(ht->hashTable[i]);
    }
    free(ht->hashTable);
    free(ht->counts);
}

int main() {
    int n; // Número de casos de teste

    // Entrada do número de casos de teste
    scanf("%d", &n);

    HashTable *cases = (HashTable *)malloc(n * sizeof(HashTable)); // Estruturas para armazenar cada tabela hash
    int *keysPerCase = (int *)malloc(n * sizeof(int));            // Número de chaves por caso

    // Leitura e armazenamento de todos os casos de teste
    for (int t = 0; t < n; t++) {
        int m, c; // Número de endereços-base e quantidade de chaves
        scanf("%d %d", &m, &c);
        keysPerCase[t] = c;

        // Inicializa a tabela hash para o caso atual
        cases[t].m = m;
        cases[t].hashTable = (int **)malloc(m * sizeof(int *));
        cases[t].counts = (int *)calloc(m, sizeof(int));

        for (int i = 0; i < m; i++) {
            cases[t].hashTable[i] = NULL;
        }

        // Entrada das chaves e armazenamento na tabela hash
        for (int i = 0; i < c; i++) {
            int key;
            scanf("%d", &key);

            int index = key % m;

            cases[t].counts[index]++;
            cases[t].hashTable[index] = (int *)realloc(cases[t].hashTable[index], cases[t].counts[index] * sizeof(int));
            cases[t].hashTable[index][cases[t].counts[index] - 1] = key;
        }
    }

    // Impressão de todas as tabelas hash após o término da entrada
    for (int t = 0; t < n; t++) {
        for (int i = 0; i < cases[t].m; i++) {
            printf("%d -> ", i);
            for (int j = 0; j < cases[t].counts[i]; j++) {
                printf("%d -> ", cases[t].hashTable[i][j]);
            }
            printf("\\\n");
        }

        if (t < n - 1) {
            printf("\n");
        }
    }

    // Liberação da memória alocada
    for (int t = 0; t < n; t++) {
        freeHashTable(&cases[t]);
    }
    free(cases);
    free(keysPerCase);

    return 0;
}
