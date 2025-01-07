//O código recebe até 20 listas de produtos e retorna uma lista em ordem alfabética e sem repetições

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char produto[50];
    struct Node *prox;
} Node;

Node* criar_no(char *produto) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        strcpy(novo->produto, produto);
        novo->prox = NULL;
    }
    return novo;
}

void inserir_ordenado(Node **cabeca, char *produto) {
    Node *novo = criar_no(produto);
    if (novo == NULL) {
        return;
    }

    if (*cabeca == NULL || strcmp((*cabeca)->produto, produto) > 0) {
        novo->prox = *cabeca;
        *cabeca = novo;
        return;
    }

    Node *atual = *cabeca;
    Node *anterior = NULL;

    while (atual != NULL && strcmp(atual->produto, produto) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && strcmp(atual->produto, produto) == 0) {
        free(novo);
        return;
    }

    novo->prox = atual;
    if (anterior != NULL) {
        anterior->prox = novo;
    }
}

int imprimir_lista(Node *cabeca, char saida[20][50][100], int n) {
    int i = 0;
    Node *temp = cabeca;
    while (temp != NULL) {
        if (i >= 50) break; 
        strcpy(saida[i][n], temp->produto);
        temp = temp->prox;
        i++;
    }
    return i;
}

void liberar_lista(Node *cabeca) {
    Node *temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}

int main() {
    char saida[20][50][100] = {0}; 
    int m, n = 0, tam[100] = {0};

    scanf("%d", &m);
    getchar();

    if (m > 20) m = 20;

    while (n < m) {
        Node *cabeca = NULL;
        char lista[1000];
        fgets(lista, 1000, stdin);

        char *token = strtok(lista, " \n");
        while (token != NULL) {
            inserir_ordenado(&cabeca, token);
            token = strtok(NULL, " \n");
        }

        tam[n] = imprimir_lista(cabeca, saida, n);
        liberar_lista(cabeca);
        n++;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < tam[i]; j++) {
            printf("%s ", saida[j][i]);
        }
        printf("\n");
    }

    return 0;
}
