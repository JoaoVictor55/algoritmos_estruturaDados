#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particionar(int[],int,int);
int particionarRandom(int[], int, int);
void quickSort(int[], int, int);
void quickSortRandom(int[], int, int);

int main(void){

    srand(time(NULL));

    int p[] = {2,	1,	3,	4,	7,	5,	6,	8};

    quickSortRandom(p, 0, 8);

    for(int a = 0; a <= 7; ++a)
        printf("%d\n",p[a]);
    return 0;
}

int particionarRandom(int vetor[], int inicio, int fim)
{
    int i = (rand()%(fim - inicio + 1)) + inicio;
    int buff = vetor[fim-1];
    vetor[fim-1] = vetor[i];
    vetor[i] = buff;
    return particionar(vetor, inicio, fim);
}

void quickSortRandom(int vetor [], int inicio, int fim){

    if(inicio < fim){

        int q = particionarRandom(vetor, inicio, fim);
        quickSortRandom(vetor, inicio, q-1);
        quickSortRandom(vetor, q+1, fim);
    }
}

void quickSort(int vetor [], int inicio, int fim){

    if(inicio < fim){

        int q = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio,q-1);
        quickSort(vetor, q+1, fim);
    }
}

int particionar(int vetor[], int inicio, int pivo){

    int i = inicio - 1;
    for(int a = inicio; a < pivo; ++a){

        if(vetor[a] <= vetor[pivo]){
            
            ++i;
            int x = vetor[a];
            vetor[a] = vetor[i];
            vetor[i] = x;
        }
    }

    int x = vetor[++i];
    vetor[i] = vetor[pivo];
    vetor[pivo] = x;
    return i;
}