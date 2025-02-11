#include <stdio.h>
#include <stdlib.h>

#define M 11  // Tamanho da tabela hash (número primo)

// Estrutura de um nó na lista encadeada
typedef struct Node {
    int key;
    struct Node *next;
} Node;

// Função que cria um novo nó com a chave informada
Node* createNode(int key) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Função hash utilizando o método da divisão: h(k) = k mod M
int hash(int key) {
    return key % M;
}

// Função para inserir uma chave na tabela hash (inserção no início da lista encadeada)
void insert(Node *hashTable[], int key) {
    int index = hash(key);
    Node *newNode = createNode(key);
    // Insere o novo nó no início da lista em hashTable[index]
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Função para imprimir o conteúdo da tabela hash
void printHashTable(Node *hashTable[]) {
    for (int i = 0; i < M; i++) {
        printf("Índice %d: ", i);
        Node *current = hashTable[i];
        if (current == NULL) {
            printf("vazio");
        }
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // Conjunto A com os elementos a serem inseridos
    int A[] = {7, 10, 23, 1, 77, 50, 34, 15};
    int n = sizeof(A) / sizeof(A[0]);

    // Criação da tabela hash: um vetor de ponteiros para Node
    Node *hashTable[M];
    for (int i = 0; i < M; i++) {
        hashTable[i] = NULL;
    }

    // Insere cada elemento de A na tabela hash
    for (int i = 0; i < n; i++) {
        insert(hashTable, A[i]);
    }

    // Imprime o estado final da tabela hash
    printf("Tabela Hash (com encadeamento):\n");
    printHashTable(hashTable);

    // Libera a memória alocada para cada nó
    for (int i = 0; i < M; i++) {
        Node *current = hashTable[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
