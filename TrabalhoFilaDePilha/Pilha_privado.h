#include <stdio.h>
#include <stdlib.h>
#include "Pilha_interface.h"

typedef struct Pilha {
  int top;
  int altura_pilha;
  int size_data;
  void* data;
} Pilha;
