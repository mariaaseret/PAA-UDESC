#include "lista_privado.h"
#include "lista_interface.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#define SUCESSO 1
#define FRACASSO 0

int listaCriar(Lista** lista) {
    if (lista == NULL) return FRACASSO;
    
    *lista = (Lista*) malloc(sizeof(Lista));
    (*lista)->inicio = NULL;
    (*lista)->fim = NULL;

    return SUCESSO;
}

int listaDestruir(Lista** lista) {
    if (lista == NULL || *lista == NULL) return FRACASSO;

    listaReiniciar(*lista);

    free(*lista);
    *lista = NULL;

    return SUCESSO;
}

int listaReiniciar(Lista* lista) {
    if (lista == NULL) return FRACASSO;

    while (!listaVazia(lista)) {
        int tamanho_dados = lista->inicio->tamanho_dados;
        void* dados = malloc(tamanho_dados);
        listaRemoverInicio(lista, dados);
        free(dados);
    }

    return SUCESSO;
}

int listaInserirInicio(Lista* lista, int tamanho_dados, void* dados) {
    return listaInserirPos(lista, 0, tamanho_dados, dados);
}

int listaInserirFim(Lista* lista, int tamanho_dados, void* dados) {
    return listaInserirPos(lista, listaTamanho(lista), tamanho_dados, dados);
}

int listaInserirPos(Lista* lista, int pos, int tamanho_dados, void* dados) {
    if (lista == NULL || dados == NULL || pos < 0 || pos > listaTamanho(lista)) return FRACASSO;

    ListaNo* novo_no = (ListaNo*) malloc(sizeof(ListaNo));
    novo_no->tamanho_dados = tamanho_dados;
    novo_no->dados = malloc(tamanho_dados);

    memcpy(novo_no->dados, dados, tamanho_dados);

    ListaNo* no_anterior = NULL;
    ListaNo* no_atual = lista->inicio;
    int pos_atual = 0;
    while (pos_atual < pos) {
        pos_atual++;
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
    }

    if (no_anterior == NULL) {
        lista->inicio = novo_no;
    } else {
        no_anterior->proximo = novo_no;
    }
    novo_no->proximo = no_atual;
    if (no_atual == NULL) {
        lista->fim = novo_no;
    }


    lista->tamanho++;

    return SUCESSO;
}

int listaRemoverInicio(Lista* lista, void* dados) {
    return listaRemoverPos(lista, 0, dados);
}

int listaRemoverFim(Lista* lista, void* dados) {
    return listaRemoverPos(lista, listaTamanho(lista) - 1, dados);
}

int listaRemoverPos(Lista* lista, int pos, void* dados) {
    if (lista == NULL || dados == NULL || pos < 0 || pos >= listaTamanho(lista)) return FRACASSO;
    
    ListaNo* no_anterior = NULL;
    ListaNo* no_atual = lista->inicio;
    int pos_atual = 0;
    while (pos_atual < pos) {
        pos_atual++;
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
    }

    if (no_anterior == NULL) {
        lista->inicio = no_atual->proximo;
    } else {
        no_anterior->proximo = no_atual->proximo;
    }

    memcpy(dados, no_atual->dados, no_atual->tamanho_dados);
    free(no_atual);
    lista->tamanho--;

    return SUCESSO;
}

int listaBuscarInicio(Lista* lista, void* dados) {
    return listaBuscarPos(lista, 0, dados);
}

int listaBuscarFim(Lista* lista, void* dados) {
    return listaBuscarPos(lista, listaTamanho(lista) - 1, dados);
}

int listaBuscarPos(Lista* lista, int pos, void* dados) {
    if (lista == NULL || pos < 0 || pos >= listaTamanho(lista)) return FRACASSO;

    ListaNo* no_atual = lista->inicio;
    int pos_atual = 0;
    while (pos_atual < pos) {
        pos_atual++;
        no_atual = no_atual->proximo;
    }

    memcpy(dados, no_atual->dados, no_atual->tamanho_dados);

    return SUCESSO;
}

int listaTamanho(Lista* lista) {
    return lista == NULL ? 0 : lista->tamanho;
}

int listaVazia(Lista* lista) {
    return listaTamanho(lista) == 0;
}