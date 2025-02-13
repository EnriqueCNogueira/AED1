#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura para representar uma aresta
typedef struct {
    int src, dest, weight;
} Edge;

// Estrutura para representar um subconjunto para union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Função para encontrar o conjunto (com compressão de caminho)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Função para unir dois subconjuntos (por ranking)
void unionSubsets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Função de comparação para qsort
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Implementação do algoritmo de Kruskal.
void kruskal(int n, int graph[][n]) {
    int i, j, totalEdges = 0;
    
    // Contar as arestas escaneando somente o triângulo superior (assumindo um grafo não direcionado)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (graph[i][j] != 0)
                totalEdges++;
        }
    }
    
    // Criar um array para armazenar todas as arestas
    Edge *edges = (Edge *)malloc(totalEdges * sizeof(Edge));
    
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[index].src = i;
                edges[index].dest = j;
                edges[index].weight = graph[i][j];
                index++;
            }
        }
    }
    
    // Ordenar as arestas em ordem crescente conforme o peso
    qsort(edges, totalEdges, sizeof(Edge), compareEdges);
    
    // Alocar memória para criar subconjuntos
    Subset *subsets = (Subset *)malloc(n * sizeof(Subset));
    
    // Inicializar os subconjuntos: cada vértice é seu próprio pai inicialmente
    for (i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    printf("Arestas na Árvore Geradora Mínima:\n");
    
    // Número de arestas incluídas na AGM
    int e = 0;
    // Iterar pelas arestas ordenadas
    for (i = 0; i < totalEdges && e < n - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);
        
        // Se incluir esta aresta não causar um ciclo, incluí-la na AGM
        if (x != y) {
            printf("%d -- %d  == %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            unionSubsets(subsets, x, y);
            e++;
        }
    }
    
    free(edges);
    free(subsets);
}

int main() {
    int n, i, j;
    int graph[MAX][MAX];
    printf("Digite o número de vértices: ");
    scanf("%d", &n);
    
    printf("Digite a matriz de adjacência:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    kruskal(n, graph);
    
    return 0;
}
