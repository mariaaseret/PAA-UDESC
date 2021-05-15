#include <stdio.h>
#include "Lista_publica.h"

int main() {
    int resultado;
    char elemento1[] = {'a', 'b', 'c', '\0'};
    char *retorno;

    pLista lista = criar_lista(4, &resultado);
    inserir_inicio(lista, elemento1, 4*sizeof(char), &resultado);
    printf("resultado: %i\n", resultado);
    retorno = buscar_inicio(lista, &resultado);
    printf("resultado: %i\n", resultado);
    printf("retorno: %s\n", (char *)retorno);

    char elemento2[] = {'c', 'd', 'e', '\0'};
    inserir_fim(lista, elemento2, 4*sizeof(char), &resultado);
    printf("resultado: %i\n", resultado);
    retorno = buscar_fim(lista, &resultado);
    printf("resultado: %i\n", resultado);
    printf("retorno: %s\n", (char *)retorno);

    int elemento3 = 15;
    inserir_pos(lista, 2, &elemento3, sizeof(int), &resultado);
    printf("resultado: %i\n", resultado);
    retorno = buscar_pos(lista, 2, &resultado);
    printf("resultado: %i\n", resultado);
    printf("retorno: %i\n", *(int *)retorno);

    remover_pos(lista, 2, &resultado);
    printf("resultado: %i\n", resultado);
    retorno = buscar_pos(lista, 2, &resultado);
    printf("resultado: %i\n", resultado);
    printf("retorno: %i\n", (int *)retorno);

    reiniciar_lista(lista, &resultado);
    printf("resultado: %i\n", resultado);
    retorno = buscar_fim(lista, &resultado);
    printf("resultado: %i\n", resultado);
    printf("retorno: %s\n", (char *)retorno);

    destruir_lista(lista, &resultado);
    printf("resultado: %i\n", resultado);

    return 0;
}
