#include "Fila_privado.h"
#include <string.h>

Fila* cria_fila(int tamanho_dados, int* resultado){
	if (tamanho_dados < 1) {
		*resultado = 0;
		return NULL;
	}
	Fila* fila = malloc(sizeof(Fila));
	fila->tamanho_dados = tamanho_dados;
	fila->inicio = NULL;
	fila->fim = NULL;
	*resultado = 1;
	return fila;
}

void enfileira(Fila* f, void* elemento, int* resultado) {
	if (f == NULL){
		*resultado = 0;
		return;	
	} 
	noFila* aux = malloc(sizeof(noFila));
	aux->dados = malloc(f->tamanho_dados);
	memcpy(aux->dados, elemento, f->tamanho_dados);
	if (f->inicio == NULL) {
		f->inicio = aux;
		f->fim = aux;
	} else {
		f->fim->ant = aux;
		f->fim = aux;
	}
	aux->ant = NULL;
	*resultado = 1;
	return;
}

void* desenfileira(Fila* f, int* resultado) {
	if (f == NULL || fila_vazia(f)) {
		*resultado = 0;
		return NULL;
	}
	noFila* aux = f->inicio;
	f->inicio = aux->ant;
	if (f->inicio == NULL) {
		f->fim = NULL;
	}
	void* res = malloc(f->tamanho_dados);
	memcpy(res, aux->dados, f->tamanho_dados);
	free(aux->dados);
	free(aux);
	*resultado = 1;
	return res;
}

void* olha_inicio(pFila f, int* resultado) {
	if (f == NULL || fila_vazia(f)) {
		*resultado = 0;
		return NULL;
	}
	noFila* aux = f->inicio;
	void* res = malloc(f->tamanho_dados);
	memcpy(res, aux->dados, f->tamanho_dados);
	*resultado = 1;
	return res;
}


void destroi_fila(Fila *f, int* resultado) {
	if (f == NULL) {
		*resultado = 0;
		return;
	}
	int r;
	while(desenfileira(f, &r) != NULL);
	free(f);	
	*resultado = 1;
	return;
}

int fila_vazia(Fila* f) {
	if(f != NULL && f->fim == NULL) {
		return 1;
	}
	return 0;
}
