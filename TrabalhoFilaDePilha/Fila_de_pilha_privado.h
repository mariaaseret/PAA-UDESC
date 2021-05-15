#include <stdio.h>
#include <stdlib.h>
#include "Fila_interface.h"
#include "Pilha_interface.h"
#include "Fila_de_pilha_interface.h"

typedef struct filaDePilha {
	pFila fila;
	pPilha pilha_atual;
	int tamanho_dados; 
} filaDePilha;

void enfileira_nova_pilha(pFilaDePilha fp, int* resultado);
