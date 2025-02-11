#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int n;
    struct Node *seg;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Lista;

void inicializar_lista(Lista *lista) {
    lista->head = malloc(sizeof(Node));
    lista->head->seg = NULL;
    lista->tail = lista->head; 
}

void Push(Lista *lista, int indice) {
    Node *nova = malloc(sizeof(Node));
    nova->n = indice;
    nova->seg = NULL;
    
    lista->tail->seg = nova; 
    lista->tail = nova;     
}

void BuscaERemove(int x, Lista *lista) {
    Node *p = lista->head;
    Node *q = lista->head->seg;
    
    while (q != NULL && q->n != x) {
        p = q;
        q = q->seg;
    }
    
    if (q != NULL) {
        p->seg = q->seg;
        
        if (q == lista->tail) { 
            lista->tail = p;
        }
        
        free(q);
    }
}

void Pop(Lista *lista) {
    Node *temp = lista->head->seg;
    int primeiro = 1; 

    while (temp != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", temp->n);
        primeiro = 0;
        temp = temp->seg;
    }
    printf("\n");
}

void liberar_lista(Lista *lista) {
    Node *temp;
    while (lista->head != NULL) {
        temp = lista->head;
        lista->head = lista->head->seg;
        free(temp);
    }
}

int main() {
    Lista lista;
    inicializar_lista(&lista);

    int tam, sai, indice;
    
    // Lê o tamanho da lista
    scanf("%d", &tam);
    
    // Lê o identificador de cada pessoa e adiciona na lista
    for (int i = 0; i < tam; i++) {
        scanf("%d", &indice);
        Push(&lista, indice);
    }
    
    // Lê quantas pessoas vão sair
    scanf("%d", &sai);
    
    // Lê o identificador de cada pessoa e as remove da lista
    for (int i = 0; i < sai; i++) {
        scanf("%d", &indice);
        BuscaERemove(indice, &lista);
    }
    
    // Imprime a lista final
    Pop(&lista);
    
    // Libera a memória da lista
    liberar_lista(&lista);

    return 0;
}
