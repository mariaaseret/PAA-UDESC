#include <stdio.h>
#include <stdlib.h>

#include "ldde_publica.h"

int main(){
    int elemento = 0, i = 5;
    pldde lista = NULL;

    if(CriarLista(&lista, sizeof(int)) == ERRO){
        printf("Erro ao criar a lista!\n");
        exit(1);
    }
    InserirInicio(lista, (void *) &i);
    i = 7;
    InserirFim(lista, (void *) &i);
    i = 6;
    InserirPos(lista, (void *) &i, 0);

    printf("elemento: %d\n", *(int *) BuscarInicio(lista));
    printf("elemento: %d\n", *(int *) BuscarPos(lista, 1));
    printf("elemento: %d\n", *(int *) BuscarFim(lista));

    if(DestruirLista(&lista) == ERRO){
        printf("Erro ao destruir a lista!\n");
        exit(1);
    }

}
