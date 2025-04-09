#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct Node {
    int chave;
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Função para criar um novo nó
Node* novoNo(int chave) {
    Node* no = (Node*)malloc(sizeof(Node));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Função InOrder (esquerda, raiz, direita)
void imprimirInOrder(Node* raiz) {
    if (raiz != NULL) {
        imprimirInOrder(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirInOrder(raiz->direita);
    }
}

int main() {
    // Vetor de ponteiros para nós
    Node* nos[7];

    // Criando os nós
    nos[0] = novoNo(30);
    nos[1] = novoNo(20);
    nos[2] = novoNo(40);
    nos[3] = novoNo(10);
    nos[4] = novoNo(25);
    nos[5] = novoNo(35);
    nos[6] = novoNo(50);

    // Montando a árvore manualmente (AVL balanceada)
    //           30
    //         /    \
    //       20      40
    //      /  \    /  \
    //    10   25  35  50

    nos[0]->esquerda = nos[1];
    nos[0]->direita = nos[2];
    nos[1]->esquerda = nos[3];
    nos[1]->direita = nos[4];
    nos[2]->esquerda = nos[5];
    nos[2]->direita = nos[6];

    // Imprime os elementos em ordem
    printf("Elementos em ordem (InOrder): ");
    imprimirInOrder(nos[0]); // Raiz é o nó 30
    printf("\n");

    return 0;
}
