#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_privado.h"

descritor *criarLista(int tamanho_dados, int *resultado)
{
    descritor *lista = (descritor *)malloc(sizeof(lista));
    if (!lista)
    {
        exit(1);
        printf("\nErro na alocação da lista!\n");
        *resultado = ERRO;
    }
    else
    {
        lista->inicio = NULL;
        lista->tamanho_dados = tamanho_dados;
        lista->qtdeNos = 0;
        *resultado = SUCESSO;

        printf("\nLista alocada com sucesso!\n\n");
        return lista;
    }
}

noLista *criarNo(descritor *lista, void *elemento)
{
    noLista *no = (noLista *)malloc(sizeof(noLista));
    no->dados = malloc(lista->tamanho_dados);

    no->dados = elemento;
    no->prox = NULL;

    return no;
}

void inserirInicio(pLista lista, void *elemento, void *valorInserido, int *resultado)
{
    //alocacao
    noLista *no = criarNo(lista, elemento);
    if (!no)
    {
        printf("\nErro na alocação do nó da lista!\n");
        *resultado = ERRO;
        exit(1);
    }
    else
    {
        if (listaVazia(lista)) // se a lista estiver vazia insere
            lista->inicio = no;
        else // se já existir elementos na lista
        {
            no->prox = lista->inicio; //novo nó recebe como próximo o primeiro elemento
            lista->inicio = no;       // novo nó ocupa agora a primeira posicao
        }

        lista->qtdeNos++;
        *resultado = SUCESSO;

        //retorna no parâmetro valor inserido
        memcpy(valorInserido, no->dados, lista->tamanho_dados);
        printf("\nElemento inserido no inicio da fila!\n");
    }
}

void inserirFim(pLista lista, void *elemento, void *valorInserido, int *resultado)
{
    //alocacao
    noLista *no = criarNo(lista, elemento);

    if (!no)
    {
        printf("\nErro na alocação do nó da lista!\n");
        *resultado = ERRO;
        exit(1);
    }
    else
    {
        if (listaVazia(lista))       
           
            inserirInicio(lista, elemento, valorInserido, resultado);       
        else
        {
            noLista *noUlt = (noLista *)malloc(sizeof(noLista));
            noUlt = lista->inicio;
            //busca pelo ultimo elemento
            while (noUlt->prox != NULL)
            {
                noUlt = noUlt->prox;
            }
            noUlt->prox = no;

            memcpy(valorInserido, no->dados, lista->tamanho_dados);
            printf("\nElemento inserido no fim da fila!\n");
             lista->qtdeNos++;
        }       
        *resultado = SUCESSO;
    }
}

void inserirPos(pLista lista, void *elemento, void *valorInserido, int pos, int *resultado)
{
    //alocacao
    noLista *no = criarNo(lista, elemento);
    if (!no)
    {
        printf("\nErro na alocação do nó da lista!\n");
        *resultado = ERRO;
        exit(1);
    }
    else
    {
        if (listaVazia(lista))         // se a lista está vazia insere na lista            
            inserirInicio(lista, elemento, valorInserido, resultado);           
        else
        {
            if (!validarPosicaoInformada(lista, pos))
            {
                printf("\nPosicao inexistente na lista!\n");
                *resultado = ERRO;
                 exit(1);
            }
            else
            {

                if (pos == 0) // inserir na primeira posicao
                    inserirInicio(lista, elemento, valorInserido, resultado);
                else if (pos == (lista->qtdeNos - 1)) // inserir na ultima posicao
                    inserirFim(lista, elemento, valorInserido, resultado);
                else
                {
                    noLista *noAnt = (noLista *)malloc(sizeof(noLista));
                    noLista *noAux = (noLista *)malloc(sizeof(noLista));             
                  
                    noAux = lista->inicio;
                    int cont = 0;
                    while (cont < pos - 1)
                    {
                        noAux = noAux->prox;
                        cont++;
                    }
                    // ao inserir na posicao desejada todos os elementos posteriores são empurrados para trás.

                    noAnt = noAux->prox; // pega o valor que estava na atual posicao
                    noAux->prox = no;    // substitui pelo o elemento inserido
                    no->prox = noAnt;    // atualiza o proximo com o elemento que ocupa a atual posicao

                    memcpy(valorInserido, no->dados, lista->tamanho_dados);
                    lista->qtdeNos++;
                    printf("\nElemento inserido na posicao %d\n", pos);
                }
                *resultado = SUCESSO;
            }            
        }
    }
}

void removerInicio(pLista lista, void *valorRemovido, int *resultado)
{
    noLista *noAux = malloc(sizeof(noLista));

    if (listaVazia(lista))
    {
        printf("\nLista vazia!\n");
        *resultado = ERRO;
    }
    else
    {
        noAux = lista->inicio;
        memcpy(valorRemovido, noAux->dados, lista->tamanho_dados);

        // se haver apenas um elemento este é "limpado"
        if (noAux->prox == NULL)
            lista->inicio = NULL;
        else
            lista->inicio = noAux->prox; // se houver mais de um elemento na lista, a segunda posicao passa a ser a primeira e assim consecutivamente.

        free(noAux);
        lista->qtdeNos--;
        *resultado = SUCESSO;
        printf("\nElemento do inicio da fila removido!\n");
    }
}

void removerFim(pLista lista, void *valorRemovido, int *resultado)
{

    if (listaVazia(lista))
    {
        printf("\nLista vazia!\n");
        *resultado = ERRO;
    }
    else
    {
        noLista *noAux = (noLista *)malloc(sizeof(noLista));
        noAux = lista->inicio;

        if (noAux->prox == NULL) // se houver apenas um elemento
        {
            lista->inicio = NULL;
            lista->qtdeNos = 0;
        }
        else
        {
            noLista *noAnt = (noLista *)malloc(sizeof(noLista));
            for (; noAux->prox != NULL; noAux = noAux->prox)
                noAnt = noAux;
            noAnt->prox = NULL; // apaga o ponteiro para o ultimo elemento
        }

        memcpy(valorRemovido, noAux->dados, lista->tamanho_dados);
        free(noAux); // remove ultimo

        lista->qtdeNos--;
        *resultado = SUCESSO;
        printf("\nElemento do fim da fila removido!\n");
    }
}

void removerPos(pLista lista, void *valorRemovido, int pos, int *resultado)
{
 
    if (listaVazia(lista))
    {
        printf("\nLista vazia!\n");
        *resultado = ERRO;
    }
    else
    {
        if (!validarPosicaoInformada(lista, pos))
        {
            printf("\nPosicao inexistente na lista!\n");
            *resultado = ERRO;
             exit(1);
        }
        else
        {
            if (pos == 0) // remover na primeira posicao
                removerInicio(lista, valorRemovido, resultado);
            else if (pos == (lista->qtdeNos - 1)) // remover na ultima posicao
                removerFim(lista, valorRemovido, resultado);
            else
            {
                noLista *noAtual = (noLista *)malloc(sizeof(noLista));
                noLista *noAnt = (noLista *)malloc(sizeof(noLista));

                // ao remover da posicao desejada todos os elementos posteriores são empurrados para frente.
                noAtual = buscarNo(lista, pos);
                noAnt = buscarNo(lista, pos - 1);

                noAnt->prox = noAtual->prox; // pega o valor de próximo da atual posicao

                memcpy(valorRemovido, noAtual->dados, lista->tamanho_dados);
                free(noAtual); // remove elemento da posicao passada

                lista->qtdeNos--;
                *resultado = SUCESSO;
                printf("\nElemento na posicao %d removido! \n", pos);
            }
        }
    }
}

int listaVazia(pLista lista)
{
    if (lista == NULL)
        return 1;
    if (lista->inicio == NULL)
        return 1;
    else
        return 0;
}

int listaCheia(pLista lista)
{
    noLista *no = malloc(sizeof(noLista));

    if (!no)
        return 1;
    else
        return 0;

    free(no);
}

void *buscarInicio(pLista lista, int *resultado)
{

    if (listaVazia(lista))
    {
        printf("\nLista vazia!\n");
        *resultado = ERRO;
        return NULL;
    }
    else
    {
        noLista *noAux = malloc(sizeof(noLista));
        noAux = lista->inicio;
        printf("\nBusca no incio da lista realizada!\n");
        *resultado = SUCESSO;
        return noAux->dados;
    }
}

void *buscarFim(pLista lista, int *resultado)
{

    if (listaVazia(lista))
    {
        printf("\nLista vazia!\n");
        *resultado = ERRO;
        return NULL;
    }
    else
    {
        noLista *noAux = malloc(sizeof(noLista));
        noAux = lista->inicio;
        while (noAux->prox != NULL) // busca o penultimo elemento da lista
            noAux = noAux->prox;

        *resultado = SUCESSO;
        printf("\nBusca no fim da lista realizada!\n");
        return noAux->dados;
    }
}

void *buscarPos(pLista lista, int pos, int *resultado)
{

    if (listaVazia(lista))
    {
        printf("\nLista vazia!\n");
        *resultado = ERRO;
        return NULL;
    }
    else
    {
        if (!validarPosicaoInformada(lista, pos))
        {
            printf("\nPosicao inexistente na lista!\n");
            *resultado = ERRO;
            return NULL;
        }
        else
        {
            noLista *noAux = (noLista *)malloc(sizeof(noLista));

            noAux = lista->inicio;
            int cont = 0;
            while (cont < pos)
            {
                noAux = noAux->prox;
                cont++;
            }
            *resultado = SUCESSO;
            printf("\nBusca por posição realizada!\n");
            return noAux->dados;
        }
    }
}

void *buscarNo(pLista lista, int pos)
{
    if (listaVazia(lista))
        return NULL;
    else
    {
        noLista *noAux = (noLista *)malloc(sizeof(noLista));

        noAux = lista->inicio;
        int cont = 0;
        while (cont < pos)
        {
            noAux = noAux->prox;
            cont++;
        }
        return noAux;
    }
}

void imprimir(pLista lista)
{
    noLista *noAux = (noLista *)malloc(sizeof(noLista));
    noAux = lista->inicio;

    char *valor = malloc(sizeof(char *));
    printf("\nLISTA: \n");

    printf("qtde: %d\n", lista->qtdeNos);
    int i = 0;
    while (i < lista->qtdeNos)
    {
        memcpy(valor, noAux->dados, lista->tamanho_dados);
        printf("Pos: %d - Valor: %s-  %p - %p\n", i, valor, noAux, noAux->prox);
        noAux = noAux->prox;
        i++;
    }
}

int validarPosicaoInformada(pLista lista, int pos)
{
    if (pos < lista->qtdeNos)
        return 1; // Posicao existe
    else
        return 0;
}

void destruirLista(pLista lista, int *resultado) {
    
    if (!lista)
    {
        *resultado = ERRO;
        printf("\nLista não alocada!\n");
    }
    else
    {
        noLista *no = (noLista *)malloc(sizeof(noLista));        
        no = lista->inicio;

        while (no != NULL)
        {
            noLista *noDestruir = (noLista *)malloc(sizeof(noLista));
            memcpy(noDestruir, no, lista->tamanho_dados);
            no = no->prox;
            free(noDestruir);
        }

        free(lista);
        *resultado = SUCESSO;
    }
}