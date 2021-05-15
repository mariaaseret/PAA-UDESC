#ifndef __LISTA_PRIVADO_H__
#define __LSITA_PRIVADO_H__
#include "Lista_publica.h"

// Definicao das constantes
#define SUCESSO 1   // Quando houver sucesso, retorna 1
#define FRACASSO 0  // Quando houver fracasso, retorna 0

struct NoLista
{
    void * dados;
    struct NoLista *prox; //Simmplesmente encadeada, controla apenas uma direcao
};

struct Lista
{
    struct NoLista * inicio, * fim;
    int tamanho_dados;
    int tamanho_max;
    int tamanho_atual;
};

#endif /* __LISTA_PRIVADO_H__ */

