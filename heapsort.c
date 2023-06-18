#include <stdio.h>
#include <stdlib.h>
#include "fazheap.h"
#include <time.h>

void heapsort(int [], int);

int main(void){
    
    srand(time(NULL));

    int elementos[tamanho];

    puts("Antes da ordenacao:");
    for(int a = 0; a < tamanho; ++a){

        elementos[a] = 2 + rand() % (10*2 - 2 + 1);
        printf("%d\t", elementos[a]);
    }

    puts("\nDepois da ordenacao:");
    heapsort(elementos, tamanho);

    for(int a = 0; a < tamanho; ++a){

        printf("%d\t", elementos[a]);
    }
    return 0;
}

void heapsort(int vetor[], int tam){

    for(; tam > 0; --tam){

        fazMaxHeap(vetor, tam);
        int buffer = vetor[0];
        vetor[0] = vetor[tam - 1];
        vetor[tam - 1] = buffer;
    }

}