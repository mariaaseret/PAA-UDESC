typedef struct Lista Lista;

int listaCriar(Lista** lista);
int listaDestruir(Lista** lista);
int listaReiniciar(Lista* lista);

int listaInserirInicio(Lista* lista, int tamanho_dados, void* dados);
int listaInserirFim(Lista* lista, int tamanho_dados, void* dados);
int listaInserirPos(Lista* lista, int pos, int tamanho_dados, void* dados);

int listaRemoverInicio(Lista* lista, void* dados);
int listaRemoverFim(Lista* lista, void* dados);
int listaRemoverPos(Lista* lista, int pos, void* dados);

int listaBuscarInicio(Lista* lista, void* dados);
int listaBuscarFim(Lista* lista, void* dados);
int listaBuscarPos(Lista* lista, int pos, void* dados);

int listaTamanho(Lista* lista);
int listaVazia(Lista* lista);