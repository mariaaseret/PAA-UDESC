#include "Lista_publica.h"

/***** Funções de manipulação da lista inteira *****/
/* Funções que se aplicam à lista toda, não somente a algum elemento */

// Pública
pLista criar_lista(int tamanho_maximo, int *resultado) {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) {
        *resultado = FRACASSO;
        return NULL;
    }
    lista->tamanho_maximo = tamanho_maximo;

    int i;
    NoLista *anterior = NULL;
    // Percorre os nós alocando-os e designando seu nó anterior
    for(i = 0; i<tamanho_maximo; i++) {
      NoLista *no_lista = (NoLista*)malloc(sizeof(NoLista));
      if (no_lista == NULL) {
          *resultado = FRACASSO;
          return NULL;
      }

      no_lista->ant = anterior;
      anterior = no_lista;

      // Atribui o primeiro nó da lista no descritor
      if (i==0) {
          lista->inicio = no_lista;
      }
      // Atribui o último nó da lista no descritor
      if (i==tamanho_maximo-1) {
          lista->fim = no_lista;
      }
    }

    NoLista *proximo = NULL;
    NoLista *no_lista = lista->fim;
    // Percorre (inversamente) os nós designando seu próximo nó
    do {
      no_lista->prox = proximo;
      proximo = no_lista;

      no_lista = no_lista->ant;
    } while (no_lista != NULL);

    *resultado = SUCESSO;
    return lista;
}

// Pública
void reiniciar_lista(pLista lista, int *resultado) {
  NoLista* no_lista = lista->inicio;
  while(no_lista != NULL) {
      // Desaloca o elemento
      remover(no_lista, resultado);

      if(*resultado == FRACASSO)
          return;

      no_lista = no_lista->prox;
  }
}

// Pública
void destruir_lista(pLista lista, int *resultado) {
  NoLista* no_lista = lista->inicio;
  while(no_lista != NULL) {
      // Desaloca o elemento
      remover(no_lista, resultado);

      if(*resultado == FRACASSO)
          return;

      no_lista = no_lista->prox;
      // Desaloca o nó (exceto o último)
      if(no_lista != NULL)
          free(no_lista->ant);
  }
  // Desaloca o úlitmo nó
  free(lista->fim);
  // Desaloca o descritor
  free(lista);
}

/***** Funções de acesso (privadas) *****/
/* Retornam a struct NoLista referente a uma certa posição */
/* Usado para evitar repetição de código entre buscar/inserir/remover */

// Privada
NoLista* no_inicio(pLista lista) {
    return lista->inicio;
}

// Privada
NoLista* no_fim(pLista lista) {
    return lista->fim;
}

// Privada
NoLista* no_pos(pLista lista, int pos, int* resultado) {
    if(pos >= lista->tamanho_maximo || pos < 0) {
        *resultado = FRACASSO;
        return NULL;
    }
    int i;
    NoLista* no_lista = lista->inicio;
    for(i=0; i<pos; i++) {
        no_lista = no_lista->prox;
    }
    return no_lista;
}

/***** Funções de busca *****/
/* Retornam o elemento em uma certa posição */
/* Usam as funções de acesso para obter o nó e retornam seu elemento */

// Pública
void* buscar_inicio(pLista lista, int* resultado) {
    *resultado = SUCESSO;
    return no_inicio(lista)->elemento;
}

// Pública
void* buscar_fim(pLista lista, int* resultado) {
    *resultado = SUCESSO;
    return no_fim(lista)->elemento;
}

// Pública
void* buscar_pos(pLista lista, int pos, int* resultado) {
    NoLista* no_lista = no_pos(lista, pos, resultado);
    if(*resultado == FRACASSO)
        return NULL;

    return no_lista->elemento;
}

/***** Funções de inserção *****/
/* Inserem um elemento (de tamanho/tipo qualquer) em uma certa posição */
/* Usam as funções de acesso para obter o nó e modificam seu elemento */
/* Todas modificam o elemento da mesma forma, usando a inserir() */
/* Se já houve um valor na posição, sobrescreve-o */

// Privada
void inserir(NoLista* no_lista, void* elemento, int tamanho_elemento, int* resultado) {
    no_lista->tamanho_elemento = tamanho_elemento;

    // Se já houver um elemento, desaloca-o
    // Importante porque sobreescreveremos o ponteiro e esse endereço será esquecido
    if(no_lista->elemento != NULL) {
        free(no_lista->elemento);
    }

    no_lista->elemento = malloc(tamanho_elemento);
    if(no_lista->elemento == NULL){
        *resultado = FRACASSO;
        return;
    }
    memcpy(no_lista->elemento, elemento, tamanho_elemento);
}

// Pública
void inserir_inicio(pLista lista, void* elemento, int tamanho_elemento, int* resultado) {
    NoLista* no_lista = no_inicio(lista);

    inserir(no_lista, elemento, tamanho_elemento, resultado);
}

// Pública
void inserir_fim(pLista lista, void* elemento, int tamanho_elemento, int* resultado) {
    NoLista* no_lista = no_fim(lista);

    inserir(no_lista, elemento, tamanho_elemento, resultado);
}

// Pública
void inserir_pos(pLista lista, int pos, void* elemento, int tamanho_elemento, int* resultado) {
    NoLista* no_lista = no_pos(lista, pos, resultado);

    if(*resultado == FRACASSO) {
        return;
    }

    inserir(no_lista, elemento, tamanho_elemento, resultado);
}

/***** Funções de remoção *****/
/* Removem um elemento em uma certa posição */
/* Como é estática, o nó continua alocado */
/* Usam as funções de acesso para obter o nó e removem seu elemento */
/* Todas removem o elemento da mesma forma, usando a remover() */

// Privada
void remover(NoLista* no_lista, int* resultado) {
    no_lista->tamanho_elemento = 0;
    free(no_lista->elemento);
    no_lista->elemento = NULL;

    *resultado = SUCESSO;
}

// Pública
void remover_inicio(pLista lista, int* resultado) {
    NoLista* no_lista = no_inicio(lista);

    remover(no_lista, resultado);
}

// Pública
void remover_fim(pLista lista, int* resultado) {
    NoLista* no_lista = no_fim(lista);

    remover(no_lista, resultado);
}

// Pública
void remover_pos(pLista lista, int pos, int* resultado) {
    NoLista* no_lista = no_pos(lista, pos, resultado);

    if(*resultado == FRACASSO) {
        return;
    }

    remover(no_lista, resultado);
}
