#include <stdio.h>
#include <stdbool.h>

// Estrutura para representar um nó (interseção) na BFS.
typedef struct {
    int x, y;   // Coordenadas: x para coluna, y para linha.
    int dist;   // Distância (custo) a partir do nó de origem.
} Node;

int main() {
    int N;
    // Processa cada caso de teste enquanto N != 0.
    while (scanf("%d", &N) == 1 && N != 0) {
        // grid[y][x][0] = norte, [1] = sul, [2] = oeste, [3] = leste.
        // Usamos índice y: 0..N-1, onde 0 é o extremo sul e N-1 o extremo norte.
        int grid[11][11][4];
        
        // Lê as N linhas do mapa. A primeira linha lida é a mais ao norte (y = N-1),
        // a próxima é y = N-2, ..., até y = 0.
        for (int i = N - 1; i >= 0; i--) {
            for (int x = 0; x < N; x++) {
                scanf("%d %d %d %d", &grid[i][x][0], &grid[i][x][1],
                      &grid[i][x][2], &grid[i][x][3]);
            }
        }
        
        int P;
        scanf("%d", &P);
        // Processa cada consulta
        for (int p = 0; p < P; p++) {
            int sx, sy, tx, ty;
            scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
            
            // Vetor para controle de nós visitados (dimensão N x N)
            bool visited[11][11] = { false };
            // Vetor para a fila da BFS. Como N<=10, no máximo 100 nós.
            Node queue[110];
            int front = 0, rear = 0;
            
            // Coloca o nó inicial na fila
            queue[rear++] = (Node){ sx, sy, 0 };
            visited[sy][sx] = true;
            
            int ans = -1; // Se continuar -1, não houve caminho
            
            // BFS
            while (front < rear) {
                Node cur = queue[front++];
                // Se alcançou o destino, guarda a distância e sai
                if (cur.x == tx && cur.y == ty) {
                    ans = cur.dist;
                    break;
                }
                
                // A partir da interseção atual, verifica os movimentos permitidos.
                // Ordem: norte, sul, oeste, leste.
                // Norte: incremento em y
                if (grid[cur.y][cur.x][0] == 1) {
                    int nx = cur.x;
                    int ny = cur.y + 1;
                    if (ny < N && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        queue[rear++] = (Node){ nx, ny, cur.dist + 1 };
                    }
                }
                // Sul: decremento em y
                if (grid[cur.y][cur.x][1] == 1) {
                    int nx = cur.x;
                    int ny = cur.y - 1;
                    if (ny >= 0 && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        queue[rear++] = (Node){ nx, ny, cur.dist + 1 };
                    }
                }
                // Oeste: decremento em x
                if (grid[cur.y][cur.x][2] == 1) {
                    int nx = cur.x - 1;
                    int ny = cur.y;
                    if (nx >= 0 && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        queue[rear++] = (Node){ nx, ny, cur.dist + 1 };
                    }
                }
                // Leste: incremento em x
                if (grid[cur.y][cur.x][3] == 1) {
                    int nx = cur.x + 1;
                    int ny = cur.y;
                    if (nx < N && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        queue[rear++] = (Node){ nx, ny, cur.dist + 1 };
                    }
                }
            }
            
            // Imprime o resultado para a consulta corrente.
            if (ans == -1)
                printf("Impossible\n");
            else
                printf("%d\n", ans);
        }
        // Linha em branco após cada caso de teste.
        printf("\n");
    }
    return 0;
}
