#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define esquerda(i) ((i << 1) + 1)
#define direita(i) ((esquerda(i)) + 1)
#define pai(i) (i >> 1)

#define tamanho 6

void max_heapfy(int [], int, int);
void min_heapfy(int [], int, int);

void max_heapfy_iter(int [], int, int);

void fazMaxHeap(int [], int);
void fazMinHeap(int [], int);

int main(void){

    srand(time(NULL));

    int elementos[tamanho];

    for(int a = 0; a < tamanho; ++a){

        elementos[a] = 2 + rand() % (10*2 - 2 + 1);
    }

    for(int a = 0; a < tamanho; ++a){

        printf("%d\t",elementos[a]);
    }

    
    fazMaxheap(elementos, tamanho);
    printf("depois do heapfy:\n");
    for(int a = 0; a < tamanho; ++a){

        printf("%d\t",elementos[a]);
    }




    return 0;
}

void max_heapfy(int elementos[], int i, int tam){

    int esquerd = esquerda(i);

    int direit = esquerd + 1;

    int maior = i;

    if (esquerd < tam && elementos[esquerd] > elementos[maior]){
        
        maior = esquerd;
    }

    if(direit < tam && elementos[direit] > elementos[maior]){

        maior = direit;
    }

    if (maior != i){
      
        int buffer = elementos[maior];
        elementos[maior] = elementos[i];
        elementos[i] = buffer;
        max_heapfy(elementos, maior, tam);
    }

}

void min_heapfy(int elementos[], int i, int tam){

    int esquerd = esquerda(i);

    int direit = esquerd + 1;

    int menor = i;

    if (esquerd < tam && elementos[esquerd] < elementos[menor]){
        
        menor = esquerd;
    }

    if(direit < tam && elementos[direit] < elementos[menor]){

        menor = direit;
    }

    if (menor != i){
      
        int buffer = elementos[menor];
        elementos[menor] = elementos[i];
        elementos[i] = buffer;
        min_heapfy(elementos, menor, tam);
    }

}

void max_heapfy_iter(int elementos[], int i,int tam){

    
    int maior = i;
    while(i < (tam >> 1)){
        int esq = esquerda(i);
        int dir = esq + 1;

        if(elementos[esq] > elementos[maior]){
            maior = esq;
        }
        if(dir < tam && elementos[dir] > elementos[maior]){
            maior = dir;
        }

        if(maior == i) break;

        int buffer = elementos[maior];
        elementos[maior] = elementos[i];
        elementos[i] = buffer;
        i = maior;
    }
}

void min_heapfy_iter(int elementos[], int i,int tam){

    
    int menor = i;
    while(i < (tam >> 1)){
        int esq = esquerda(i);
        int dir = esq + 1;

        if(elementos[esq] < elementos[menor]){
            menor = esq;
        }
        if(dir < tam && elementos[dir] < elementos[menor]){
            menor = dir;
        }

        if(menor == i) break;

        int buffer = elementos[menor];
        elementos[menor] = elementos[i];
        elementos[i] = buffer;
        i = menor;
    }
}

void fazMaxHeap(int elementos[], int tam){

    for(int a = tam >> 1; a >= 0; --a){

        max_heapfy_iter(elementos,a,tam);
    }
}

void fazMinHeap(int elementos[], int tam){

    for(int a = tam >> 1; a >= 0; --a){

        min_heapfy_iter(elementos,a,tam);
    }

}