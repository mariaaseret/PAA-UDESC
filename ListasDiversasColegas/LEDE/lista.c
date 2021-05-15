#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_privada.h"

#define TRUE 0
#define FALSE 1
#define EMPTY -1

// criarLista Cria a lista com o tamanho estático de um tamanho de dados específico
// tamanho -> tamanho estático e máximo da lista
// tamanho_elemento -> tamanho do dado a ser armazenado ex.: sizeof(int)
lLista criarLista(int tamanho, int tamanho_elemento) {
  if (tamanho <= 0) {
    return NULL;
  }

  // aloca o tamanho da lista
  lLista ll = malloc(sizeof(Lista));
  ll->tamanho_total_lista = tamanho;
  ll->tamanho_elemento = tamanho_elemento;

  ll->tamanho_atual = 0;

  // aloca a lista de posicoes_ocupadas
  ll->posicoes_ocupadas = malloc(tamanho * sizeof(int));
  for (int i = 0; i < tamanho; i++) {
    ll->posicoes_ocupadas[i] = FALSE;
  }

  ll->posicao_primeiro_elemento = EMPTY;
  ll->posicao_ultimo_elemento = EMPTY;

  // aloca os elementos
  ll->elementos = malloc(tamanho * sizeof(Elemento));

  return ll;
}

// destruirLista destroi a lista liberando da memória os dados
// l -> lista de dados
int destruirLista(lLista l) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return FALSE;
  }

  // libera os elementos e posicoes_ocupadas da lista
  for (int i = 0; i < l->tamanho_total_lista; i++) {
    if (l->posicoes_ocupadas[i] == TRUE) {
      free(l->elementos[i]->dado);
      free(l->elementos[i]);
    }
  }

  // libera a lista da memoria
  free(l->elementos);
  free(l->posicoes_ocupadas);
  free(l);

  return TRUE;
}

// reiniciarLista reinicia a lista, liberando os elementos da memória e reiniciando os valores da lista
// l -> lista de dados
int reiniciarLista(lLista l) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return FALSE;
  }

  // libera os elementos da lista
  for (int i = 0; i < l->tamanho_total_lista; i++) {
    if (l->posicoes_ocupadas[i] == TRUE) {
      free(l->elementos[i]->dado);
      free(l->elementos[i]);
    }
    l->posicoes_ocupadas[i] = FALSE;
  }

  // reinicia os valores da lista
  l->tamanho_atual = 0;
  l->posicao_primeiro_elemento = EMPTY;
  l->posicao_ultimo_elemento = EMPTY;

  return TRUE;
}

// escreve o elemento na posicao indicada
int escrever(lLista l, void *elemento, int posicao) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return FALSE;
  }

  // verifica se deve escrever
  if (posicao < 0 || posicao > l->tamanho_total_lista) {
    return FALSE;
  }

  // adiciona um ao tamanho atual
  l->tamanho_atual++;
  // seta a posicao ocupada como 1
  l->posicoes_ocupadas[posicao] = TRUE;

  // copia o elemento para dentro da lista
  l->elementos[posicao] = (Elemento *)malloc(sizeof(struct Elemento));
  l->elementos[posicao]->dado = malloc(l->tamanho_elemento);
  memcpy(l->elementos[posicao]->dado, elemento, l->tamanho_elemento);

  return TRUE;
}

// procurarVazio retorna o primeiro elemento vazio na lista
int procurarVazio(lLista l) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return FALSE;
  }

  // procura a primeira posicao vazia na lista
  for (int i = 0; i < l->tamanho_total_lista; i++) {
    if (l->posicoes_ocupadas[i] == FALSE) {
      return i;
    }
  }

  return EMPTY;
}

// insere no inicio com a lista vazia
int inserirInicioVazio(lLista l, void *elemento) {
  escrever(l, elemento, 0);
  l->posicao_primeiro_elemento = 0;
  l->posicao_ultimo_elemento = 0;
  l->elementos[0]->posicao_anterior = EMPTY;
  l->elementos[0]->posicao_proximo = EMPTY;

  return TRUE;
}

// insere no inicio com a lista vazia
int inserirInicioNaoVazio(lLista l, void *elemento) {
  int pos = procurarVazio(l);
  if (pos == EMPTY) return FALSE;

  escrever(l, elemento, pos);

  l->elementos[l->posicao_primeiro_elemento]->posicao_anterior = pos;

  l->elementos[pos]->posicao_anterior = l->posicao_ultimo_elemento;
  l->elementos[pos]->posicao_proximo = l->posicao_primeiro_elemento;

  if (l->posicoes_ocupadas[l->posicao_ultimo_elemento] == TRUE) {
    l->elementos[l->posicao_ultimo_elemento]->posicao_proximo = pos;
  }

  l->posicao_primeiro_elemento = pos;

  return TRUE;
}

// inserirInicio insere o elemento no inicio da lista
// l -> lista de dados
// element -> ponteiro do elemento a ser inserido
// retorna TRUE caso de certo e FALSE caso de errado
int inserirInicio(lLista l, void *elemento) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return FALSE;
  }

  if (l->posicao_primeiro_elemento == EMPTY) {
    return inserirInicioVazio(l, elemento);
  }
  return inserirInicioNaoVazio(l, elemento);
}

// insere no fim com a lista vazia
int inserirFimVazio(lLista l, void *elemento) {
  return inserirInicioVazio(l, elemento);
  // Se você parar para pensar, a lógica é a mesma
}

// insere no fim quando a lista tem elementos
int inserirFimNaoVazio(lLista l, void *elemento) {
  // verifica se deve inserir
  if (l->tamanho_atual >= l->tamanho_total_lista) {
    return FALSE;
  }
  int pos = procurarVazio(l);
  if (pos == EMPTY) return FALSE;

  // escreve o elemento na lista
  escrever(l, elemento, pos);

  // modifica os primeiros e proximos
  l->elementos[l->posicao_ultimo_elemento]->posicao_proximo = pos;

  l->elementos[pos]->posicao_anterior = l->posicao_ultimo_elemento;
  l->elementos[pos]->posicao_proximo = l->posicao_primeiro_elemento;
  l->posicao_ultimo_elemento = pos;

  if (l->posicoes_ocupadas[l->posicao_primeiro_elemento] == TRUE) {
    l->elementos[l->posicao_primeiro_elemento]->posicao_anterior = pos;
  }
  return TRUE;
}

// inserirFim insere o elemento no fim da lista
// l -> lista de dados
// element -> ponteiro do elemento a ser inserido
// retorna TRUE caso de certo e FALSE caso de errado
int inserirFim(lLista l, void *elemento) {
  if (l->posicao_ultimo_elemento == EMPTY) {
    return inserirFimVazio(l, elemento);
  }
  return inserirFimNaoVazio(l, elemento);
}

// inserirNaPosicao insere o elemento na posicao indicada
// element -> ponteiro do elemento a ser inserido
// posicao -> posicao a inserir o elemento na lista
// retorna TRUE caso de certo e FALSE caso de errado
int inserirNaPosicao(lLista l, void *elemento, int posicao) {
  int pos = procurarVazio(l);
  if (pos == EMPTY) return FALSE;  // verifica se tem lugar para adicionar

  escrever(l, elemento, pos);

  int cont = 0;
  Elemento *el = l->elementos[l->posicao_primeiro_elemento];
  int p = l->posicao_primeiro_elemento;
  while (cont != posicao) {
    p = el->posicao_proximo;
    el = l->elementos[el->posicao_proximo];
    cont++;
  }
  l->elementos[pos]->posicao_anterior = el->posicao_anterior;
  l->elementos[pos]->posicao_proximo = p;
  l->elementos[l->elementos[p]->posicao_anterior]->posicao_proximo = pos;
  l->elementos[p]->posicao_anterior = pos;
  return TRUE;
}

// inserirPos insere o elemento na posicao indicada
// caso a posicao informada seja 0, insere no inicio
// caso a posicao informada seja l->tamanho_atual - 1, insere no fim
// caso a posicao a ser inserida não exista na lista retorna FALSE
// caso a posicao ainda não tenha sido preenchida, retorna FALSE
// l -> lista de dados
// element -> ponteiro do elemento a ser inserido
// posicao -> posicao a inserir o elemento na lista
// retorna TRUE caso de certo e FALSE caso de errado
int inserirPos(lLista l, void *elemento, int posicao) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return FALSE;
  }

  if (posicao < 0 || posicao >= l->tamanho_atual) {
    return FALSE;
  } else if (posicao == 0) {
    return inserirInicio(l, elemento);
  } else if (posicao == l->tamanho_atual - 1) {
    return inserirFim(l, elemento);
  }
  return inserirNaPosicao(l, elemento, posicao);
}

// removerInicio retorna Null caso a lista esteja vazia ou retorna o elemento removido
void *removerInicio(lLista l) {
  return removerPos(l, l->posicao_primeiro_elemento);
}

// removerPrimeiroElem logica remover o primeiro elemento quando a posicao a ser removida é a primeira posicao
// l -> lista de dados
// pos -> l->elementos[posicao]->posicao_proximo
void removerPrimeiroElem(lLista l, int pos) {
  if (l->posicoes_ocupadas[pos] == TRUE) {
    l->elementos[pos]->posicao_anterior = l->posicao_ultimo_elemento;
  }

  if (l->posicao_ultimo_elemento != EMPTY && l->posicoes_ocupadas[l->posicao_ultimo_elemento] == TRUE) {
    l->elementos[l->posicao_ultimo_elemento]->posicao_proximo = pos;
  }

  l->posicao_primeiro_elemento = pos;
}

// removerUltimoElem logica remover o ultimo elemento
// l -> lista de dados
// pos -> l->elementos[posicao]->posicao_anterior
void removerUltimoElem(lLista l, int pos) {
  if (l->posicoes_ocupadas[pos] == TRUE) {
    l->elementos[pos]->posicao_proximo = l->posicao_primeiro_elemento;
  }

  if (l->posicao_primeiro_elemento != EMPTY && l->posicoes_ocupadas[l->posicao_primeiro_elemento] == TRUE) {
    l->elementos[l->posicao_primeiro_elemento]->posicao_anterior = pos;
  }

  l->posicao_ultimo_elemento = pos;
}

// removerPos remove o elemento da posicao indicada
// l -> lista de dados
// posicao -> posicao da lista a ser removida
// retorna o dado do fim da lista ou NULL caso a posicao não exista
void *removerPos(lLista l, int posicao) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return NULL;
  }

  if (l->tamanho_atual <= 0) {  // lista esta vazia
    return NULL;
  }

  if (posicao >= l->tamanho_total_lista) {  // posicao to remove maior que tamanho total lista
    return NULL;
  }

  if (l->posicoes_ocupadas[posicao] == FALSE) {
    // posicao ja esta desocupada
    return NULL;
  }

  Elemento *el = l->elementos[posicao];     // elemento na posicao
  int pos_proximo = el->posicao_proximo;    // armazena a posicao do proximo
  int pos_anterior = el->posicao_anterior;  // armazena a posicao do anterior

  // desocupa posicao
  l->posicoes_ocupadas[posicao] = FALSE;

  // copia o dado retorno
  void *dado = malloc(l->tamanho_elemento);
  memcpy(dado, el->dado, l->tamanho_elemento);

  // limpa o elemento na posicao
  free(l->elementos[posicao]->dado);
  free(l->elementos[posicao]);

  l->tamanho_atual--;

  // caso a lista fique vazia é só retornar o valor
  if (l->tamanho_atual == 0) {
    printf("\nREMOVE POS - lista vazia\n");
    l->posicao_primeiro_elemento = EMPTY;
    l->posicao_ultimo_elemento = EMPTY;
    return dado;
  }

  // esta removendo na primeira posicao
  if (l->posicao_primeiro_elemento == posicao) {
    printf("\n REMOVE PRIMEIRA POSICAO %d\n", posicao);
    removerPrimeiroElem(l, pos_proximo);
    return dado;
  }

  // esta removendo na ultima posicao
  if (l->posicao_ultimo_elemento == posicao) {
    printf("\n REMOVE ULTIMA POSICAO %d\n", posicao);
    removerUltimoElem(l, pos_anterior);
    return dado;
  }

  // caso a lista tenha mais valores, deve zerar a posicao anterior do primeiro elemento
  if (l->posicoes_ocupadas[pos_proximo] == TRUE) {
    l->elementos[pos_proximo]->posicao_anterior = pos_anterior;
  }
  if (l->posicoes_ocupadas[pos_anterior] == TRUE) {
    l->elementos[pos_anterior]->posicao_proximo = pos_proximo;
  }

  return dado;
}

// removerFim remove o elemento do fim da lista
// l -> lista de dados
// retorna o dado do fim da lista ou NULL caso não tenha elementos na lista
void *removerFim(lLista l) {
  return removerPos(l, l->posicao_ultimo_elemento);
}

// buscarInicio retorna o elemento do início da lista
// l -> lista de dados
// retorna o dado do início da lista ou NULL caso não tenha elementos na lista
void *buscarInicio(lLista l) {
  return buscarPos(l, l->posicao_primeiro_elemento);
}

// buscarFim retorna o elemento do fim da lista
// l -> lista de dados
// retorna o dado do fim da lista ou NULL caso não tenha elementos na lista
void *buscarFim(lLista l) {
  return buscarPos(l, l->posicao_ultimo_elemento);
}

// buscarPos retorna o elemento da posicao indicada da lista
// l -> lista de dados
// posicao -> posicao da lista a ser removida
// retorna o dado de acordo com a posicao informada da lista ou NULL caso não tenha a posicao indicada
void *buscarPos(lLista l, int posicao) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return NULL;
  }

  if (l->tamanho_atual <= 0) {  // lista esta vazia
    return NULL;
  }

  if (posicao >= l->tamanho_total_lista) {  // posicao maior que tamanho total lista
    return NULL;
  }

  if (l->posicoes_ocupadas[posicao] == FALSE) {
    // posicao vazia
    return NULL;
  }

  // busca o elemento para copiar o dado
  Elemento *el = l->elementos[posicao];
  void *dado = malloc(l->tamanho_elemento);
  memcpy(dado, el->dado, l->tamanho_elemento);

  return dado;
}

// mostrarListaInt printa a lista para o tipo inteiro
// l -> lista de dados
void mostrarListaInt(lLista l) {
  // verifica se a lista ja não esta vazia
  if (l == NULL || !l || l->tamanho_total_lista <= 0) {
    return;
  }

  printf("TAMANHO_TOTAL_LISTA: %d\n", l->tamanho_total_lista);
  printf("TAMANHO_ELEMENTO: %d\n", l->tamanho_elemento);
  printf("TAMANHO_ATUAL: %d\n", l->tamanho_atual);

  printf("POSICOES_OCUPADAS: ");
  // printa todas as posicoes ocupadas
  for (int i = 0; i < l->tamanho_total_lista; i++) {
    printf("%d, ", l->posicoes_ocupadas[i]);
  }

  printf("\n");
  printf("POSICAO_PRIMEIRO_ELEMENTO: %d\n", l->posicao_primeiro_elemento);
  printf("POSICAO_ULTIMO_ELEMENTO: %d\n", l->posicao_ultimo_elemento);
  if (l->tamanho_atual <= 0) {
    printf("\n\n");
    return;
  }
  printf("ELEMENTOS NA LISTA:\n");
  for (int i = 0; i < l->tamanho_total_lista; i++) {
    mostrarElemento(l->elementos[i], i, l->posicoes_ocupadas[i]);
  }
  printf("POSICOES EM ORDEM: ");
  int a = l->posicao_primeiro_elemento;
  Elemento *el = l->elementos[l->posicao_primeiro_elemento];
  while (el != 0 && el->posicao_proximo != l->posicao_primeiro_elemento) {
    printf("%d, ", a);
    if (el->posicao_proximo == EMPTY || el->posicao_proximo == l->posicao_primeiro_elemento) {
      break;
    }

    a = el->posicao_proximo;
    el = l->elementos[el->posicao_proximo];
  }
  printf("\n");
  printf("ELEMENTOS EM ORDEM: ");
  int *d = 0;
  el = l->elementos[l->posicao_primeiro_elemento];
  while (el != 0) {
    d = el->dado;
    printf("%d, ", *d);
    if (el->posicao_proximo == EMPTY || el->posicao_proximo == l->posicao_primeiro_elemento) break;
    el = l->elementos[el->posicao_proximo];
  }
  printf("\n");
  // Ajuda a depurar ;)
  printf("ELEMENTOS EM ORDEM CONTRÁRIA: ");
  d = 0;
  el = l->elementos[l->posicao_ultimo_elemento];
  while (el != 0) {
    d = el->dado;
    printf("%d, ", *d);
    if (el->posicao_anterior == EMPTY || el->posicao_anterior == l->posicao_ultimo_elemento) break;
    el = l->elementos[el->posicao_anterior];
  }
  printf("\n\n\n");
}

// printa todo o elemento
// el -> elemento a ser printado
// posicao -> posicao para printar
// posicaoOcupada -> inidica se a posicao esta ocupada ou não
void mostrarElemento(Elemento *el, int posicao, int posicaoOcupada) {
  printf("%d:", posicao);
  if (el == 0 || posicaoOcupada == FALSE) {
    printf("Vazio\n");
    return;
  }
  int *d = el->dado;
  printf("\tDADO: %d\n", *d);
  printf("\tPOSICAO_ANTERIOR: %d\n", el->posicao_anterior);
  printf("\tPOSICAO_PROXIMO: %d\n", el->posicao_proximo);
}

// printElementosLista printa toda a lista mostrando todos os elementos
// l -> lista de dados
void printElementosLista(lLista l) {
  printf("ELEMENTOS NA LISTA:\n");
  for (int i = 0; i < l->tamanho_total_lista; i++) {
    mostrarElemento(l->elementos[i], i, l->posicoes_ocupadas[i]);
  }
}