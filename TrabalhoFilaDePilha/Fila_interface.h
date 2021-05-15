typedef struct Fila* pFila;

pFila cria_fila(int tamanho_dados, int* resultado);
void enfileira(pFila f, void* elemento, int* resultado);
void* desenfileira(pFila f, int* resultado);
void destroi_fila(pFila f, int* resultado);
void* olha_inicio(pFila f, int* resultado);
int fila_vazia(pFila f);
