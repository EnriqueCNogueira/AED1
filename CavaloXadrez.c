#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Movimentos possíveis do cavalo
int moves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Estrutura para representar uma posição no tabuleiro
typedef struct {
    int x, y, dist;
} Position;

// Função para converter notação de xadrez para coordenadas de matriz
void parse_position(char *pos, int *x, int *y) {
    *x = pos[0] - 'a';
    *y = pos[1] - '1';
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int is_valid(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// Função para encontrar o menor número de movimentos do cavalo usando BFS
int min_knight_moves(int startX, int startY, int endX, int endY) {
    if (startX == endX && startY == endY) return 0;
    
    int visited[BOARD_SIZE][BOARD_SIZE] = {0};
    Position queue[BOARD_SIZE * BOARD_SIZE];
    int front = 0, rear = 0;
    
    queue[rear++] = (Position){startX, startY, 0};
    visited[startX][startY] = 1;
    
    while (front < rear) {
        Position current = queue[front++];
        
        for (int i = 0; i < 8; i++) {
            int newX = current.x + moves[i][0];
            int newY = current.y + moves[i][1];
            
            if (newX == endX && newY == endY)
                return current.dist + 1;
            
            if (is_valid(newX, newY) && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                queue[rear++] = (Position){newX, newY, current.dist + 1};
            }
        }
    }
    return -1; // Nunca deve acontecer, pois há sempre um caminho válido
}

int main() {
    char start[3], end[3];
    while (scanf("%s %s", start, end) != EOF) {
        int startX, startY, endX, endY;
        parse_position(start, &startX, &startY);
        parse_position(end, &endX, &endY);
        
        int moves = min_knight_moves(startX, startY, endX, endY);
        printf("To get from %s to %s takes %d knight moves.\n", start, end, moves);
    }
    return 0;
}
