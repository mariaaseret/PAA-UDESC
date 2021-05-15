Implementação de pilha genérica e de tamanho variado de acordo com a 
incidência de palavras que iniciam com a letra A ou a e estão dentro do arquivo texto.txt dentro
do mesmo ficheiro;

Para compilar seu main é necessário adicionar inicialmente #include "main.h"

Para inicializar uma pilha adicione  pilha *p = Init (x); sendo x um número inteiro 
representando o tamanho da pilha

Para adicionar diretamente uma palavra na pilha 
Push(p, "Anil");
printf("%s\n", (char*)Top(p));

Para adicionar diretamente um inteiro na pilha
Push(p, 1);
printf("%s\n", (int*)Top(p));