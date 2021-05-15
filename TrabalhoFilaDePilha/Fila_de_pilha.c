#include <stdio.h>
#include <stdlib.h>
#include "Fila_de_pilha_privado.h"

pFilaDePilha cria(int tamanho_dados, int* resultado) {
	pFilaDePilha filaDePilha = malloc(sizeof(filaDePilha));
	pFila fila = cria_fila(sizeof(pPilha), resultado);
	if (*resultado == FRACASSO) return NULL;

	filaDePilha->fila = fila;
	filaDePilha->pilha_atual = NULL;
	filaDePilha->tamanho_dados = tamanho_dados; 
	return filaDePilha;
}

void insere(pFilaDePilha fp, void* elemento, int* resultado) {
	// Garantimos que a fila sempre tem uma pilha não cheia no final, apontada por pilha_atual
	if (fila_vazia(fp->fila)) {
		enfileira_nova_pilha(fp, resultado);
		if (*resultado == FRACASSO) return;
	}

	if (pilha_cheia(fp->pilha_atual)) {
		enfileira_nova_pilha(fp, resultado);
		if (*resultado == FRACASSO) return;
	}

	empilha(fp->pilha_atual, elemento);
}

void* retira(pFilaDePilha fp, int* resultado) {
	if (fila_vazia(fp->fila)) {
		fp->pilha_atual = NULL;
		*resultado = FRACASSO;
		return NULL;
	}

	pPilha pilha_inicial = *(pPilha *)olha_inicio(fp->fila, resultado);
	if (*resultado == FRACASSO) return NULL;

	void* elemento = desempilha(pilha_inicial);

	// Se acabamos de desempilhar todos os elementos uma pilha, ela pode ser desenfileirada e destruida
	if (pilha_vazia(pilha_inicial)) {
		pPilha* pilha = desenfileira(fp->fila, resultado);
		if (*resultado == FRACASSO) return NULL;
		destroi_pilha(pilha);
		free(pilha);
	}

	*resultado = SUCESSO;
	return elemento;
}

void destroi(pFilaDePilha fp, int* resultado) {
	do {
        void* elemento = retira(fp, resultado);
        if (*resultado == FRACASSO) break;
		free(elemento);
    } while (*resultado == SUCESSO);

	destroi_fila(fp->fila, resultado);
	if (*resultado == FRACASSO) return;
	fp->pilha_atual = NULL;
	*resultado = SUCESSO;
}

void enfileira_nova_pilha(pFilaDePilha fp, int* resultado) {
	pPilha pilha;
	cria_pilha(&pilha, 3, fp->tamanho_dados);
	enfileira(fp->fila, &pilha, resultado);
	fp->pilha_atual = pilha;
}
