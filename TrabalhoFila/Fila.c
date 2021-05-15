#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila_publica.h"

Fila *criar(int tamanho_dados, int *resultado){
  Fila* f = (Fila *) malloc(sizeof(Fila));
  if(f != NULL){
    f->tamanho_dados = tamanho_dados;
    f->inicio = NULL;
    f->fim = NULL;
  }else{
    *resultado = ERRO;
  }
  return f;
}

void enfileirar(Fila *f, void *elemento, int *resultado){
    NoFila *no;
    no=malloc(sizeof(NoFila));
    if(no==NULL){
        *resultado=ERRO;
    }
    no->dados = elemento;
    no->ant = NULL;
    if(f->inicio==NULL){
        f->inicio = no;
    }else{
        f->fim->ant = no;
    }
    f->fim = no;
    *resultado=SUCESSO;
}

void *desenfileirar(Fila *f, int *resultado){
    NoFila *no;
    void *info;
    if(f->inicio==NULL){
        *resultado=ERRO;
        return NULL;
    }
    no=f->inicio;
    info=(void *)no->dados;
    f->inicio = no->ant;
    if(f->inicio==NULL){
        f->fim = NULL;
    }
    free(no);
    *resultado = SUCESSO;
    return info;
}

void destruir(Fila *f, int *resultado){
    NoFila *noApagar, *proxNo;
    if(!(f->inicio==NULL)){
        proxNo = f->inicio;
        while(proxNo != NULL){
            noApagar = proxNo;
            proxNo = proxNo->ant;
            free(noApagar);
        }
    }
    free(f);
}
int cheia(Fila *f)
{
    NoFila *no = malloc(sizeof(NoFila));

    if (!no)
        return SUCESSO;
    else
        return ERRO;

    free(no);
}
int vazia(Fila *f)
{
    if (f == NULL)
        return SUCESSO;
    if (f->inicio == NULL)
        return SUCESSO;
    else
        return ERRO;
}