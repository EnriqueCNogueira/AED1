#include <stdio.h>
#include <stdlib.h>

#define MAX_VERT 100
#define MAX_ARES 1000

typedef struct {
    int u, v, p;  // u e v: vértices; p: peso da aresta
} Aresta;

// Função auxiliar para o "find" com compressão de caminho
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

// Função auxiliar para unir dois conjuntos
void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}

// Função de comparação para o qsort (ordena as arestas em ordem crescente de peso)
int compareEdges(const void *a, const void *b) {
    Aresta *edgeA = *(Aresta **)a;
    Aresta *edgeB = *(Aresta **)b;
    return edgeA->p - edgeB->p;
}

// Função que aplica o algoritmo de Kruskal para encontrar a MST
void MST(Aresta *arestas[], int num_ares, int n) {
    int parent[MAX_VERT];
    // Inicializa cada vértice em seu próprio conjunto
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    int e = 0;         // Contador de arestas incluídas na MST
    int i = 0;         // Índice para iterar pelas arestas ordenadas
    int total_weight = 0;
    
    printf("\nArestas selecionadas para a MST:\n");
    
    // Enquanto a MST não possuir (n-1) arestas e houverem arestas para verificar
    while (e < n - 1 && i < num_ares) {
        int u = arestas[i]->u;
        int v = arestas[i]->v;
        
        // Encontra os conjuntos (subárvores) dos vértices u e v
        int set_u = find(parent, u);
        int set_v = find(parent, v);
        
        // Se não formarem ciclo, adicione a aresta na MST
        if (set_u != set_v) {
            printf("Aresta: %d -- %d, peso: %d\n", u, v, arestas[i]->p);
            total_weight += arestas[i]->p;
            unionSets(parent, set_u, set_v);
            e++;
        }
        i++;
    }
    
    printf("Peso total da MST: %d\n", total_weight);
}

int main() {
    int n, matriz[MAX_VERT][MAX_VERT], num_ares = 0;
    Aresta *arestas[MAX_ARES];
    
    printf("Digite o número de vértices: ");
    scanf("%d", &n);
    
    printf("Digite a matriz de adjacência:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Cria as arestas a partir da matriz de adjacência
    // Para grafo não direcionado, consideramos apenas a parte superior da matriz (j > i)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matriz[i][j] != 0) {
                arestas[num_ares] = (Aresta *) malloc(sizeof(Aresta));
                if (arestas[num_ares] == NULL) {
                    fprintf(stderr, "Erro de alocação de memória.\n");
                    exit(1);
                }
                arestas[num_ares]->u = i;
                arestas[num_ares]->v = j;
                arestas[num_ares]->p = matriz[i][j];
                num_ares++;
            }
        }
    }
    
    // Ordena as arestas em ordem crescente de peso
    qsort(arestas, num_ares, sizeof(Aresta *), compareEdges);
    
    // Chama a função MST para calcular e exibir a árvore geradora mínima
    MST(arestas, num_ares, n);
    
    // Libera a memória alocada para cada aresta
    for (int i = 0; i < num_ares; i++) {
        free(arestas[i]);
    }
    
    return 0;
}
