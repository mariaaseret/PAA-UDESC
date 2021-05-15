#include <stdio.h>
#include <stdlib.h>
#include "Lista_publica.h"

int main(int argc, char **argv)
{
    int Resultado;
    int i = 0;
    

    //Criando lista de Palavras
    lista_t *p = NULL;
    p = CriarLista(sizeof(char) * 100, 100, &Resultado);

    //Criando lista de numeros (inteiros)
    lista_t *f = NULL;
    f = CriarLista(sizeof(int), 100, &Resultado);

    //Definindo as palavras da lista
    char* um = "um";
    char* dois = "dois";
    char* tres = "tres";
    char* quatro = "quatro";
    char* cinco = "cinco";
    char* seis = "seis";
    char* saida; //Captura o resultado retornado pelas funções

    printf("\n ############# Execucao da Lista de Palavras #############\n");

    printf("\n## Adicionado e buscando elementos na lista ##\n\n");

    InserirInicio(p, um, &Resultado);
    saida = BuscarInicio(p, &Resultado);
    printf("\nElemento adicionado no inicio: %s\n", saida);

    InserirInicio(p, dois, &Resultado);
    saida = BuscarInicio(p, &Resultado);
    printf("\nElemento adicionado no inicio: %s\n", saida);

    InserirInicio(p, tres, &Resultado);
    saida = BuscarInicio(p, &Resultado);
    printf("\nElemento adicionado no inicio: %s\n", saida);

    InserirInicio(p, quatro, &Resultado);
    saida = BuscarInicio(p, &Resultado);
    printf("\nElemento adicionado no inicio: %s\n", saida);

    InserirFim(p, cinco, &Resultado);
    saida = BuscarFim(p, &Resultado);
    printf("\nElemento adicionado no fim: %s\n", saida);

    InserirPos(p, seis, 3, &Resultado);
    saida = BuscarPos(p, 3, &Resultado);
    printf("\nElemento na posicao 3: %s\n", saida);
    
    saida = BuscarInicio(p, &Resultado);
    printf("\nBuscar no inicio: %s\n", saida);

    saida = BuscarFim(p, &Resultado);
    printf("\nBuscar no fim: %s\n", saida);

    printf("\n## Removendo elementos da lista ##\n\n");

    saida = RemoverInicio(p, &Resultado);
    printf("Elemento removido do inicio da lista: %s\n",saida);

    saida = RemoverFim(p, &Resultado);
    printf("Elemento removido do fim da lista: %s\n",saida);

    saida = RemoverFim(p, &Resultado);
    printf("Elemento removido do fim da lista: %s\n",saida);

    saida = RemoverPos(p, 0, &Resultado);
    printf("Elemento removido na posicao 1 da lista: %s\n",saida);

//--------------------------------------------------------------------------------------------------------------

    printf("\n ############# Execucao da Lista de Numeros (inteiros) #############\n\n");

    printf("\n## ADICIONA NO INICIO, REMOVE DO INCIO (retorno sera de tras para frente) ##\n");
   
    // Adiciona elementos
    for (i=0; i<10; i++){
        int *k;
        k = (int*)malloc(sizeof(int));
        *k = (1+i)*10;
        InserirInicio(f, *k, &Resultado);  //Jeito correto de enviar e receber os dados
        printf("Elemento enfileirado: %d\n",(int)BuscarInicio(f, &Resultado));
    }
    printf("\n");
   
    // Retorna elementos
    for (i = 0; i < 15; i++){
        int *k;
        void* dado;
        dado = BuscarInicio(f, &Resultado);
        if (Resultado == 1){
            printf("Elemento no inicio da lista: %d\n",(int)dado);
            dado = RemoverInicio(f, &Resultado);
            printf("Elemento removido do inicio da lista: %d\n",(int)dado);
        }
         printf("\n");
    }

    printf("\n## ADICIONA NO FIM, REMOVE DO FIM (retorno sera de tras para frente) ##\n\n");
    
    // Adiciona elementos
    for (i=0; i<10; i++){
        int *k;
        k = (int*)malloc(sizeof(int));
        *k = (1+i)*10;
        InserirFim(f, *k, &Resultado);  //Jeito correto de enviar e receber os dados
        printf("Elemento inserido no fim lista: %d\n",(int)BuscarFim(f, &Resultado));
    }
     printf("\n");
    
    // Retorna elementos
    for (i = 0; i < 15; i++){
        int *k;
        void* dado;
        dado = BuscarFim(f, &Resultado);
        if (Resultado == 1){ 
            printf("Elemento no fim da lista: %d\n",(int)dado);
            dado = RemoverFim(f, &Resultado);
            printf("Elemento removido do fim da lista: %d\n",(int)dado);
        }
        printf("\n");
    }

    // Teste de reinicializacao da lista
    printf("\nReinicializando a lista\n");
    f = ReiniciarLista(f, &Resultado);

    printf("\n## ADICIONA NO FIM, REMOVE DO INICIO (retorno sera sequencial) ##\n\n");
    
    // Adiciona elementos
    for (i=0; i<10; i++){
        int *k;
        k = (int*)malloc(sizeof(int));
        *k = (1+i)*10;
        InserirFim(f, *k, &Resultado);  //Jeito correto de enviar e receber os dados
        printf("Elemento inserido no fim da lista: %d\n",(int)BuscarFim(f, &Resultado));
    }
    printf("\n");
    
    // Retorna elementos
    for (i = 0; i < 15; i++){
        int *k;
        void* dado;
        dado = BuscarInicio(f, &Resultado);
        if (Resultado == 1){ 
            printf("Elemento no inicio da lista: %d\n",(int)dado);
            dado = RemoverInicio(f, &Resultado);
            printf("Elemento removido do inicio lista: %d\n",(int)dado);
        }
          printf("\n");
    }
    printf("\n## RETORNA POSICAO ##\n\n");
   
    // Adiciona elementos
    for (i=0; i<10; i++){
        int *k;
        k = (int*)malloc(sizeof(int));
        *k = (1+i)*10;
        printf("Posicao %d, elemento inserido no fim da lista: %d\n",i, (int)*k);
        InserirFim(f, *k, &Resultado);  //Jeito correto de enviar e receber os dados
    }
     printf("\n");

    // Retorna elementos
    int posicao = 3;
    int *k;
    void* dado;

    printf("\n## Verificando a posicao 3 da lista ##\n\n");
    dado = BuscarPos(f, posicao, &Resultado);
    printf("Elemento na posicao %d: %d\n",posicao, (int)dado);

    dado = RemoverPos(f, posicao, &Resultado);
    printf("Elemento removido da posicao %d: %d\n",posicao,(int)dado);

    dado = BuscarPos(f, posicao, &Resultado);
    printf("Novo elemento na posicao %d: %d\n",posicao, (int)dado);

    printf("\n## Verificacoes usando a posicao 5 da lista ##\n\n");
    posicao = 5;

    printf("Elemento na posicao %d: %d\n",posicao-1, (int)BuscarPos(f, posicao-1, &Resultado));
    printf("Elemento na posicao %d: %d\n",posicao, (int)BuscarPos(f, posicao, &Resultado));
    printf("Elemento na posicao %d: %d\n",posicao+1, (int)BuscarPos(f, posicao+1, &Resultado));

    printf("\nAdicionando o elemento %d a posicao %d\n", 1000,posicao);
    InserirPos(f, (int)1000, posicao, &Resultado);
    printf("Elemento na posicao %d: %d\n",posicao-1, (int)BuscarPos(f, posicao-1, &Resultado));
    printf("Elemento na posicao %d: %d\n",posicao, (int)BuscarPos(f, posicao, &Resultado));
    printf("Elemento na posicao %d: %d\n",posicao+1, (int)BuscarPos(f, posicao+1, &Resultado));
    printf("Elemento na posicao %d: %d\n",posicao+2, (int)BuscarPos(f, posicao+2, &Resultado));


    printf("\n## Destruindo as listas ##\n\n");
    DestruirLista(p, &Resultado); //Lista de palavras
    DestruirLista(f, &Resultado); //Lista de numeros inteiros
}
