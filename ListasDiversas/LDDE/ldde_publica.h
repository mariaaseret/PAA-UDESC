#ifndef _LDDE_PUBLICA
#define _LDDE_PUBLICA

#define SUCESSO 0 
#define ERRO 1 

typedef struct ldde ldde;
typedef ldde * pldde;

int CriarLista(pldde * lista, int tamanho_dados);
int DestruirLista(pldde * lista);
int ReiniciarLista(pldde lista);

int InserirInicio(pldde lista, void * elemento);
int InserirFim(pldde lista, void * elemento);
int InserirPos(pldde lista, void * elemento, int posicao);

int RemoverInicio(pldde lista);
int RemoverFim(pldde lista);
int RemoverPos(pldde lista, int posicao);

void * BuscarInicio(pldde lista);
void * BuscarFim(pldde lista);
void * BuscarPos(pldde lista, int posicao);


#endif
