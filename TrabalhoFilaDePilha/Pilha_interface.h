typedef struct Pilha *pPilha, **ppPilha;

void cria_pilha(ppPilha pilha, int altura_pilha, int size_data);
void destroi_pilha(ppPilha pilha);
void empilha(pPilha pilha, void* elem);
void* desempilha(pPilha pilha);
void* olha_topo(pPilha pilha);

int pilha_cheia(pPilha pilha);
int pilha_vazia(pPilha pilha);
