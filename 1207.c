#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1200
#define MAX_EDGES 500000
#define INF 1000000000

// Estrutura para representar cada aresta do grafo
typedef struct {
    int to, cap, nxt;
} Edge;

Edge edge[MAX_EDGES];
int head[MAX_NODES];
int edge_count;

int level[MAX_NODES];
int iter[MAX_NODES];

// Inicializa a lista de adjacência
void init_graph(int n) {
    for (int i = 0; i < n; i++) {
        head[i] = -1;
    }
    edge_count = 0;
}

// Adiciona uma aresta de u para v com capacidade cap e a aresta reversa (de v para u) com capacidade 0
void addEdge(int u, int v, int cap) {
    edge[edge_count].to = v;
    edge[edge_count].cap = cap;
    edge[edge_count].nxt = head[u];
    head[u] = edge_count++;
    
    edge[edge_count].to = u;
    edge[edge_count].cap = 0;
    edge[edge_count].nxt = head[v];
    head[v] = edge_count++;
}

// Implementação do BFS do Dinic (construção dos níveis)
int bfs(int s, int t, int n) {
    for (int i = 0; i < n; i++) {
        level[i] = -1;
    }
    level[s] = 0;
    
    int queue[MAX_NODES], front = 0, rear = 0;
    queue[rear++] = s;
    
    while (front < rear) {
        int u = queue[front++];
        for (int i = head[u]; i != -1; i = edge[i].nxt) {
            int v = edge[i].to;
            if (edge[i].cap > 0 && level[v] < 0) {
                level[v] = level[u] + 1;
                queue[rear++] = v;
            }
        }
    }
    return level[t] != -1;
}

// DFS do Dinic para enviar fluxo
int dfs(int u, int t, int f) {
    if (u == t)
        return f;
    for (int *i = &iter[u]; *i != -1; *i = edge[*i].nxt) {
        int idx = *i;
        int v = edge[idx].to;
        if (edge[idx].cap > 0 && level[u] + 1 == level[v]) {
            int ret = dfs(v, t, f < edge[idx].cap ? f : edge[idx].cap);
            if (ret) {
                edge[idx].cap -= ret;
                edge[idx ^ 1].cap += ret;
                return ret;
            }
        }
    }
    return 0;
}

// Algoritmo de Dinic para cálculo do fluxo máximo
int maxFlow(int s, int t, int n) {
    int flow = 0;
    while (bfs(s, t, n)) {
        for (int i = 0; i < n; i++) {
            iter[i] = head[i];
        }
        int pushed;
        while ((pushed = dfs(s, t, INF)) != 0) {
            flow += pushed;
        }
    }
    return flow;
}

int main(){
    int N, M;
    // Enquanto houver instâncias (EOF)
    while (scanf("%d %d", &N, &M) == 2) {
        // Os nós serão organizados da seguinte forma:
        // Nós 0: fonte (source)
        // Nós 1..M: categorias
        // Nós M+1 .. M+N: tipos de vodka
        // Nó M+N+1: sorvedouro (sink)
        int total_nodes = M + N + 2;
        int source = 0;
        int sink = M + N + 1;
        
        init_graph(total_nodes);
        
        int i, j;
        int costVodka[N+1];
        for (j = 1; j <= N; j++) {
            scanf("%d", &costVodka[j]);
        }
        
        // Vetor P: número de vodkas em cada categoria
        int P[M+1];
        for (i = 1; i <= M; i++) {
            scanf("%d", &P[i]);
        }
        
        // A soma de benefícios positivos
        int totalBeneficios = 0;
        
        // Para cada categoria, lê seu benefício e as vodkas que a compõem
        // Nós das categorias terão índices 1 a M
        // Adiciona aresta da fonte para a categoria com capacidade = benefício
        // Em seguida, para cada vodka na categoria, adiciona aresta da categoria para o nó da vodka (índice M + id_vodka)
        for (i = 1; i <= M; i++) {
            int beneficio;
            scanf("%d", &beneficio);
            totalBeneficios += beneficio;
            addEdge(source, i, beneficio);
            for (j = 0; j < P[i]; j++) {
                int vodka;
                scanf("%d", &vodka);
                // Adiciona aresta de categoria i para o nó que representa a vodka
                addEdge(i, M + vodka, INF);
            }
        }
        
        // Para cada vodka, adiciona aresta do nó correspondente para o sorvedouro com capacidade = custo
        for (j = 1; j <= N; j++) {
            addEdge(M + j, sink, costVodka[j]);
        }
        
        // Calcula o fluxo máximo
        int fluxo = maxFlow(source, sink, total_nodes);
        // O resultado é a soma dos benefícios menos o custo total mínimo (fluxo)
        int resultado = totalBeneficios - fluxo;
        printf("%d\n", resultado);
    }
    
    return 0;
}
