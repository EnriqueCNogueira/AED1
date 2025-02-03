#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void union_sets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n), m || n) {
        Edge edges[n];
        int total_weight = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
            total_weight += edges[i].weight;
        }
        
        qsort(edges, n, sizeof(Edge), compare);
        
        int parent[m], rank[m];
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        int mst_weight = 0, edges_used = 0;
        for (int i = 0; i < n && edges_used < m - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            if (find(parent, u) != find(parent, v)) {
                union_sets(parent, rank, u, v);
                mst_weight += edges[i].weight;
                edges_used++;
            }
        }
        
        printf("%d\n", total_weight - mst_weight);
    }
    return 0;
}
