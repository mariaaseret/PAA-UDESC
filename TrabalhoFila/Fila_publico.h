#include "Fila_privado.h"

Fila* criar(int tamanho_dados, int *resultado);
void enfileirar(Fila *f, void *elemento, int *resultado);
void* desenfileirar(Fila *f, int *resultado);
void destruir(Fila *f, int *resultado);