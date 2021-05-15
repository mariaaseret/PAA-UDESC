#include <stdlib.h>
#include <string.h>

typedef struct NoLista {
    void *elemento;
    int tamanho_elemento;
    struct NoLista *ant, *prox;
} NoLista;

typedef struct Lista {
    int tamanho_maximo;
    NoLista *inicio, *fim;
} Lista;

void insere(NoLista* no_lista, void* elemento, int tamanho_elemento, int* resultado);
void remover(NoLista* no_lista, int* resultado);
NoLista* no_inicio(Lista* lista);
NoLista* no_fim(Lista* lista);
NoLista* no_pos(Lista* lista, int pos, int* resultado);
