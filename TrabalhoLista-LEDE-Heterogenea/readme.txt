1 TDA Lista Linear Estática Duplamente Encadeada Heterogênea
════════════════════════════════════════════════════════════

  Todas as funções da biblioteca esperam, como último argumento, um
  endereço para uma variável inteira onde será escrito o resultado da
  operação. Se o valor escrito for 0, tudo ocorreu com sucesso. Caso
  contrário, houve algum erro.

  A lista é estática, portanto todos os nós são alocados no momento da
  criação, conforme o tamanho_maximo determinado para a lista. Os nós
  contém ponteiros para elementos, que podem ser de tipos/tamanhos
  distintos (heterôgeneos), e que portanto não são alocados no momento
  da criação. Ao inserir um elemento, é alocado um espaço de memória
  para ele, que é apontado pelo nó correspondente à posição determinada
  na inserção. Ao remover, somente o elemento é desalocado, sendo que o
  nó continua alocado (comportamento estático). A única forma de
  destruir os nós é destruindo a lista.

  As funções públicas disponíveis são:
  ┌────
  │ pLista criar_lista(int tamanho_dados, int *resultado);
  │ void reiniciar_lista(pLista lista, int *resultado);
  │ void destruir_lista(pLista lista, int *resultado);
  │ 
  │ void* buscar_inicio(pLista lista, int* resultado);
  │ void* buscar_fim(pLista lista, int* resultado);
  │ void* buscar_pos(pLista lista, int pos, int* resultado);
  │ 
  │ void inserir_inicio(pLista lista, void* elemento, int tamanho_elemento, int* resultado);
  │ void inserir_fim(pLista lista, void* elemento, int tamanho_elemento, int* resultado);
  │ void inserir_pos(pLista lista, int pos, void* elemento, int tamanho_elemento, int* resultado);
  │ 
  │ void remover_inicio(pLista lista, int* resultado);
  │ void remover_fim(pLista lista, int* resultado);
  │ void remover_pos(pLista lista, int pos, int* resultado);
  └────
