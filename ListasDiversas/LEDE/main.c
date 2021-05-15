#include <stdio.h>

#include "lista_publica.h"

void reiniciaLista1a5(lLista ll) {
  reiniciarLista(ll);
  int v1 = 1;
  inserirInicio(ll, &v1);
  int v2 = 2;
  inserirFim(ll, &v2);
  int v3 = 3;
  inserirFim(ll, &v3);
  int v4 = 4;
  inserirFim(ll, &v4);
  int v5 = 5;
  inserirFim(ll, &v5);
}

void testDestruir(lLista ll) {
  destruirLista(ll);
  destruirLista(ll);
}

void testReiniciar(lLista ll) {
  reiniciarLista(ll);
  reiniciarLista(ll);
  reiniciarLista(ll);
  reiniciaLista1a5(ll);
  reiniciaLista1a5(ll);
  reiniciarLista(ll);
}

void testBuscarInicio(lLista ll) {
  reiniciaLista1a5(ll);
  mostrarListaInt(ll);

  int* pos0 = buscarInicio(ll);
  printf("value of pos 0 - %d \n", *pos0);
  removerInicio(ll);

  int* pos1 = buscarInicio(ll);
  printf("value of pos 1 - %d \n", *pos1);
  removerInicio(ll);

  int* pos2 = buscarInicio(ll);
  printf("value of pos 2 - %d \n", *pos2);
  removerInicio(ll);

  int* pos3 = buscarInicio(ll);
  printf("value of pos 3 - %d \n", *pos3);
  removerInicio(ll);

  int* pos4 = buscarInicio(ll);
  printf("value of pos 4 - %d \n", *pos4);
  removerInicio(ll);

  void* buscaNull = buscarInicio(ll);
  printf("valor de busca posicao inexistente Null %s \n", (char*)buscaNull);
  removerInicio(ll);

  reiniciarLista(ll);

  void* buscaNull2 = buscarInicio(ll);
  printf("valor de busca posicao inexistente Null %s \n", (char*)buscaNull2);
}

void testBuscarPos(lLista ll) {
  reiniciaLista1a5(ll);
  mostrarListaInt(ll);

  int* pos0 = buscarPos(ll, 0);
  printf("value of pos 0 - %d \n", *pos0);

  int* pos1 = buscarPos(ll, 1);
  printf("value of pos 1 - %d \n", *pos1);

  int* pos2 = buscarPos(ll, 2);
  printf("value of pos 2 - %d \n", *pos2);

  int* pos3 = buscarPos(ll, 3);
  printf("value of pos 3 - %d \n", *pos3);

  int* pos4 = buscarPos(ll, 4);
  printf("value of pos 4 - %d \n", *pos4);

  void* buscaNull = buscarPos(ll, 5);
  printf("valor de busca posicao inexistente Null %s \n", (char*)buscaNull);

  reiniciarLista(ll);

  void* buscaNull2 = buscarPos(ll, 2);
  printf("valor de busca posicao inexistente Null %s \n", (char*)buscaNull2);
}

void testRemoverFim(lLista ll) {
  reiniciaLista1a5(ll);
  mostrarListaInt(ll);

  mostrarListaInt(ll);
  removerFim(ll);
  removerFim(ll);
  removerFim(ll);
  removerFim(ll);
  mostrarListaInt(ll);
  int* valueRemoved = removerFim(ll);
  printf("value of result %d \n", *valueRemoved);

  void* removeNull = removerFim(ll);
  printf("valor de removed posicao inexistente Null %s \n", (char*)removeNull);
  mostrarListaInt(ll);
}

void testInserirPos(lLista ll) {
  int v5 = 5;
  inserirInicio(ll, &v5);
  mostrarListaInt(ll);

  int v4 = 4;
  inserirPos(ll, &v4, 0);
  mostrarListaInt(ll);

  int v3 = 3;
  inserirPos(ll, &v3, 1);
  mostrarListaInt(ll);

  int v2 = 2;
  inserirPos(ll, &v2, 2);
  mostrarListaInt(ll);

  int v1 = 1;
  inserirPos(ll, &v1, 3);
  mostrarListaInt(ll);

  int v6 = 6;
  inserirPos(ll, &v6, 5);
  mostrarListaInt(ll);
}

void testInserirInicioFim(lLista ll) {
  int v5 = 5;
  inserirInicio(ll, &v5);
  mostrarListaInt(ll);

  int v4 = 4;
  inserirFim(ll, &v4);
  mostrarListaInt(ll);

  int v3 = 3;
  inserirInicio(ll, &v3);
  mostrarListaInt(ll);

  int v2 = 2;
  inserirFim(ll, &v2);
  mostrarListaInt(ll);

  int v1 = 1;
  inserirInicio(ll, &v1);
  mostrarListaInt(ll);

  int v6 = 6;
  inserirInicio(ll, &v6);
  mostrarListaInt(ll);
}

void testInserirInicio(lLista ll) {
  int v5 = 5;
  inserirInicio(ll, &v5);
  mostrarListaInt(ll);

  int v4 = 4;
  inserirInicio(ll, &v4);
  mostrarListaInt(ll);

  int v3 = 3;
  inserirInicio(ll, &v3);
  mostrarListaInt(ll);

  int v2 = 2;
  inserirInicio(ll, &v2);
  mostrarListaInt(ll);

  int v1 = 1;
  inserirInicio(ll, &v1);
  mostrarListaInt(ll);

  int v6 = 6;
  inserirInicio(ll, &v6);
  mostrarListaInt(ll);
}

void testInserirFim(lLista ll) {
  int v5 = 5;
  inserirFim(ll, &v5);
  mostrarListaInt(ll);

  int v4 = 4;
  inserirFim(ll, &v4);
  mostrarListaInt(ll);

  int v3 = 3;
  inserirFim(ll, &v3);
  mostrarListaInt(ll);

  int v2 = 2;
  inserirFim(ll, &v2);
  mostrarListaInt(ll);

  int v1 = 1;
  inserirFim(ll, &v1);
  mostrarListaInt(ll);

  int v6 = 6;
  inserirFim(ll, &v6);
  mostrarListaInt(ll);
}

void testRemoverPos(lLista ll) {
  void* removeNull = removerPos(ll, 3);
  printf("valor de removed posicao inexistente Null %s \n", (char*)removeNull);
  mostrarListaInt(ll);

  int v1 = 1;
  inserirInicio(ll, &v1);
  mostrarListaInt(ll);

  void* resultRemoveUnsetPos = removerPos(ll, 3);
  printf("value of result pos 3 %s \n", (char*)resultRemoveUnsetPos);
  mostrarListaInt(ll);

  int* valueRemoved = removerPos(ll, 0);
  printf("value of result %d \n", *valueRemoved);
  mostrarListaInt(ll);

  int v2 = 2;
  inserirInicio(ll, &v2);
  mostrarListaInt(ll);

  int v3 = 3;
  inserirFim(ll, &v3);
  mostrarListaInt(ll);

  int v4 = 4;
  inserirFim(ll, &v4);
  mostrarListaInt(ll);

  int v5 = 5;
  inserirInicio(ll, &v5);
  mostrarListaInt(ll);

  int v6 = 6;
  inserirInicio(ll, &v6);
  mostrarListaInt(ll);

  int* valueRemovedFirst = removerPos(ll, 4);
  printf("\nvalue of result %d \n", *valueRemovedFirst);
  mostrarListaInt(ll);

  void* resultRemoveUnsetPos2 = removerPos(ll, 4);
  printf("value of result pos 4 %s \n", (char*)resultRemoveUnsetPos2);
  // mostrarListaInt(ll);

  reiniciarLista(ll);
  reiniciaLista1a5(ll);
  mostrarListaInt(ll);
  removerPos(ll, 4);
  mostrarListaInt(ll);
  removerPos(ll, 3);

  mostrarListaInt(ll);

  int* valorRemovidoMeio = removerPos(ll, 1);
  printf("\nvalue of result %d \n", *valorRemovidoMeio);
  mostrarListaInt(ll);

  reiniciarLista(ll);

  reiniciaLista1a5(ll);
  mostrarListaInt(ll);
  int* valorRemovidoMeio2 = removerPos(ll, 1);
  printf("\nvalue of result %d \n", *valorRemovidoMeio2);
  removerPos(ll, 3);
  removerPos(ll, 2);
  removerPos(ll, 5);
  removerPos(ll, 4);
  mostrarListaInt(ll);
  int* another = removerPos(ll, 0);
  printf("Removed last element %d\n", *another);
  mostrarListaInt(ll);
}

void testRemoverInicio(lLista ll) {
  void* removeNull = removerInicio(ll);
  printf("value of result Null %s \n", (char*)removeNull);
  mostrarListaInt(ll);

  int a = 2;
  inserirInicio(ll, &a);
  mostrarListaInt(ll);

  int* valueRemoved = removerInicio(ll);
  printf("valor removido do inicio %d \n\n", *valueRemoved);
  mostrarListaInt(ll);

  inserirInicio(ll, &a);
  mostrarListaInt(ll);

  int b = 3;
  inserirInicio(ll, &b);
  mostrarListaInt(ll);

  int* valueRemoved2 = removerInicio(ll);
  printf("valor removido do inicio %d \n\n", *valueRemoved2);
  mostrarListaInt(ll);

  int valor2 = 12;
  inserirInicio(ll, &valor2);
  int valor3 = 13;
  inserirInicio(ll, &valor3);
  int valor4 = 14;
  inserirInicio(ll, &valor4);
  int valor5 = 15;
  inserirInicio(ll, &valor5);
  inserirInicio(ll, &valor5);
  mostrarListaInt(ll);

  int* valueRemoved3 = removerInicio(ll);
  printf("valor removido do inicio %d \n\n", *valueRemoved3);
  mostrarListaInt(ll);
}

void testString(lLista ls) {
  char v5[15] = "ultimo valor";

  char v1[15] = "primeiro valor";
  inserirInicio(ls, &v1);

  inserirInicio(ls, &v1);

  char v2[15] = "valor do meio";
  inserirPos(ls, &v2, 1);

  int result = inserirFim(ls, &v5);
  printf("\n result %d", result);

  char* v5buscado = buscarFim(ls);
  printf("\n v5buscado: %s", v5buscado);

  char* v1buscado = buscarInicio(ls);
  printf("\n v1buscado: %s", v1buscado);

  char* meio = buscarPos(ls, 2);
  printf("\n meio: %s", meio);

  reiniciaLista1a5(ls);
  mostrarListaInt(ls);
  destruirLista(ls);
}

int main(int argc, char* argv[]) {
  lLista ll = criarLista(5, sizeof(int));

  if (ll == 0) return 1;

  testReiniciar(ll);
  testInserirPos(ll);
  testInserirInicioFim(ll);
  testInserirFim(ll);
  testInserirInicio(ll);
  testRemoverPos(ll);
  testRemoverInicio(ll);
  testRemoverFim(ll);
  testBuscarPos(ll);
  testBuscarInicio(ll);
  testDestruir(ll);

  lLista ls = criarLista(3, sizeof(char[15]));
  if (ls == 0) return 1;

  testString(ls);

  return 0;
}