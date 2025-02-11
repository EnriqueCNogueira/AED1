#include <stdio.h>

int main() {
    int col, lin, mat[101][101] = {0}, i, j;
    char map[101][101];

    // Leitura das dimensões do mapa
    scanf("%d %d", &col, &lin);

    // Leitura do mapa
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    // Início no canto superior esquerdo
    i = 0;
    j = 0;

    while (1) {
        // Verifica se está fora dos limites
        if (i < 0 || i >= lin || j < 0 || j >= col) {
            printf("!\n");
            return 0;
        }

        // Verifica se está num baú
        if (map[i][j] == '*') {
            printf("*\n");
            return 0;
        }

        // Marca a posição como visitada
        mat[i][j]++;
        if (mat[i][j] > 1) { // Detecta ciclos
            printf("!\n");
            return 0;
        }

        // Movimenta de acordo com o símbolo
        if (map[i][j] == '>') {
            j++;
            while(map[i][j] == '.')
                j++;
            
        } else if (map[i][j] == '<') {
            j--;
            while(map[i][j] == '.')
                j--;
            
        } else if (map[i][j] == 'v') {
            i++;
            while(map[i][j] == '.')
                i++;
            
        } else if (map[i][j] == '^') {
            i--;
            while(map[i][j] == '.')
                i--;
            
        } else {
            printf("!\n");
            return 0;
        }
    }

    return 0;
}
