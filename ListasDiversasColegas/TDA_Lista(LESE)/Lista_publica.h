#ifndef __FILA_PUBLICA_H__
#define __FILA_PUBLICA_H__

typedef struct Lista lista_t;
typedef struct NoLista no_t;

// Funcoes para adicionar elementos a Lista
void InserirInicio (struct Lista * lista, void * elemento, int * resultado);
void InserirFim (struct Lista * lista, void * elemento, int * resultado);
void InserirPos (struct Lista * lista, void * elemento, int Pos, int * resultado);

// Funcoes para remover elementos da Lista
void * RemoverInicio(struct Lista * lista, int * resultado);
void * RemoverFim(struct Lista * lista, int * resultado);
void * RemoverPos(struct Lista * lista, int Pos, int * resultado);

// Funcoes que consultam elementos da Lista, sem modifica-la
void * BuscarInicio(struct Lista * lista, int * resultado);
void * BuscarFim(struct Lista * lista, int * resultado);
void * BuscarPos(struct Lista * lista, int Pos, int * resultado);

// Funcoes para criacao, reinicializacao e destruicao da Lista
//struct Lista * CriarLista (int tamanho_dados, int * resultado);
struct Lista * CriarLista (int tamanho_dados, int tamanho_maximo, int * resultado);
struct Lista * ReiniciarLista (struct Lista * lista, int * resultado);
void DestruirLista (struct Lista * lista, int * resultado);

#endif /* __LISTA_PUBLICA_H__ */
