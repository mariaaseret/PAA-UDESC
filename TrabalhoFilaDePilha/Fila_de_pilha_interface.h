typedef struct filaDePilha* pFilaDePilha;
#define SUCESSO 1
#define FRACASSO 0

pFilaDePilha cria(int tamanho_dados, int* resultado);
void destroi(pFilaDePilha fp, int* resultado);
void insere(pFilaDePilha fp, void* elemento, int* resultado);
void* retira(pFilaDePilha fp, int* resultado);
