#include <stdio.h>
#include <stdlib.h>

#define MAX_NOS 100
#define MAX_ARESTAS 1000

typedef struct no {
    int cont;
    struct no *seg;
} fila;

void Insere(int y, fila *p) {
    fila *nova = malloc(sizeof(fila));
    if(nova == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    nova->cont = y;
    nova->seg = p->seg;
    p->seg = nova;
}

int Remove(fila *p) {
    if (p->seg == NULL) {
        printf("Fila vazia.\n");
        exit(1);
    }
    fila *temp = p->seg;
    int valor = temp->cont;
    p->seg = temp->seg;
    free(temp);
    printf("%d ", valor);
    return valor;
}

void BuscaemLargura(int lista[MAX_ARESTAS][2], int s, int arest, fila *cabeca) {
    int aux, visitado[MAX_NOS] = {0};
    visitado[s] = 1;
    
    // Enquanto a fila não estiver vazia, continue a busca
    while (cabeca->seg != NULL) {
        aux = Remove(cabeca); // obtém o próximo vértice a ser processado
        for (int j = 0; j < arest; j++) {
            // Se a aresta tem origem no vértice atual e o destino ainda não foi visitado
            if (lista[j][0] == aux && visitado[lista[j][1]] == 0) {
                visitado[lista[j][1]] = 1;
                Insere(lista[j][1], cabeca);
            }
        }
    }
}

int main() {
    int lista[MAX_ARESTAS][2], s, vert, arest;
    fila *cabeca;
    
    cabeca = malloc(sizeof(fila));
    if(cabeca == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    cabeca->seg = NULL; // inicializa a lista (fila vazia)
    
    printf("Digite o número de vértices e arestas no grafo:\n");
    scanf("%d %d", &vert, &arest);
    
    printf("Digite o vértice inicial:\n");
    scanf("%d", &s);
    Insere(s, cabeca);
    
    printf("Digite o vértice inicial e final de cada aresta:\n");
    for (int i = 0; i < arest; i++) {
        scanf("%d %d", &lista[i][0], &lista[i][1]);
    }
    
    printf("Busca em Largura começando do vértice %d:\n", s);
    BuscaemLargura(lista, s, arest, cabeca);
    
    free(cabeca);
    return 0;
}
