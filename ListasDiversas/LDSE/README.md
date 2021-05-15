# Biblioteca de lista
Projeto e análise de algoritmos
UDESC Joinville

Após descompactar, adicionar no .c:
#include "lista_publica.h"

-------------------------------------------------------------------------------------- 
 Para compilar:

  gcc -o  lista lista.c main.c
  ./lista

-------------------------------------------------------------------------------------- 
 Obs: 

Lista Linear Dinâmica Simplesmente Encadeada
Homogênea 
-> Simplemesmente encadeada - somente para o próximo

As posições da lista são iniciadas a partir do zero. Ex:  Lista: 4 - 5 - 7 - 9. O elemento 4 está na posição 0. 

-------------------------------------------------------------------------------------- 
# Funções disponíveis  
Abaixo são descritas cada uma das funções disponíveis para a lista. 

# ------------- Funções públicas ------------- 

- descritor *criarLista(int tamanho_dados, int *resultado) 
Cria e aloca memória para a lista. Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo:
  pLista lista = criarLista(sizeof(int *), &resultado);

- void destruirLista(pLista lista, int *resultado)
Libera memória alocada para os elementos e para a lista.
Exemplo: 
   destruirLista(lista, &resultado);
    if(resultado == 0) {
        printf("Lista destruída!\n");
    }

# metodos de insercao

- void inserirInicio(pLista lista, void *elemento, void *valorInserido, int *resultado)
Insere o elemento passado por parâmetro no início da lista.  
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo:
  inserirInicio(lista, &valor, valorInserido, &resultado);
  printf("Valor inserido: %d \n", *valorInserido);  

- void inserirFim(pLista lista, void *elemento, void *valorInserido, int *resultado)
Insere o elemento passado por parâmetro no fim da lista. 
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo:
  inserirFim(lista, &valor3, valorInserido, &resultado);
  printf("Valor inserido: %d \n", *valorInserido); 

- void inserirPos(pLista lista, void *elemento, void *valorInserido, int pos, int *resultado) 
Insere o elemento passado por parâmetro na posicao também fornecida no parâmetro 'pos'.
Caso a posicao seja inválida na lista, ou seja, não existe elementos, uma mensagem de erro será repassada. 
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo: 
  inserirPos(lista, &valor4, valorInserido, 2, &resultado);
  printf("Valor inserido: %d \n", *valorInserido);   

OBS: caso seja fornecido a primeira posicao ou a última posicao, a funcao chamará os respectivos métodos de inserir no inicio e inserir no fim. Portanto a mensagem correspondente será a desses métodos. 
 
# metodos de remocao

- void removerInicio(pLista lista, void *valorRemovido, int *resultado)
Remove o primeiro elemento da lista. 
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo:
  removerInicio(lista, valorRemovido, &resultado2);
  printf("Valor removido: %d \n", *valorRemovido);

- void removerFim(pLista lista, void *valorRemovido, int *resultado)
Remove o último elemento da lista. 
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo:
  removerFim(lista, valorRemovido, &resultado2);
  printf("Valor removido: %d \n", *valorRemovido); 

- void removerPos(pLista lista, void *valorRemovido, int post, int *resultado)
Remove o elemento da posicao fornecida no parâmetro 'pos'.
Caso a posicao seja inválida na lista, ou seja, não existe elementos, uma mensagem de erro será repassada. 
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo:   
  removerPos(lista, valorRemovido, 1, &resultado2);
  printf("Valor removido: %d \n", *valorRemovido); 

OBS: caso seja fornecido a primeira posicao ou a última posicao, a funcao chamará os respectivos métodos de remover no inicio e remover no fim. Portanto a mensagem correspondente será a desses métodos. 

# metodos de busca

- void* buscarInicio(pLista lista, int *resultado);
Busca o primeiro elemento da lista. 
Retorna o valor buscado.
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo: 
  valorBuscado = buscarInicio(lista, &resultado);
  printf("Valor buscado: %d \n", *valorBuscado);

- void* buscarFim(pLista lista, int *resultado);
Busca o último elemento da lista. 
Retorna o valor buscado.
Repassa ao ponteiro o resultado de SUCESSO / ERRO.
Exemplo: 
  valorBuscado = buscarFim(lista, &resultado);
  printf("Valor buscado: %d \n", *valorBuscado);

- void* buscarPos(pLista lista, int pos, int *resultado);
Busca na lista o elemento informado no parâmetro 'pos'.
Retorna o valor buscado.
Repassa ao ponteiro o resultado de SUCESSO / ERRO.   
  valorBuscado = buscarPos(lista,1, &resultado);
  printf("Valor buscado: %d \n", *valorBuscado); 

 
# ------------- Funções privadas ------------- 
- int listaVazia(pLista lista)) e int listaCheia(pLista lista)
Retorna 1 se a lista está cheia/vazia ou 0 se não está.

- noLista* criarNo(descritor* lista, void* elemento);
Cria e aloca memória para os nós a serem incluídos na lista. 
Repassa ao ponteiro o resultado de SUCESSO / ERRO.

- void *buscarNo(pLista lista, int pos);
Busca por um nó específico que está na posição informado no parâmetro 'pos'. 

- int validarPosicaoInformada(pLista lista, int pos);
Valida se existe um elemento na posicao informada. 

-------------------------------------------------------------------------------------- 
