# Lista Linear Estatica Duplamente Encadeada

- A lista estatica tem tamanho fixo assim que criado
- A lista é duplamente encadeada, então o anterior do primeiro aponta para o último e o próximo do ultimo deve apontar para o primeiro

### Dependencias
- [linux](https://www.linux.org/pages/download/)
- [GCC](https://gcc.gnu.org/install/index.html)
- [make](https://www.unixmen.com/install-ubuntu-make-on-ubuntu-15-04/)

### Métodos Publicos
- Os `ifndef` e `endif` são apenas para facilitar em casos que multiplos arquivos importam `lista_publica.h`. Entretando, detro do TDA os includes são respeitados
```c
// lista_publica.h

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
```

### Estrutura de Lista Privada
```c
// lista_privada.h

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

...

```

### Como buildar
- Para buildar você deve criar ou modificar o `main.c` no root do projeto

- Execute o comando `make`
__Resultado Esperado__
![](https://i.imgur.com/8yiNwTg.png)

- Deve gerar o arquivo executável `main`

### Como Executar
- Após realizar o build do executável com `make`
- Rode o arquivo com a seguinte linha de comando
```shell
./main
```

__Resultado Esperado__
![](https://i.imgur.com/SXIacqo.png)

> Para limpar, realizar o build e executar o main use `make run`

### Como Limpar
- Limpa todos os `.out` e o `main`
- Execute o comando `make clean`
