#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para a lista encadeada (cada índice da tabela hash)
typedef struct node {
    int data;
    struct node *next;
} Node;

// Função que retorna o primeiro número primo maior que n
int Primo(int n) {
    int num = n + 1;
    while (1) {
        int isPrime = 1;
        // Verifica se num é primo
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            return num;
        num++;
    }
}

// Função para inserir um elemento x na tabela hash com tratamento de colisão por encadeamento
void Hash(Node *hash_table[], int x, int table_size) {
    int index = x % table_size;
    Node *new_node = malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = NULL;
    
    // Insere no final da lista encadeada do índice correspondente
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node *p = hash_table[index];
        while (p->next != NULL)
            p = p->next;
        p->next = new_node;
    }
}

int main() {
    int n;
    printf("Digite quantos elementos deseja inserir na tabela hash: ");
    scanf("%d", &n);
    
    // Define o tamanho da tabela como o primeiro primo maior que n
    int table_size = Primo(n);
    
    // Aloca a tabela hash (vetor de ponteiros para Node) e inicializa cada posição com NULL
    Node **hash_table = malloc(table_size * sizeof(Node*));
    for (int i = 0; i < table_size; i++)
        hash_table[i] = NULL;
    
    // Recebe os elementos do usuário e insere na tabela hash
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        Hash(hash_table, x, table_size);
    }
    
    // Imprime toda a tabela hash
    printf("\nTabela Hash:\n");
    for (int i = 0; i < table_size; i++){
        printf("Indice %d: ", i);
        Node *p = hash_table[i];
        while(p != NULL){
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
    
    // Libera a memória alocada para os nós e para a tabela
    for (int i = 0; i < table_size; i++){
        Node *p = hash_table[i];
        while(p != NULL){
            Node *temp = p;
            p = p->next;
            free(temp);
        }
    }
    free(hash_table);
    
    return 0;
}
