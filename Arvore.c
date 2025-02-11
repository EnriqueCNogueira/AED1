#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da árvore
struct arvore {
    int cont;
    struct arvore *esq;
    struct arvore *dir;
};
typedef struct arvore no;

// Função para inserir um novo nó na árvore
no* inserir(no* raiz, int valor) {
    if (raiz == NULL) {
        no* novo = (no*) malloc(sizeof(no));
        if (novo == NULL) {
            printf("Erro de alocacao!\n");
            exit(1);
        }
        novo->cont = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->cont)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->cont)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Função para buscar um valor na árvore
no* buscar(no* raiz, int valor) {
    if (raiz == NULL || raiz->cont == valor)
        return raiz;
    if (valor < raiz->cont)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

// Função auxiliar para encontrar o nó com o menor valor (usada na remoção)
no* encontrarMin(no* raiz) {
    while (raiz && raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

// Função para remover um nó da árvore
no* remover(no* raiz, int valor) {
    if (raiz == NULL)
        return raiz;
    if (valor < raiz->cont)
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->cont)
        raiz->dir = remover(raiz->dir, valor);
    else {  // Nó encontrado
        if (raiz->esq == NULL) {
            no* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            no* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        // Nó com dois filhos: encontra o sucessor (menor nó na subárvore direita)
        no* temp = encontrarMin(raiz->dir);
        raiz->cont = temp->cont;
        raiz->dir = remover(raiz->dir, temp->cont);
    }
    return raiz;
}

// Função para imprimir os valores da árvore em ordem (in-order)
void imprimir(no* raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esq);
        printf("%d ", raiz->cont);
        imprimir(raiz->dir);
    }
}

// Função auxiliar para contar os nós da árvore
int contarNos(no* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

// Função auxiliar para preencher um array com os valores da árvore (pré-ordem)
void preencherArray(no* raiz, int *arr, int *index) {
    if (raiz == NULL)
        return;
    arr[(*index)++] = raiz->cont;
    preencherArray(raiz->esq, arr, index);
    preencherArray(raiz->dir, arr, index);
}

// Função auxiliar para ordenar um array de inteiros (Bubble Sort)
void ordenar(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função auxiliar para construir uma árvore completa (heap mínimo)
// a partir de um array ordenado, onde o pai dos índices 2*i+1 e 2*i+2
// é o elemento do índice i.
no* construirHeap(int *arr, int n) {
    if (n == 0)
        return NULL;
    no **nos = (no**) malloc(n * sizeof(no*));
    int i;
    for (i = 0; i < n; i++) {
        nos[i] = (no*) malloc(sizeof(no));
        if (nos[i] == NULL) {
            printf("Erro de alocacao!\n");
            exit(1);
        }
        nos[i]->cont = arr[i];
        nos[i]->esq = NULL;
        nos[i]->dir = NULL;
    }
    for (i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n)
            nos[i]->esq = nos[left];
        if (right < n)
            nos[i]->dir = nos[right];
    }
    no* novaRaiz = nos[0];
    free(nos);
    return novaRaiz;
}

// Função para balancear a árvore transformando-a em um heap mínimo.
// O procedimento é: contar os nós, armazenar os valores em um array,
// ordenar o array e reconstruir a árvore completa a partir dele.
no* balancear(no* raiz) {
    int n = contarNos(raiz);
    if (n == 0)
        return NULL;
    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    int index = 0;
    preencherArray(raiz, arr, &index);
    ordenar(arr, n);
    no* novaRaiz = construirHeap(arr, n);
    free(arr);
    return novaRaiz;
}

// Função para liberar a memória alocada na árvore
void liberar(no* raiz) {
    if (raiz == NULL)
        return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main(){
    int opcao = 1, x;
    no *raiz = NULL;
    
    while(opcao != 0) {
        printf("\n----- MENU -----\n");
        printf("Digite 1 para inserir.\n");
        printf("Digite 2 para remover.\n");
        printf("Digite 3 para buscar.\n");
        printf("Digite 4 para imprimir (em ordem).\n");
        printf("Digite 5 para balancear a arvore (heap minimo).\n");
        printf("Digite 0 para sair.\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &x);
                raiz = inserir(raiz, x);
                break;
            case 2:
                printf("Digite o valor a remover: ");
                scanf("%d", &x);
                raiz = remover(raiz, x);
                break;
            case 3: {
                printf("Digite o valor a buscar: ");
                scanf("%d", &x);
                no *resultado = buscar(raiz, x);
                if (resultado)
                    printf("Valor %d encontrado na arvore.\n", resultado->cont);
                else
                    printf("Valor %d nao encontrado na arvore.\n", x);
                break;
            }
            case 4:
                printf("Arvore (em ordem): ");
                imprimir(raiz);
                printf("\n");
                break;
            case 5:
                raiz = balancear(raiz);
                printf("Arvore balanceada (heap minimo): ");
                imprimir(raiz);
                printf("\n");
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }
    
    liberar(raiz);
    return 0;
}
