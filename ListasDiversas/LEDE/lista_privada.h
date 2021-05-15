#ifndef LISTA_PRIVADA_H
#define LISTA_PRIVADA_H

#include "lista_publica.h"

// Elemento
// *dado -> qualquer dado a ser armazenado no elemento
// posicao_anterior -> elemento anterior
// posicao_proximo -> proximo elemento
typedef struct Elemento{
    void * dado;
    int posicao_anterior;
    int posicao_proximo;
} Elemento;

// Lista
// tamanho_total_lista -> todo o tamanho da lista ex.: 5
// tamanho_elemento -> tamanho do elemento ex.: sizeof(char[15])
// tamanho_atual -> tamanho atual da lista ex.: 5 se cheia
// posicoes_ocupadas -> lista de posicoes ocupadas 0 se existe valor na posicao,
// 1 se não tem elemento na posicao ex.: [1, 0, 0, 0, 1] contem elementos na pos: 0 e 4 e não contem nas posicoes: 1, 2, 3
// posicao_primeiro_elemento -> posicao na lista do primeiro elemento
// posicao_ultimo_elemento ->posicao na lista do ultimo elemento
// elementos -> lista de elementos
typedef struct Lista{
    int tamanho_total_lista;
    int tamanho_elemento;
    int tamanho_atual;
    int * posicoes_ocupadas;
    int posicao_primeiro_elemento;
    int posicao_ultimo_elemento;
    Elemento ** elementos;
} Lista;

// escreve o elemento na posicao indicada
int escrever( lLista l, void * elemento, int posicao );

// procura o primeiro elemento vazio
int procurarVazio( lLista l );

// insere no inicio com a lista vazia
int inserirInicioVazio( lLista l, void * elemento );

// insere no inicio quando a lista tem elementos
int inserirInicioNaoVazio( lLista l, void * elemento );

// insere no fim com a lista vazia
int inserirFimVazio( lLista l, void * elemento );

// insere no fim quando a lista tem elementos
int inserirFimNaoVazio( lLista l, void * elemento );

// inserirNaPosicao insere o elemento na posicao indicada
// element -> ponteiro do elemento a ser inserido
// posicao -> posicao a inserir o elemento na lista
// retorna TRUE caso de certo e FALSE caso de errado
int inserirNaPosicao( lLista l, void * elemento, int posicao);

// removerPrimeiroElem logica remover o primeiro elemento quando a posicao a ser removida é a primeira posicao
// l -> lista de dados
// pos -> l->elementos[posicao]->posicao_proximo
void removerPrimeiroElem(lLista l, int pos);

// removerUltimoElem logica remover o ultimo elemento
// l -> lista de dados
// pos -> l->elementos[posicao]->posicao_anterior
void removerUltimoElem(lLista l, int pos);

// printa todo o elemento
void mostrarElemento( Elemento * el, int posicao , int posicaoOcupada);

// printa todos os elementos da lista
void printElementosLista(lLista l);

#endif