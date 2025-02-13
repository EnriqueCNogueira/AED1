#include <stdio.h>
#include <stdlib.h>

#define MAX_CASE 1000
#define MAX 500

struct node {
    int data;
    struct node *lef;
    struct node *rig;
};
typedef struct node Tree;

Tree* Insere(Tree* r, Tree* novo) {
    Tree *f, *p;
    if (r == NULL)
        return novo;
    f = r;
    while (f != NULL) {
        p = f;
        if (f->data > novo->data)
            f = f->lef;
        else
            f = f->rig;
    }
    if (p->data > novo->data)
        p->lef = novo;
    else
        p->rig = novo;
    return r;
}

void preOrder(Tree *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->lef);
        preOrder(root->rig);
    }
}

void inOrder(Tree *root) {
    if (root != NULL) {
        inOrder(root->lef);
        printf("%d ", root->data);
        inOrder(root->rig);
    }
}

void postOrder(Tree *root) {
    if (root != NULL) {
        postOrder(root->lef);
        postOrder(root->rig);
        printf("%d ", root->data);
    }
}

int main(){
    int cases, ncases[MAX_CASE];
    int input[MAX_CASE][MAX];
    Tree *root[MAX_CASE];
    
    scanf("%d", &cases);
    
    for (int i = 0; i < cases; i++){
        root[i] = NULL;
        scanf("%d", &ncases[i]);
        for (int j = 0; j < ncases[i]; j++){
            int valor;
            scanf("%d", &valor);
            Tree *novoNo = malloc(sizeof(Tree));
            novoNo->data = valor;
            novoNo->lef = NULL;
            novoNo->rig = NULL;
            root[i] = Insere(root[i], novoNo);
        }
        
        printf("Case %d:\n", i+1);
        printf("Pre.: ");
        preOrder(root[i]);
        printf("\n");

        printf("In..: ");
        inOrder(root[i]);
        printf("\n");
    
        printf("Post: ");
        postOrder(root[i]);
        printf("\n");
    }
    
    return 0;
}
