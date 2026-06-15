#include <stdio.h>
#include <stdlib.h>
#include "TADtrabalho.h"

//const MAX_SIZE = 50;

struct fila {
    int *v;
    int capacidade;
    int end;
};

void cresce_fila(fila *vet) {
    int new_capacidade = 2*vet->capacidade;
    int *new_v = malloc(new_capacidade*sizeof(int));

    for(int i=0; i<vet->end; i++) {
        new_v[i] = vet->v[i];
    }

    free(vet->v);
    vet->v = new_v;
}

fila *initFila(int start_size) {
    fila *vet = malloc(sizeof(fila));

    vet->v = malloc(start_size*sizeof(int));
    if(vet->v == NULL) {
        free(vet);
        printf("A criação da fila falhou.");
        return NULL;
    }
    vet->capacidade = start_size;
    vet->end = 0;
    return vet;
}

void deleteFila(fila *vet) {
    if(vet != NULL) {
        free(vet->v);
        free(vet);
    }
}

int fila_vazia(fila *vet) {
    return (vet->end == 0);
}

int fila_cheia(fila *vet) {
    return (vet->end == vet->capacidade);
}

void inserirNaFila(fila *vet, int x) {
    if (fila_cheia(vet)) {
        cresce_fila(vet);
    }
    vet->v[vet->end] = x;
    vet->end = vet->end+1;
}

int removerDaFila(fila *vet) {
    if(fila_vazia(vet)) {
        printf("\nA fila já está vazia.");
        return -1;
    }

    int removed = vet->v[0]; 

    for(int i=0; i<vet->end-1; i++) {
        vet->v[i] = vet->v[i+1];
    }
    vet->end = vet->end-1;
}

void imprimirFila(fila *vet) {
    if(fila_vazia(vet)) {
        printf("\nA fila está vazia.");
        return;
    }

    for(int i=0; i<vet->end; i++) {
        printf("%d ", vet->v[i]);
    }
}

int main() {
    fila *vet = initFila(10);
    for(int i=0; i<11; i++) {
        inserirNaFila(vet, i);
    }
    imprimirFila(vet);

    printf("\n");

    for(int i=0; i<5; i++) {
        removerDaFila(vet);
    }
    imprimirFila(vet);

    printf("\n");

    for(int i=0; i<11; i++) {
        inserirNaFila(vet, i);
    }
    imprimirFila(vet);
}