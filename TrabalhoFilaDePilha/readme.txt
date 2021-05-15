1 TDA Fila de Pilha
═══════════════════

  Implementamos um TDA para fila de pilha, que tem a seguinte interface:

  ┌────
  │ pFilaDePilha cria(int tamanho_dados, int* resultado);
  │ void destroi(pFilaDePilha fp, int* resultado);
  │ void insere(pFilaDePilha fp, void* elemento, int* resultado);
  │ void* retira(pFilaDePilha fp, int* resultado);
  └────

  As funções destroi e insere recebem elementos de um tipo qualquer (com
  tamanho igual a tamanho_dados). Os elementos são armazenados conforme
  a especificação da Fila de Pilha, ou seja, em uma fila de pilhas de
  tamanho 3.

  Todas as funções da biblioteca esperam, como último argumento, um
  endereço para uma variável inteira onde será escrito o resultado da
  operação. Se o valor escrito for 1, tudo ocorreu com sucesso. Caso
  contrário, houve algum erro.

  Esse TDA usa internamente os TDAs originais de Fila e de Pilha, com
  pequenas modificações para que métodos que verificam se a estrutura
  está cheia ou vazia sejam públicos, e para que seja possível olhar
  para o início da fila sem desenfileirar.

  Nossa estratégia é sempre manter uma pilha com espaços vagos
  disponíveis no final da fila. Assim, sempre que enchemos a última
  pilha, na hora já enfileiramos uma nova pilha vazia. Dessa forma,
  podemos sempre empilhar um novo elemento na pilha que está no final da
  fila. A última pilha inserida é sempre apontada pelo ponteiro
  `pilha_atual`, presente no descritor. O descritor, portanto, precisa
  conhecer somente a fila e a pilha atual que está sendo manipulada,
  assim como o tamanho dos dados enfileirados, já que lida com dados
  genéricos.
