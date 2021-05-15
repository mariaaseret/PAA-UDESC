#ifndef _lista_publica
#define _lista_publica

#include "Lista_privada.h"

#define SUCESSO 0
#define FRACASSO 1

typedef struct Lista *pLista;

pLista criar_lista(int tamanho_dados, int *resultado);
void reiniciar_lista(pLista lista, int *resultado);
void destruir_lista(pLista lista, int *resultado);

void* buscar_inicio(pLista lista, int* resultado);
void* buscar_fim(pLista lista, int* resultado);
void* buscar_pos(pLista lista, int pos, int* resultado);

void inserir_inicio(pLista lista, void* elemento, int tamanho_elemento, int* resultado);
void inserir_fim(pLista lista, void* elemento, int tamanho_elemento, int* resultado);
void inserir_pos(pLista lista, int pos, void* elemento, int tamanho_elemento, int* resultado);

void remover_inicio(pLista lista, int* resultado);
void remover_fim(pLista lista, int* resultado);
void remover_pos(pLista lista, int pos, int* resultado);
#endif
