//Lista Linear Dinâmica Simplesmente Encadeada
// Homogênea 
// simplemesmente encadeada - somente para o próximo

#include <stdio.h>
#include <stdlib.h>
#include "lista_publico.h"


typedef struct noLista {
	void* dados;
	struct noLista *prox;
} noLista;

typedef struct descritor {    
	noLista *inicio;
	int tamanho_dados; 
	int qtdeNos;
} descritor;


noLista* criarNo(descritor* fila, void* elemento);
void *buscarNo(pLista lista, int pos);
int validarPosicaoInformada(pLista lista, int pos);
int listaVazia(pLista lista);
int listaCheia(pLista lista);


