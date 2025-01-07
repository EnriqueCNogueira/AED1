//Este código utiliza o algoritmos QuickSort para ordenar um vetor em ordem crescente

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 10000; //constante para tamanho do vetor

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void QuickSort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        QuickSort (p, j - 1, v);
        QuickSort (j + 1, r, v);
    }
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); 
    QuickSort(0, TAM, vetor);
    t = clock() - t; 

    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
