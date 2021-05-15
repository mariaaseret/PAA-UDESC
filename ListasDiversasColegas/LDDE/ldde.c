#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ldde_privada.h"

int CriarLista(pldde *lista, int tamanho_dados){

    /* Aloca o espaço e verifica o sucesso */
    pldde tmp_lista = (pldde) malloc(sizeof(ldde));
    if(tmp_lista == NULL){
        printf("Erro: Alocação de memória para criação da lista falhou!\n");
        return ERRO;
    }

    /* Inicializa os ponteiros da lista */
    tmp_lista->tamanho_dados = tamanho_dados;
    tmp_lista->inicio = tmp_lista->fim = NULL;
    tmp_lista->quantidade_nos = 0;

    /* Atualiza o ponteiro externo */
    *lista = tmp_lista;
    return SUCESSO;
}

int ReiniciarLista(pldde lista){
    /* Caso a lista não exista, informa o erro */
    if(lista == NULL){
        printf("Erro: Ponteiro para lista nulo, lista já destruída ou não iniciada!\n");
        return ERRO;
    }
    
    /* Percorre a lista removendo os nós */
    noLdde * no = NULL; 
    while(lista->inicio != NULL){
        no = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(no->dados);
        free(no);
    }
    return SUCESSO;
}

int DestruirLista(pldde *lista){
    /* Chama a Reinicialização da lista para limpar todos os nós */
    if(ReiniciarLista(*lista) == ERRO)
        return ERRO;

    /* Destói o descritor da lista */
    free(*lista);
    *lista = NULL;
    return SUCESSO; 
}

/* Função wrapper para inserção no início utilizando a InserirPos */
int InserirInicio(pldde lista, void * elemento){
    return InserirPos(lista, elemento, 0);
}

/* Função wrapper para inserção no final utilizando a InserirPos */
int InserirFim(pldde lista, void * elemento){
    return InserirPos(lista, elemento, lista->quantidade_nos);
}

int InserirPos(pldde lista, void * elemento, int posicao){
    int i = 0;
    noLdde * atual = NULL;
    
    /* Se a posição informada for maior que a quantidade de nós, retorna erro */
    if(posicao > lista->quantidade_nos){
        printf("Erro: Posição inexistente!\n");
        return ERRO;
    }

    /* Aloca o espaço para o novo nó e verifica sucesso */
    noLdde * novo_no = (noLdde *) malloc(sizeof(noLdde));
    if(novo_no == NULL){
        printf("Erro: Alocação de memória para criação de nó falhou!\n");
        return ERRO;
    }

    /* Inicializa os ponteiros do novo nó */
    novo_no->prox = novo_no->ant = NULL;

    /* Aloca o espaço para os dados e verifica sucesso */ 
    novo_no->dados = (void *) malloc(lista->tamanho_dados);
    if(novo_no->dados == NULL){
        printf("Erro: Alocação de memória para o dado falhou!\n");
        return ERRO;
    }

    /* Copia o novo elemento para o nó */
    memcpy(novo_no->dados, elemento, lista->tamanho_dados);

    /* Percorre a lista para encontrar o elemento na posição especificada */
    atual = lista->inicio; 
    for(i = 0; i < posicao; i++)
        atual = atual->prox;

    /* Caso o valor do nó seja nulo, então a inserção deve ser no final ou não há elementos na lista */
    if(atual == NULL){
        /* Atualiza os ponteiros de acordo com o caso específico */
        if(posicao == 0){
            lista->inicio = lista->fim = novo_no;
        }else{
            novo_no->ant = lista->fim;
            lista->fim->prox = novo_no;
            lista->fim = novo_no;
        }
        lista->quantidade_nos++;
        return SUCESSO;
    }

    /* Atualiza os ponteiros caso a inserção seja de fato no meio da lista */
    novo_no->prox = atual;
    novo_no->ant = atual->ant;
    atual->ant = novo_no;

    /* Se o elemento foi inserido no início (para o caso em que já haviam elementos na lista), o */
    /* ponteiro da lista deve ser atualizado */
    if(posicao == 0)
        lista->inicio = novo_no;

    lista->quantidade_nos++;

    return SUCESSO; 
}

/* Função wrapper para buscar no início utilizando a BuscarPos */
void * BuscarInicio(pldde lista){
    return lista->inicio->dados;
}

/* Função wrapper para buscar no fim utilizando a BuscarPos */
void * BuscarFim(pldde lista){
    return lista->fim->dados;
}

void * BuscarPos(pldde lista, int posicao){
    int i = 0;
    noLdde * atual = NULL;

    /* Percorre a lista buscando pelo nó na posição informada */
    atual = lista->inicio; 
    for(i = 0; i < posicao && atual->prox != NULL; i++){
        atual = atual->prox;
    }

    /* Caso o nó seja nulo, então a posição informada não existe */
    if(atual == NULL){
        printf("Erro: Posição inexistente!\n");
        return NULL;
    }

    return atual->dados;
}

/* Função wrapper para remover do início utilizando a RemoverPos */
int RemoverInicio(pldde lista){
    return RemoverPos(lista, 0);
}

/* Função wrapper para remover do fim utilizando a RemoverPos */
int RemoverFim(pldde lista){
    return RemoverPos(lista, lista->quantidade_nos - 1);
}

int RemoverPos(pldde lista, int posicao){
    int i = 0;
    noLdde * atual = NULL;

    /* Caso a posição informada seja maior ou igual à quantidade de nós, retorna erro */
    if(posicao >= lista->quantidade_nos){
        printf("Erro: Posição inexistente!\n");
        return ERRO;
    }

    /* Percorre a lista procurando pelo elemento na posição informada */
    atual = lista->inicio; 
    for(i = 0; i < posicao; i++)
        atual = atual->prox;

    /* Atualiza os ponteiros de acordo com o caso específico (início, fim ou meio) */
    if(posicao == 0){
        lista->inicio = atual->prox;
        lista->inicio->ant = NULL;
    }else if(posicao == lista->quantidade_nos - 1){
        lista->fim = atual->ant;
        lista->fim->prox = NULL;
    }else{
        noLdde * aux = atual->prox;
        atual->ant->prox = aux;
        atual->prox->ant = atual->ant;
    }

    free(atual->dados);
    free(atual);
    
    lista->quantidade_nos--;
    return SUCESSO;
}
