#ifndef _LDDE_PRIVADA
#define _LDDE_PRIVADA

#include "ldde_publica.h"

typedef struct noLdde noLdde;

typedef struct ldde{
    noLdde * inicio, *fim;
    int tamanho_dados;
    int quantidade_nos;
}ldde;

struct noLdde{
    void * dados;
    noLdde * ant;
    noLdde * prox;
};

#endif
