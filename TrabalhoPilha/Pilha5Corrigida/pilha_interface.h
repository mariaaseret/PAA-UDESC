#include <stdbool.h>

typedef struct aPilha pilha;

pilha *Init (int t);

int Destroy (pilha * aPilha);

int Push (pilha * aPilha, void *data);

void *Top (pilha * aPilha);

int Pop (pilha * aPilha);
