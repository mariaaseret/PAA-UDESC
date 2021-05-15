#include <stdio.h>
#include <stdlib.h>
#include "Fila_interface.h"

typedef struct noFila {
	void* dados;
	struct noFila *ant;
} noFila;


typedef struct Fila {
	noFila *inicio, *fim;
	int tamanho_dados; 
} Fila;
