# TDA LISTA (LESE)
Lista Linear Estática Simplesmente Encadeada

Funções disponíveis neste TDA:
    ### Orientações gerais: É necessário informar um ponteiro de inteiros que fará o controle sobre o sucesso ou não da operação realizada (simbolizado por int * resultado) 

   ``Funções para criar, reinicializar e destruir a Lista ``
      CriarLista (int tamanho_dados, int tamanho_maximo, int * resultado);
      ReiniciarLista (struct Lista * lista, int * resultado);
      DestruirLista (struct Lista * lista, int * resultado);
        ## Orientação: É necessário definir o tamanho dos dados (por se tratar de void) e o tamanho MAXIMO da lista

  ``Funções para adicionar elementos a Lista``
      InserirInicio (struct Lista * lista, * elemento, int * resultado);
      InserirFim (struct Lista * lista, * elemento, int * resultado);
      InserirPos (struct Lista * lista, * elemento, int Pos, int * resultado);
        ## Orientação: Para inserir em uma posição específica da lista, é necessário passar por parametro uma variavel do tipo int com a posição desejada

  ``Funções para remover elementos da Lista``
      RemoverInicio(struct Lista * lista, int * resultado);
      RemoverFim(struct Lista * lista, int * resultado);
      RemoverPos(struct Lista * lista, int Pos, int * resultado);
        ## Orientação: Para remover em uma posição específica da lista, é necessário passar por parametro uma variavel do tipo int com a posição desejada

  ``Funções que consultam elementos da Lista (sem modifica-la)``
      BuscarInicio(struct Lista * lista, int * resultado);
      BuscarFim(struct Lista * lista, int * resultado);
      BuscarPos(struct Lista * lista, int Pos, int * resultado);
       ## Orientação: Para buscar em uma posição específica da lista, é necessário passar por parametro uma variavel do tipo int com a posição desejada

-------------------------------------------------------------------------------------- 
# COMO COMPILAR

  ``No terminal``
    gcc -o lista Lista.c main.c -w
  
  ``Para executar``
    ./lista

-------------------------------------------------------------------------------------- 
