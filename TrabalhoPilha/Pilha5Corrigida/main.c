#include "main.h"

int
main ()
{

  FILE *f = fopen ("texto.txt", "rb");

  fseek (f, 0, SEEK_END);
  long fsize = ftell (f);
  fseek (f, 0, SEEK_SET);

  char *texto = (char *) malloc (fsize + 1);
  fread (texto, fsize, 1, f);
  fclose (f);

  texto[fsize] = 0;

  int cont = 0;
  int contaPalavra = 0;
  int contaPalavraCerta = 0;
  char *palavras[300];
  char *palavrasCertas[300];
  int tamanho = strlen (texto);
  char *token = strtok (texto, "\b \b\n");
  while (token != NULL)
    {
      if ((strchr (token, 'a') != NULL) || (strchr (token, 'A') != NULL)) // se a palavra contém a letra a ou A
  { 
    palavras[contaPalavra] = token;
    if ((isalpha (*palavras[contaPalavra]) != 0))
      {
        char *w = token;
          char firstLetter = w[0];
          //printf("%c\n",firstLetter);
          if(firstLetter == 'a' || firstLetter == 'A'){ // se a palavra que contém a ou A inicia com a letra a ou A
        palavrasCertas[contaPalavraCerta] = token;
        contaPalavraCerta++;
          }
      }
    contaPalavra++;
  }
      token = strtok (NULL, "\b \b\n");
      cont++;
    }

  pilha *p = Init (contaPalavraCerta);
  printf ("\n====Empilhando====");
  for (int i = 0; i < contaPalavraCerta; i++)
    {
      Push (p, (palavrasCertas[i]));
      printf ("\n%s", (char *) Top (p));
    }
  printf ("\n====IsFull====");
  IsFull (p);

  printf ("\n====IsEmpty====");
  if (IsEmpty (p))
    {
      printf ("\nA pilha está vazia");
    }
  else
    {
      printf ("\nA pilha não está vazia");
    }

  printf ("\n====Desempilhando====");
  for (int i = 0; i < contaPalavraCerta; i++)
    {
      printf ("\n%s", (char *) Top (p));
      Pop (p);
    }
  printf ("\n====IsFull====");
  IsFull (p);

  printf ("\n====IsEmpty====");
  if (IsEmpty (p))
    {
      printf ("\nA pilha está vazia");
    }
  else
    {
      printf ("\nA pilha não está vazia");
    }
}
