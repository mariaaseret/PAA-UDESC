para iniciar a pilha utilize 
int resultado;
struct Fila *fila = criar(TAMANHODODADO, &resultado);

para imprimir o início da fila
printf("f->inicio:   %p\n", fila->inicio);

para imprimir o fim da fila
printf("f->fim:   %p\n", fila->fim);
