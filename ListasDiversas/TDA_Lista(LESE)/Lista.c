#include <stdio.h>
#include <stdlib.h>
#include "Lista_privado.h"

int i = 0;

// FUNCOES PARA ADICIONAR ELEMENTOS A LISTA
// Insere elemento no inicio da lista
void InserirInicio (struct Lista * lista, void * elemento, int * resultado)
{
    *resultado = FRACASSO;   // Inicializa o resultado como FRACASSO

    // Caso a lista esteja vazia. Nao deve ocorrer porque na criacao
    // ja inicializa pelo menos o tamanho dos dados
    if (lista == NULL){ return; }
    if (lista->tamanho_atual >= lista->tamanho_max) {
        printf("Lista cheia\n");
        return;
    }

    // Cria um no temporatio
    no_t *novo_no = (no_t*) malloc(sizeof(no_t));
    novo_no->dados = malloc(lista->tamanho_dados);

    // Caso haja erro no malloc
    if (novo_no == NULL){ return; }

    // Inicializa o no temporario com os dados fornecidos
    novo_no->dados = elemento;
    novo_no->prox = NULL;       // Como esse e o fim da lista, o prox = NULL

    // Apos a criacao do no temporario, adiciona ele ao fim da lista
    if (lista->inicio == NULL){                 // Se a lista esta vazia, deve ser inicializada
        lista->inicio = lista->fim = novo_no;   // Faz o entrelacamento entre inicio e fim da lista e adiciona o no temporario
        lista->inicio->prox = lista->fim;       // Faz o entrelacamento entre os nos  // novo_no->prox = novo_no;
        lista->fim->prox = NULL;                // Garante que o fim da lista acaba no fim
        lista->tamanho_atual = lista->tamanho_atual + 1;
        *resultado = SUCESSO;
        return;
    } else {
        no_t * primeiro_no = lista->inicio; // no temporario com o primeiro elemento
        novo_no->prox = primeiro_no;        // coloca o inicio atual da lista no prox do novo no
        lista->inicio = novo_no;            // aponta o inicio da lista para o novo no
        lista->tamanho_atual = lista->tamanho_atual + 1;
        *resultado = SUCESSO;
        return;
    } 

    // Se esse ponto foi atingido, resultado continua = FRACASSO.
    return;
}

void InserirFim (struct Lista * lista, void * elemento, int * resultado)
{
    *resultado = FRACASSO;   // Inicializa o resultado como FRACASSO

    // Caso a lista esteja vazia. Nao deve ocorrer porque na criacao
    // ja inicializa pelo menos o tamanho dos dados
    if (lista == NULL){ return; }
    if (lista->tamanho_atual >= lista->tamanho_max) {
        printf("Lista cheia\n");
        return;
    }

    // Cria um no temporatio
    no_t *novo_no = (no_t*) malloc(sizeof(no_t));
    novo_no->dados = malloc(lista->tamanho_dados);

    // Caso haja erro no malloc
    if (novo_no == NULL){ return; }

    // Inicializa o no temporario com os dados fornecidos
    novo_no->dados = elemento;
    novo_no->prox = NULL;       // Como esse e o fim da lista, o prox = NULL

    // Apos a criacao do no temporario, adiciona ele ao fim da lista
    if (lista->fim == NULL){                    // Se a lista esta vazia, deve ser inicializada
        lista->inicio = lista->fim = novo_no;   // Faz o entrelacamento entre inicio e fim da lista e adiciona o no temporario
        lista->inicio->prox = lista->fim;       // Faz o entrelacamento entre os nos   // novo_no->prox = novo_no;
        lista->fim->prox = NULL;                // Garante que o fim da lista acaba no fim
        lista->tamanho_atual = lista->tamanho_atual + 1;
        *resultado = SUCESSO;
        return;
    } else {
        no_t * ultimo_no = lista->fim;  // no temporario com o ultimo elemento
        ultimo_no->prox = novo_no;      // coloca o prox elemento como o novo no temporario
        lista->fim = novo_no;           // aponta o fim da lista para o novo no temporario
        lista->tamanho_atual = lista->tamanho_atual + 1;
        *resultado = SUCESSO;
        return;
    } 

    // Se esse ponto foi atingido, resultado continua = FRACASSO.
    return;
}

void InserirPos (struct Lista * lista, void * elemento, int Pos, int * resultado)
{
    
    *resultado = FRACASSO;   // Inicializa o resultado como FRACASSO
    void * Dado;

    // Caso a lista esteja vazia. Nao deve ocorrer porque na criacao
    // ja inicializa pelo menos o tamanho dos dados
    if (lista == NULL){ return; }
    else if (lista->inicio == NULL) {  return;  }  // Se a lista esta vazia
    if (lista->tamanho_atual >= lista->tamanho_max) {
        printf("Lista cheia\n");
        return;
    }
    if (Pos >= lista->tamanho_max) {
        printf("A posicao desejada é maior que a capacidade da lista\n");
        return;
    }

    // Se esse ponto foi atingido, a lista nao esta vazia
    no_t * novo_no = lista->inicio;  // Inicializa o novo_no como o inicio da lista
    no_t * no_atual = lista->inicio; // Inicializa o no_atual como o inicio da lista

    // Verifica se a posicao selecionada para insercao foi o inicio
    if (Pos == 0){
        novo_no->dados = elemento;         // Armazena o dado atual
        novo_no->prox = lista->inicio;     // Desloca um no na lista
        lista->inicio = novo_no;           // Coloca o novo_no na lista
        lista->tamanho_atual = lista->tamanho_atual + 1;
        *resultado = SUCESSO;
        return;
    } else {
        // Procura pela posicao desejada, a partir da 1a.
        for (i=0; i<Pos; i++){
            if (no_atual->prox != 0){
                novo_no = no_atual;  
                no_atual = novo_no->prox;     //Desloca um no na lista
            } else { // Se a posicao desejada e maior que numero de elementos na lista, adiciona ao fim da lista
                novo_no->dados = elemento;    // Adiciona o dado ao novo_no
                novo_no->prox = NULL;         // Anula o proximo do novo_no

                // Como e o ultimo elemento, atualiza o fim da lista
                lista->fim = novo_no;

                *resultado = FRACASSO;
                return;
            }
        }

        // Apos encontrar a posicao desejada, retorna as informacoes
        novo_no = (no_t*) malloc(sizeof(no_t));
        novo_no->dados = elemento;
        novo_no->prox = no_atual;

        // Faz uma nova busca pela lista para atualizar os nos
        no_atual = lista->inicio;
        for (i=0; i<Pos; i++){
            if (no_atual->prox != novo_no->prox){
                no_atual = no_atual->prox;
            } else {break;}  // Se encontrado o no, sai do for
        }
        // Apos reencontrar o no, atualiza a lista
        no_atual->prox = novo_no;  //no_atual = novo_no;  //Nao atualizou a lista
        lista->tamanho_atual = lista->tamanho_atual + 1;
        *resultado = SUCESSO;
        return;
    }

    // Se foi atingido, nao foi feito nada
    *resultado = FRACASSO;
    return;
}

// FUNCOES PARA REMOVER ELEMENTOS DA LISTA
// Remove elemento do inicio da lista
void * RemoverInicio(struct Lista * lista, int * resultado)
{

    *resultado = FRACASSO;   // Inicializa o resultado como FRACASSO

    // Caso a lista esteja vazia. Nao deve ocorrer porque na criacao
    // ja inicializa pelo menos o tamanho dos dados
    if (lista == NULL){ return NULL; }
    else if (lista->inicio == NULL) {  return NULL;  }  // Se a lista esta vazia


    // Armazena a informacao do elemento a ser removido para retorna-la
    void * elem_removido;
    elem_removido = lista->inicio->dados;

    
    // Remove o ultimo elemento da lista
    no_t * segundo_no;
    segundo_no = lista->inicio;
    // Encontra o segundo elemento da lista para desloca-lo. 
    // Isso nao era necessario, mas e interessante para garantir
    while (lista->inicio->prox != segundo_no)  // Procura ate encontrar qual no aponta para o ultimo da lista
    {
        segundo_no = segundo_no->prox;    // Desloca um no na lista
    }
    // Verifica se foi encontrado
    if (lista->inicio->prox == segundo_no){
        lista->inicio = segundo_no;      // Iguala o inicio da lista ao segundo no

        // Verifica se a lista ficou vazia
        if (lista->inicio == 0){
            lista->inicio = NULL;       // Anula o primeiro elemento da lista
            lista->fim = NULL;          // Também anula o ultimo elemento da lista
        }
        lista->tamanho_atual = lista->tamanho_atual - 1;
        *resultado = SUCESSO;
        return elem_removido;
    }

    // Se foi atingido, nao encontramos penultimo_no->prox == fim
    return NULL;
}

void * RemoverFim(struct Lista * lista, int * resultado)
{
    *resultado = FRACASSO;   // Inicializa o resultado como FRACASSO

    // Caso a lista esteja vazia. Nao deve ocorrer porque na criacao
    // ja inicializa pelo menos o tamanho dos dados
    if (lista == NULL){ return NULL; }
    else if (lista->fim == NULL) {  return NULL;  }  // Se a lista esta vazia


    // Armazena a informacao do elemento a ser removido para retorna-la
    void * elem_removido;
    elem_removido = lista->fim->dados;

    
    // Remove o ultimo elemento da lista
    no_t * penultimo_no;
    penultimo_no = lista->inicio;
    // Encontra o penultimo elemento da lista
    if (penultimo_no->prox != 0){  // Procura somente se a lista tem mais que um elemento
        while (lista->fim != penultimo_no->prox)  // Procura ate encontrar qual no aponta para o ultimo da lista
        {
            penultimo_no = penultimo_no->prox;    // Desloca um no na lista
        }
    } else {  // A lista tem somente um elemento    
        lista->fim = NULL;          // Anula o ultimo elemento
        lista->inicio = NULL;       // Tambem anula o primeiro elemento da lista
        lista->tamanho_atual = lista->tamanho_atual - 1;
        *resultado = SUCESSO;
        return elem_removido;
    }
    // Verifica se foi encontrado
    if (penultimo_no->prox == lista->fim){
        lista->fim = penultimo_no;      // Iguala o fim da lista ao penultimo no
        lista->fim->prox = NULL;        // Garante que a lista acaba no fim
        lista->tamanho_atual = lista->tamanho_atual - 1;
        *resultado = SUCESSO;
        return elem_removido;
    }

    // Se foi atingido, nao encontramos penultimo_no->prox == fim
    return NULL;
}

void * RemoverPos(struct Lista * lista, int Pos, int * resultado)
{
    *resultado = FRACASSO;   // Inicializa o resultado como FRACASSO
    void * Dado;

    // Caso a lista esteja vazia. Nao deve ocorrer porque na criacao
    // ja inicializa pelo menos o tamanho dos dados
    if (lista == NULL){ return NULL; }
    else if (lista->inicio == NULL) {  return NULL;  }  // Se a lista esta vazia
    if (Pos >= lista->tamanho_max) {
        printf("A posicao desejada é maior que a capacidade da lista\n");
        return NULL;
    }
    // Se esse ponto foi atingido, a lista nao esta vazia
    no_t * no_atual = lista->inicio;  // Inicializa o no_atual como o inicio da lista

    // Verifica se a posicao selecionada para insercao foi o inicio
    if (Pos == 0){
        Dado = lista->inicio->dados;        // Armazena a informacao que esta no inicio para retorna-la
        no_atual = lista->inicio->prox;     // Armazena o prox no no_atual
        lista->inicio = no_atual;           // Remove o no de inicio da lista
        lista->tamanho_atual = lista->tamanho_atual - 1;
        *resultado = SUCESSO;
        return Dado;
    } else {
        // Procura pela posicao desejada, a partir da 1a.
        for (i=0; i<Pos; i++){
            if (no_atual->prox != 0){
                no_atual = no_atual->prox;  //Desloca um no na lista
            } else { // Se a posicao desejada e maior que numero de elementos na lista
                *resultado = FRACASSO;
                return NULL;
            }
        }
        // Apos encontrar a posicao desejada, retorna as informacoes
        Dado = no_atual->dados;
        *no_atual = *no_atual->prox;
        lista->tamanho_atual = lista->tamanho_atual - 1;
        *resultado = SUCESSO;
        return Dado;
    }
    
    // Se foi atingido, nao foi feito nada
    *resultado = FRACASSO;
    return NULL;
}

// FUNCOES PARA BUSCAR ELEMENTOS DA LISTA, SEM MODIFICA-LA
//Retorna a informacao armazenada no inicio da lista, sem modifica-la
void * BuscarInicio(struct Lista * lista, int * resultado)
{
    *resultado = FRACASSO;  // Inicializa resultado como FRACASSO
    void * Dado;
    
    // Caso a lista esteja vazia. Nao deve ocorrer porque sempre e criada
    // inicializando o tamanho dos dados
    if (lista == NULL) { return NULL; }
    

    // Se a lista esta vazia, nao faz nada
    if (lista->inicio == NULL){ return NULL; } 
    else {
        Dado = lista->inicio->dados; // Armazena a informacao que esta no fim da lista
        *resultado = SUCESSO;
        return Dado;
    }

    // Se atingido, retorna nulo tambem e resultado continua = FRACASSO
    return NULL;
}

// Retorna a informacao armazenada no ultimo elemento da lista, sem modifica-la
void * BuscarFim(struct Lista * lista, int * resultado)
{
    *resultado = FRACASSO;  // Inicializa resultado como FRACASSO
    void * Dado;
    
    // Caso a lista esteja vazia. Nao deve ocorrer porque sempre e criada
    // inicializando o tamanho dos dados
    if (lista == NULL) { return NULL; }
    

    // Se a lista esta vazia, nao faz nada
    if (lista->fim == NULL){ return NULL; } 
    else {
        Dado = lista->fim->dados; // Armazena a informacao que esta no fim da lista
        *resultado = SUCESSO;
        return Dado;
    }

    // Se atingido, retorna nulo tambem e resultado continua = FRACASSO
    return NULL;
}

void * BuscarPos(struct Lista * lista, int Pos, int * resultado)
{
    *resultado = FRACASSO;  // Inicializa o resultado como FRACASSO

    void * Dado;
    
    // Caso a lista esteja vazia. Nao deve ocorrer porque sempre e criada
    // inicializando o tamanho dos dados
    if (lista == NULL) { return NULL; }
    if (Pos >= lista->tamanho_max) {
        printf("A posicao desejada é maior que a capacidade da lista\n");
        return NULL;
    }

    // Se a lista esta vazia, nao faz nada
    if (lista->inicio == NULL){ return NULL; } 
    else {

        no_t * no_atual = lista->inicio;  // Inicializa o no_atual como inicio

        // Verifica se a posicao solicitada foi o inicio da lista
        if (Pos == 0){
            Dado = lista->inicio->dados;
            *resultado = SUCESSO;
            return Dado;
        }
        // Procura pela posicao desejada, a partir da 1a.
        for (i=0; i<Pos; i++){  
            if (no_atual->prox != 0){
                no_atual = no_atual->prox;  // Desloca um no na lista
            } else { // Se a posicao desejada e maior que numero de elementos na lista
                *resultado = FRACASSO;
                return NULL;
            }
        }
        // Apos encontrar a posicao, retorna o dado
        Dado = no_atual->dados;
        *resultado = SUCESSO;
        return Dado;

    }

    // Se esse ponto foi atingido, nada foi feito
    return NULL;
    
}

// FUNCOES PARA CRIACAO, REINICIALIZACAO E DESTRUICAO DA LISTA
// Cria a lista
struct Lista * CriarLista (int tamanho_dados, int tamanho_maximo, int * resultado)
{
    lista_t * lista;
    lista = (lista_t*) malloc(sizeof(lista_t));
    
    // Em caso de falha no malloc
    if (lista == NULL)
    {
        *resultado = FRACASSO;
        printf("\nFalha ao criar a lista\n");
        return lista;
    }

    // Se houve sucesso no malloc, armazena as outras informacoes da lista
    lista->tamanho_dados = tamanho_dados;
    lista->tamanho_max = tamanho_maximo;
    lista->tamanho_atual = 0;
    lista->inicio = NULL;   // Lista inicializada, mas vazia. Inicio = NULL
    lista->fim = NULL;      // Lista inicializada, mas vazia. Fim    = NULL

    *resultado = SUCESSO;
    printf("\nLista criada com sucesso\n\n");
    return lista;
}

// Reinicia a lista, destruindo e depois recriando.
struct Lista * ReiniciarLista (struct Lista * lista, int * resultado)
{
    int tamanho_dados = lista->tamanho_dados;
    int tamanho_max = lista->tamanho_max;
    // Para reiniciar a lista, destroi a lista atual e depois recria
    DestruirLista(lista, resultado);
    // Recria a lista
    if (*resultado == SUCESSO){
        lista = CriarLista(tamanho_dados, tamanho_max, resultado);
        return lista;
    } else {
        return lista;
    }

    printf("\nA lista foi reiniciada\n\n");
    return lista;
}

// Destroi a lista
void DestruirLista (struct Lista * lista, int * resultado)
{
	// Se a lista esta vazia. Nao deve ocorrer porque na criacao sempre
    // e inicializada pelo menos a informacao do tamanho.
    if (lista == NULL)
    {
        *resultado = FRACASSO;
        return;
    }

    // Enquanto houverem dados no inicio, remove um por um ate o fim da lista
	while(lista->inicio != NULL)
	{
        void * Dado;
		Dado = RemoverInicio(lista, resultado);
	}

    // Libera a memoria da lista
	free(lista);
    printf("\nA lista foi destruida\n\n");
    *resultado = SUCESSO;
}

