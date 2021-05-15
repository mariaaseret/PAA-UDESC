#define SUCESSO 1
#define ERRO 0

typedef struct Fila{
    struct NoFila *inicio, *fim;
    int tamanho_dados;
}Fila;

typedef struct NoFila{
    void *dados;
    struct NoFila *ant;
}NoFila;

int cheia(Fila *f);
int vazia(Fila *f);