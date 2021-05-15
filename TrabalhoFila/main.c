#include <stdio.h>
#include <stdlib.h>
#include "Fila_publica.h"

int main(){
    
    int val1 =1;
    int val2 = 2;
    int val3 = 3;
    int resultado;
    
    struct Fila *fila = criar(5, &resultado);
    
    printf("f->inicio:   %p\n", fila->inicio);
    printf("f->fim:   %p\n", fila->fim);
    
    enfileirar(fila, (void*)val1,&resultado);
    printf("f->inicio:    %p\n", fila->inicio);
    printf("f->fim:   %p\n", fila->fim);
    //printf("f->inicio:    %i\n", fila->inicio->dados);
    //printf("f->fim:   %i\n", fila->fim->dados);
    
    enfileirar(fila, (void*)val2,&resultado);
    printf("f->inicio:   %p\n", fila->inicio);
    printf("f->fim:   %p\n", fila->fim);
    //printf("f->inicio:   %i\n", fila->inicio->dados);
    //printf("f->fim:   %i\n", fila->fim->dados);
    
    enfileirar(fila, (void*)val3,&resultado);
    printf("f->inicio:   %p\n", fila->inicio);
    printf("f->fim:   %p\n", fila->fim);
    //printf("f->inicio:   %i\n", fila->inicio->dados);
    //printf("f->fim:   %i\n", fila->fim->dados);
    
    desenfileirar(fila,&resultado);
    printf("f->inicio:   %p\n", fila->inicio);
    printf("f->fim:   %p\n", fila->fim);
    //printf("f->inicio:   %i\n", fila->inicio->dados);
    //printf("f->fim:   %i\n", fila->fim->dados);
}