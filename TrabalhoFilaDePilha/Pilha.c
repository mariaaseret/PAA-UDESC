#include "Pilha_privado.h"
#include <string.h>

void cria_pilha(ppPilha pilha, int altura_pilha, int size_data) {
	*pilha = malloc(sizeof(Pilha));
	(*pilha)->data = malloc(size_data * altura_pilha);
	(*pilha)->top = -1;
	(*pilha)->altura_pilha = altura_pilha;
	(*pilha)->size_data = size_data;
}

void destroi_pilha(ppPilha pilha) {
  free((*pilha)->data);
  free((*pilha));
  (*pilha) = NULL;
}

void empilha(pPilha pilha, void *elem) {
  if (pilha == NULL) {
    printf("Pilha não existe\n");
    exit(1);
  }
  if (pilha_cheia(pilha)) {
    printf("Pilha cheia\n");
    exit(1);
  }
  pilha->top++;
  memcpy(pilha->data + pilha->top * pilha->size_data, elem, pilha->size_data);
}

void *desempilha(pPilha pilha) {
  void *ret = olha_topo(pilha);
  pilha->top--;
  return ret;
}

void *olha_topo(pPilha pilha) {
  if (pilha == NULL || pilha->data == NULL) {
    printf("Pilha não existe\n");
    exit(1);
  }
  if (pilha_vazia(pilha)) {
    printf("Pilha vazia\n");
    return NULL;
  }
  void *ret = malloc(pilha->size_data);
  memcpy(ret, pilha->data + pilha->top * pilha->size_data, pilha->size_data);

  return ret;
}

int pilha_cheia(pPilha pilha) {
	return pilha->top >= pilha->altura_pilha-1;
}

int pilha_vazia(pPilha pilha) {
	return pilha->top <= -1;
}
