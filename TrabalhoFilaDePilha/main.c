#include "main.h"

int main(){
    int resultado;
    pFilaDePilha fila_de_pilha = cria(sizeof(int), &resultado);
    if (resultado == FRACASSO) {
        printf("Erro ao criar fila de pilha\n");
        exit(1);
    }

    int x;
    printf("Digite seu numero ou digite -1 para terminar\n");
    do {
        scanf("%i", &x);
        if (x != -1) {
            insere(fila_de_pilha, &x, &resultado);
            if (resultado == FRACASSO) {
                printf("Erro ao inserir\n");
                exit(1);
            }
        }
    } while (x != -1);

    do {
        void* elemento = retira(fila_de_pilha, &resultado);
        if (resultado == FRACASSO) break;
        printf("%i\n", *(int*)elemento);
    } while (resultado == SUCESSO);

    destroi(fila_de_pilha, &resultado);

    if (resultado == FRACASSO) {
        printf("Erro ao destruir fila de pilha\n");
        exit(1);
    }
    return 0;
}
