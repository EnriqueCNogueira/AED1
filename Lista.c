#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int cont;
    struct list *next;
} Node;

// Função para imprimir a lista (assumindo nó cabeça com sentinela)
void Print(Node *head) {
    Node *p = head->next;  // pula o nó cabeça (sentinela)
    while (p != NULL) {
        printf("%d\n", p->cont);
        p = p->next;
    }
}

// Função recursiva para buscar um elemento na lista
// Procura a partir de 'lst' (não incluindo o nó cabeça)
Node* SearchR(int x, Node *lst) {
    if (lst == NULL)
        return NULL;
    if (lst->cont == x)
        return lst;
    return SearchR(x, lst->next);
}

// Insere um novo nó logo após o nó cabeça (método de inserção no início)
void Insert(int x, Node *head) {
    Node *novo = malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novo->cont = x;
    novo->next = head->next;
    head->next = novo;
}

// Remove o primeiro nó que contenha o valor x
void SearchRemove(int x, Node *head) {
    Node *p = head;
    Node *q = head->next;
    
    while (q != NULL && q->cont != x) {
        p = q;
        q = q->next;
    }
    
    if (q != NULL) {
        p->next = q->next;
        free(q);
        printf("Elemento %d removido com sucesso.\n", x);
    } else {
        printf("Elemento %d nao encontrado.\n", x);
    }
}

int main(){
    int opcao = 1, x;
    
    // Aloca o nó cabeça (sentinela) e inicializa a lista vazia
    Node *head = malloc(sizeof(Node));
    if (head == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    head->next = NULL;
    
    while(opcao != 0) {
        printf("\nDigite 1 para inserir.\n");
        printf("Digite 2 para remover.\n");
        printf("Digite 3 para buscar.\n");
        printf("Digite 4 para imprimir.\n");
        printf("Digite 0 para parar.\n");
        printf("Opcao: ");
        
        // Use o endereço da variável para armazenar a opção lida
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o numero que deseja inserir: ");
                scanf("%d", &x);
                Insert(x, head);
                break;
                
            case 2:
                printf("Digite o numero que deseja remover: ");
                scanf("%d", &x);
                SearchRemove(x, head);
                break;
                
            case 3: {
                printf("Digite o numero que deseja buscar: ");
                scanf("%d", &x);
                // Busca na lista (pulando o nó cabeça)
                Node *resultado = SearchR(x, head->next);
                if (resultado != NULL)
                    printf("Elemento encontrado: %d\n", resultado->cont);
                else
                    printf("Elemento nao encontrado.\n");
                break;
            }
                
            case 4:
                printf("Lista:\n");
                Print(head);
                break;
                
            case 0:
                printf("Encerrando...\n");
                break;
                
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }
    
    // Libera toda a memória alocada para a lista
    Node *p = head;
    while (p != NULL) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    
    return 0;
}
