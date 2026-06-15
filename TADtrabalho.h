#ifndef TAD
#define TAD

#include <stdio.h>
#include <stdlib.h>

typedef struct fila fila;

fila *initFila(int start_size);
void deleteFila(fila *vet);
void inserirNaFila(fila *vet, int x);
int removerDaFila(fila *vet);
void imprimirFila(fila *vet);

#endif