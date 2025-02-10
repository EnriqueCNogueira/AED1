#include <stdio.h>
#include <limits.h>

#define MAX 100 // Número máximo de vértices permitido

// Função que implementa o algoritmo de Dijkstra para encontrar o caminho mais curto
void dijkstra(int G[MAX][MAX], int numVertices, int s, int f) {
    int dist[MAX], visitado[MAX] = {0}; // Vetores de distâncias e de vértices visitados

    // Inicialização das distâncias
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX; // Define todas as distâncias como infinitas inicialmente
    }
    dist[s] = 0; // Distância do vértice inicial (s) para ele mesmo é zero

    // Loop principal do algoritmo de Dijkstra
    for (int i = 0; i < numVertices; i++) {
        int u = -1, minDist = INT_MAX;

        // Encontrar o vértice não visitado com a menor distância
        for (int j = 0; j < numVertices; j++) {
            if (!visitado[j] && dist[j] < minDist) { // Apenas considera vértices não visitados
                minDist = dist[j];
                u = j; // Atualiza o vértice com a menor distância
            }
        }

        if (u == -1) break; // Todos os vértices alcançáveis já foram processados

        visitado[u] = 1; // Marca o vértice como visitado

        // Atualizar as distâncias dos vértices vizinhos
        for (int v = 0; v < numVertices; v++) {
            if (G[u][v] != 0 && !visitado[v]) { // Verifica se existe uma aresta para o vértice vizinho
                if (dist[u] + G[u][v] < dist[v]) { // Verifica se o caminho atual é menor
                    dist[v] = dist[u] + G[u][v]; // Atualiza a distância mínima para o vizinho
                }
            }
        }
    }

    // Imprime o resultado final
    if (dist[f] == INT_MAX) {
        printf("Não há caminho de %d para %d\n", s, f); // Se a distância é infinita, não há caminho
    } else {
        printf("Distância de %d para %d: %d\n", s, f, dist[f]); // Imprime a distância mínima encontrada
    }
}

int main() {
    int G[MAX][MAX] = {0}; // Matriz de adjacência representando o grafo
    int n, m, s, f;        // n: número de vértices, m: número de arestas, s: inicial, f: final

    // Entrada do número de vértices, arestas, vértice inicial e vértice final
    printf("Digite o número de vértices, arestas, vértice inicial e final:\n");
    scanf("%d %d %d %d", &n, &m, &s, &f);

    // Entrada das arestas
    printf("Digite as arestas no formato 'u v p' (origem, destino e peso):\n");
    for (int i = 0; i < m; i++) {
        int u, v, p; // u: vértice origem, v: vértice destino, p: peso da aresta
        scanf("%d %d %d", &u, &v, &p);
        G[u][v] = p; // Preenche a matriz de adjacência com o peso da aresta
    }

    // Chamada do algoritmo de Dijkstra para calcular o caminho mais curto
    dijkstra(G, n, s, f);

    return 0;
}
