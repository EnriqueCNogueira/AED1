#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 26 // Número máximo de vértices (letras do alfabeto)

int main() {
    int num_casos;
    scanf("%d", &num_casos);

    for (int caso_atual = 1; caso_atual <= num_casos; caso_atual++) {
        int num_vertices, num_arestas;
        scanf("%d %d", &num_vertices, &num_arestas);

        int matriz_adj[MAX_VERTICES][MAX_VERTICES] = {0}; // Matriz de adjacência para armazenar conexões

        // Leitura das arestas do grafo
        for (int i = 0; i < num_arestas; i++) {
            char vertice1, vertice2;
            scanf(" %c %c", &vertice1, &vertice2);
            int u = vertice1 - 'a';
            int v = vertice2 - 'a';
            matriz_adj[u][v] = 1;
            matriz_adj[v][u] = 1;
        }

        bool visitado[MAX_VERTICES] = {false}; // Vetor para marcar vértices visitados
        char componentes[MAX_VERTICES][MAX_VERTICES]; // Lista de componentes conectados
        int tamanho_componentes[MAX_VERTICES] = {0}; // Tamanho de cada componente
        int num_componentes = 0; // Contador de componentes

        // Busca por componentes conectados no grafo
        for (int vertice = 0; vertice < num_vertices; vertice++) {
            if (!visitado[vertice]) {
                int fila[MAX_VERTICES]; // Fila para busca em largura (BFS)
                int frente = 0, fim = 0;
                fila[fim++] = vertice;
                visitado[vertice] = true;

                int componente[MAX_VERTICES]; // Lista para armazenar os vértices do componente atual
                int tamanho_comp = 0;
                componente[tamanho_comp++] = vertice;

                // Realiza BFS para encontrar todos os vértices conectados
                while (frente < fim) {
                    int atual = fila[frente++];
                    for (int vizinho = 0; vizinho < num_vertices; vizinho++) {
                        if (matriz_adj[atual][vizinho] && !visitado[vizinho]) {
                            visitado[vizinho] = true;
                            fila[fim++] = vizinho;
                            componente[tamanho_comp++] = vizinho;
                        }
                    }
                }

                // Ordena os vértices do componente encontrado
                for (int i = 0; i < tamanho_comp - 1; i++) {
                    for (int j = i + 1; j < tamanho_comp; j++) {
                        if (componente[i] > componente[j]) {
                            int temp = componente[i];
                            componente[i] = componente[j];
                            componente[j] = temp;
                        }
                    }
                }

                // Armazena o componente na matriz de componentes
                for (int i = 0; i < tamanho_comp; i++) {
                    componentes[num_componentes][i] = componente[i] + 'a';
                }
                tamanho_componentes[num_componentes] = tamanho_comp;
                num_componentes++;
            }
        }

        // Ordenação dos componentes por ordem alfabética
        for (int i = 0; i < num_componentes - 1; i++) {
            for (int j = 0; j < num_componentes - i - 1; j++) {
                if (componentes[j][0] > componentes[j + 1][0]) {
                    char temp_componente[MAX_VERTICES];
                    int temp_tamanho = tamanho_componentes[j];
                    memcpy(temp_componente, componentes[j], temp_tamanho);
                    memcpy(componentes[j], componentes[j + 1], tamanho_componentes[j + 1]);
                    tamanho_componentes[j] = tamanho_componentes[j + 1];
                    memcpy(componentes[j + 1], temp_componente, temp_tamanho);
                    tamanho_componentes[j + 1] = temp_tamanho;
                }
            }
        }

        // Exibição do resultado
        printf("Case #%d:\n", caso_atual);
        for (int i = 0; i < num_componentes; i++) {
            for (int j = 0; j < tamanho_componentes[i]; j++) {
                printf("%c,", componentes[i][j]);
            }
            printf("\n");
        }
        printf("%d connected components\n\n", num_componentes);
    }

    return 0;
}
