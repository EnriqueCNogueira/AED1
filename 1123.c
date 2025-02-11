#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 250
#define MAXM 31250

typedef struct {
    int u, v, p;
} Edge;

Edge edges[MAXM];
int dist[MAXN];
int visited[MAXN];
int n, m, c, k;

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int minDist = INT_MAX, minIndex = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = 1;

        for (int j = 0; j < m; j++) {
            if (edges[j].u == minIndex || edges[j].v == minIndex) {
                int neighbor = (edges[j].u == minIndex) ? edges[j].v : edges[j].u;
                int cost = edges[j].p;

                // Restrição: se estamos dentro da rota de serviço
                if (minIndex < c - 1 && neighbor != minIndex + 1) {
                    continue;
                }

                if (dist[minIndex] + cost < dist[neighbor]) {
                    dist[neighbor] = dist[minIndex] + cost;
                }
            }
        }
    }
}

int main() {
    int saida[999], aux, i=0;
    
    while (1) {
        scanf("%d %d %d %d", &n, &m, &c, &k);
        
        if (n == 0 && m == 0 && c == 0 && k == 0) {
            break;
        }
        
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].p);
        }
        
        dijkstra(k);
        
        saida[i] = dist[c - 1];
        i++;
    }
    
    for(aux =0; aux < i; aux++){
        printf("%d\n", saida[aux]);
    }

    return 0;
}
