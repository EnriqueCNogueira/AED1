#include <stdio.h>

#define MAX 100

int Conexidade(int n, int matriz[MAX][MAX]) {
    int con = 0;
    int visitado[MAX] = {0}; 

    for (int i = 0; i < n; i++) {
        if (!visitado[i]) { //Se o vértice não foi visitado
            con++; //Incrementa o contador de componentes
            int fila[MAX];
            int inicio = 0, fim = 0;
            
            fila[fim++] = i; //Coloca v na fila
            visitado[i] = 1; //Marca v como visitado
            
            while (inicio < fim) { // Enquanto a fila não estiver vazia
                int v = fila[inicio++];  // Desenfileira o vértice v
                
                for (int j = 0; j < n; j++) {
                    // Se a aresta tem origem no vértice atual e o destino não foi visitado
                    if (matriz[v][j] && !visitado[j]) { 
                        visitado[j] = 1;     // Marca o vizinho como visitado
                        fila[fim++] = j;     // Enfileira o vértice j
                    }
                }
            }
        }
    }
    return con;
}

int main(){
    int n, matriz[MAX][MAX];
    
    scanf("%d", &n);
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int con = Conexidade(n, matriz[MAX][MAX]);
    
    printf("%d", con);

    return 0;
}
