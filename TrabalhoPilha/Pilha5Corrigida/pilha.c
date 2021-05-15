#include <stdio.h>
#include <stdlib.h>
#include "pilha_privado.h"


pilha *
Init (int t)
{
  //Aloca espaco para o indicador de estado dos elementos
  pilha *aPilha = malloc (sizeof (pilha));

  aPilha->topo = 0;
  aPilha->size = t;
  aPilha->datas = malloc (t * sizeof (void *));


  // Informa que a pilha foi inicializada
  printf
    ("Pilha inicializada com %i elementos.\nCorrespondentes ao número de incidência de palavras que iniciam com a letra A ou a no arquivo texto.txt",
     t);

  return aPilha;
}

int
Destroy (pilha * p)
{
  // Verifica se o ponteiro estava vazio antes:
  if (p == NULL)
    {
      printf ("\nPilha não inicializada. Executar função Init antes.");
      return -1;
    }

  //Se o ponteiro nC#o estava vazio, libera a memC3ria:
  free (p->datas);
  free (p);
  //free(aPilha);
  return 1;
}

// Adiciona um valor ao topo da pilha, deslocando os demais
int
Push (pilha * p, void *data)
{
  // Verifica se o ponteiro estava vazio antes:
  if (p == NULL)
    {
      printf ("\nPilha não inicializada. Executar função Init antes.");
      return -1;
    }

  if (p->topo < p->size)
    {
      p->datas[p->topo] = data;
      ((p->topo))++;
      //printf("entrou o numero");
      //printf(data);
    }
  else
    {
      printf ("\nAcabou o espaço.");
      return -1;
    }

  return 1;
}

// Remove o valor que estC! no topo da pilha, deslocando os demais
int
Pop (pilha * p)
{
  // Verifica se o ponteiro estava vazio antes:
  if (p == NULL)
    {
      printf
  ("\nPilha não inicializada. Executar função Init antes. Valor retornado é -1.");
      return -1;
    }

  // Verifica se o primeiro valor da pilha jC! foi preenchido com alguma informaC'C#o
  if (p->datas == NULL)
    {
      printf
  ("\nPilha está vazia. Não há elementos para remover. Valor retornado é -1.");
      return -1;
    }

  (p->topo)--;

  return 1;

}

void *
Top (pilha * p)
{
  // Verifica se o ponteiro estava vazio antes:
  if (p == NULL)
    {
      printf
  ("\nPilha nC#o inicializada. Executar função Init antes. Valor retornado é -1.");
      return -1;
    }

  // Verifica se o primeiro valor da pilha jC! foi preenchido com alguma informaC'C#o
  if (p->datas == NULL)
    {
      printf
  ("\nPilha está vazia. Não há elementos para exibir. Valor retornado é 0.");
      return 0;
    }

  // Retorna o C:ltimo valor da pilha
  return p->datas[p->topo - 1];
}

int
IsFull (pilha * p)
{
  // Verifica se o ponteiro estava vazio antes:
  if (p == NULL)
    {
      printf ("\nPilha não inicializada. Executar função Init antes.");
      return -1;
    }

  int topo = (p->topo);
  int size = (p->size);
  if (topo < size)
    {
      printf ("\nPilha não está cheia.");
      return 0;
    }
  else
    {
      printf ("\nPilha está cheia.");
      return 1;
    }

}

bool
IsEmpty (pilha * p)
{
  // Verifica se o ponteiro estava vazio antes:
  if (p == NULL)
    {
      printf ("\nPilha não inicializada. Executar função Init antes.");
      return -1;
    }
  if (p->datas == NULL)
    {
      printf ("\nPilha não inicializada. Executar função Init antes.");
      return 1;
    }
  return p->topo == 0;

}
