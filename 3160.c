#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct amigo {
    char nome[20];
    struct amigo *seg;
};

typedef struct amigo Amigo;

void Insere(char aux[20], Amigo **cabeca, int tam) {
    Amigo *novo = malloc(sizeof(Amigo));
    strcpy(novo->nome, aux);
    novo->seg = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        Amigo *p = *cabeca;
        while (p->seg != NULL) {
            p = p->seg;
        }
        p->seg = novo;
    }
}

void BuscaEInsere(Amigo *cabeca, Amigo *cabecanova, char indica[20]) {
    Amigo *p = NULL, *q = cabeca, *rabonova = cabecanova;

    while (rabonova->seg != NULL) {
        rabonova = rabonova->seg;
    }

    while (q != NULL && strcmp(q->nome, indica) != 0) {
        p = q;
        q = q->seg;
    }

    if (p != NULL) {
        p->seg = cabecanova;
        rabonova->seg = q;
    }
}

void Imprima(Amigo *cabeca) {
    while (cabeca != NULL) {
        if(cabeca->seg != NULL){
            printf("%s ", cabeca->nome);
            cabeca = cabeca->seg;
        }else{
            printf("%s", cabeca->nome);
            cabeca = cabeca->seg;
        }
    }
}

int main() {
    char lista[1000], listanova[1000], aux[20], indica[20];
    int cont = 0;
    Amigo *cabeca = NULL, *cabecanova = NULL;

    fgets(lista, 1000, stdin);
    fgets(listanova, 1000, stdin);
    
    int len = strlen(lista);

    if (len > 0 && lista[len - 1] == '\n') {
        lista[len - 1] = '\0';
    }
    
    len = strlen(listanova);

    if (len > 0 && listanova[len - 1] == '\n') {
        listanova[len - 1] = '\0';
    }

    for (int i = 0; i <= strlen(lista); i++) {
        if (lista[i] != ' ' && lista[i] != '\0') {
            aux[cont++] = lista[i];
        } else {
            aux[cont] = '\0';
            Insere(aux, &cabeca, cont);
            cont = 0;
        }
    }

    for (int i = 0; i <= strlen(listanova); i++) {
        if (listanova[i] != ' ' && listanova[i] != '\0') {
            aux[cont++] = listanova[i];
        } else {
            aux[cont] = '\0';
            Insere(aux, &cabecanova, cont);
            cont = 0;
        }
    }

    fgets(indica, 20, stdin);
    indica[strcspn(indica, "\n")] = '\0';

    if (strcmp(indica, "nao") == 0) {
        Imprima(cabeca);
        printf(" ");
        Imprima(cabecanova);
    } else if(strcmp(indica, cabeca->nome) == 0) {
        Imprima(cabecanova);
        printf(" ");
        Imprima(cabeca);
    } else {
        BuscaEInsere(cabeca, cabecanova, indica);
        Imprima(cabeca);
    }

    printf("\n");
    return 0;
}
