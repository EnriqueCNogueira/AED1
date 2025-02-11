#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_A 101
#define MAX_B 101

int A[MAX_A], B[MAX_B];
int adj[MAX_A][MAX_B];
int nA, nB;

int matchB[MAX_B];
bool visitedB[MAX_B];

bool dfs(int a) {
    for (int b = 0; b < nB; b++) {
        if (adj[a][b] && !visitedB[b]) {
            visitedB[b] = true;
            if (matchB[b] == -1 || dfs(matchB[b])) {
                matchB[b] = a;
                return true;
            }
        }
    }
    return false;
}

int maxBipartiteMatching() {
    memset(matchB, -1, sizeof(matchB));
    int result = 0;
    for (int a = 0; a < nA; a++) {
        memset(visitedB, 0, sizeof(visitedB));
        if (dfs(a)) {
            result++;
        }
    }
    return result;
}

int main() {
    int T, tc, answer[51];
    scanf("%d", &T);
    
    for (tc = 1; tc <= T; tc++) {
        scanf("%d", &nA);
        for (int i = 0; i < nA; i++) {
            scanf("%d", &A[i]);
        }
        scanf("%d", &nB);
        for (int j = 0; j < nB; j++) {
            scanf("%d", &B[j]);
        }
        
        // Build adjacency matrix
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < nA; i++) {
            int a = A[i];
            for (int j = 0; j < nB; j++) {
                int b = B[j];
                if (a == 0) {
                    if (b == 0) {
                        adj[i][j] = 1;
                    }
                } else {
                    if (b == 0) {
                        adj[i][j] = 1;
                    } else if (b % a == 0) {
                        adj[i][j] = 1;
                    }
                }
            }
        }
        
        answer[tc] = maxBipartiteMatching();
    }
    
    for (tc = 1; tc <= T; tc++) 
        printf("Case %d: %d\n", tc, answer[tc]);
    
    return 0;
}
