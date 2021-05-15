#ifndef LISTA_PUBLICA_H
#define LISTA_PUBLICA_H

typedef struct Lista *lLista;

// criarLista Cria a lista com o tamanho estático de um tamanho de dados específico
// tamanho -> tamanho estático e máximo da lista
// tamanho_elemento -> tamanho do dado a ser armazenado ex.: sizeof(int)
lLista criarLista(int tamanho, int tamanho_elemento);

// destruirLista destroi a lista liberando da memória os dados
// l -> lista de dados
int destruirLista(lLista l);

// reiniciarLista reinicia a lista, liberando os elementos da memória e reiniciando os valores da lista
// l -> lista de dados
int reiniciarLista(lLista l);

// inserirInicio insere o elemento no inicio da lista
// l -> lista de dados
// element -> ponteiro do elemento a ser inserido
// retorna TRUE caso de certo e FALSE caso de errado
int inserirInicio(lLista l, void *elemento);

// inserirFim insere o elemento no fim da lista
// l -> lista de dados
// element -> ponteiro do elemento a ser inserido
// retorna TRUE caso de certo e FALSE caso de errado
int inserirFim(lLista l, void *elemento);

// inserirPos insere o elemento na posicao indicada
// caso a posicao informada seja 0, insere no inicio
// caso a posicao informada seja l->tamanho_atual - 1, insere no fim
// caso a posicao a ser inserida não exista na lista retorna FALSE
// caso a posicao ainda não tenha sido preenchida, retorna FALSE
// l -> lista de dados
// element -> ponteiro do elemento a ser inserido
// posicao -> posicao a inserir o elemento na lista
// retorna TRUE caso de certo e FALSE caso de errado
int inserirPos(lLista l, void *elemento, int posicao);

// removerInicio remove o elemento do início da lista
// l -> lista de dados
// retorna o dado do início da lista ou NULL caso não tenha elementos na lista
void *removerInicio(lLista l);

// removerFim remove o elemento do fim da lista
// l -> lista de dados
// retorna o dado do fim da lista ou NULL caso não tenha elementos na lista
void *removerFim(lLista l);

// removerPos remove o elemento da posicao indicada
// l -> lista de dados
// posicao -> posicao da lista a ser removida
// retorna o dado do fim da lista ou NULL caso a posicao não exista
void *removerPos(lLista l, int posicao);

// buscarInicio retorna o elemento do início da lista
// l -> lista de dados
// retorna o dado do início da lista ou NULL caso não tenha elementos na lista
void *buscarInicio(lLista l);

// buscarFim retorna o elemento do fim da lista
// l -> lista de dados
// retorna o dado do fim da lista ou NULL caso não tenha elementos na lista
void *buscarFim(lLista l);

// buscarPos retorna o elemento da posicao indicada da lista
// l -> lista de dados
// posicao -> posicao da lista a ser removida
// retorna o dado de acordo com a posicao informada da lista ou NULL caso não tenha a posicao indicada
void *buscarPos(lLista l, int posicao);

// mostrarListaInt
// l -> lista de dados
// printa a lista para o tipo inteiro
void mostrarListaInt(lLista l);

#endif