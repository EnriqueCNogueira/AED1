#include <stdio.h>

//Função que le a matriz
void LeMatriz (int matriz[9][9]){
    int i, j;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    return;
}

//Função que verifica se a matriz é um sudoku válido
int VerificaMatriz (int m[9][9]){
    int i, j, k, aux[9], n=0;
    
    //verifica as linhas
    for(k=0; k<9; k++){
        for(i=0; i<8; i++){
            for(j=i+1; j<9; j++){
                if(m[i][k] == m[j][k])
                return 0;
            }
        }
    }
    
    //verifica as colunas
    for(k=0; k<9; k++){
        for(i=0; i<8; i++){
            for(j=i+1; j<9; j++){
                if(m[k][i] == m[k][j])
                return 0;
            }
        }
    }
    
    //verifica as submatrizes 3x3
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(i%3==0 && j%3==0){
                aux[0] = m[i][j];
                aux[1] = m[i][j+1];
                aux[2] = m[i][j+2];
                aux[3] = m[i+1][j];
                aux[4] = m[i+1][j+1];
                aux[5] = m[i+1][j+2];
                aux[6] = m[i+2][j];
                aux[7] = m[i+2][j+1];
                aux[8] = m[i+2][j+2];
                
                for(k=0; k<9; k++){
                    for(int l=k+1; l<9; l++){
                        if(aux[k] == aux[l])
                        return 0;
                    }
                }
            }
        }
    }
    
    //verifica se os valores são de 1 a 9
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if (m[i][j] < 1 || m[i][j] > 9)
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    int n, i, matriz[9][9], resultado;
    i = 0;
    
    scanf("%d", &n);
    
    //Laço que chama as funções que le a matriz e verifica se a matriz corresponde a um sudoku válido, imprimindo se é valido ou não
    while(i<n){
        LeMatriz(matriz);
        resultado = VerificaMatriz(matriz);
        if(resultado == 1){
            printf("Instancia %d\nSIM", i+1);
        }else{
            printf("Instancia %d\nNAO", i+1);
        }
        i++;
        printf("\n\n");
    }
    
    return 0;
}