#include <stdbool.h>

#include "pilha_interface.h"

struct aPilha
{
  int topo;			//topo da pilha
  void **datas;			//valores da pilha
  int size;			//tamanho dos valores jC! que pode receber qualquer tipo com tamanhos diferentes
};

int IsFull (pilha * aPilha);
bool IsEmpty (pilha * aPilha);
