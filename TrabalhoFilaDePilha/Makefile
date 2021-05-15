default: main

CC = gcc
CCFLAGS = -Wall
LDFLAGS =
TARGET = main

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

Fila.o: Fila.c Fila_interface.h Fila_privado.h
	gcc $(CCFLAGS) -c Fila.c -o Fila.o

Pilha.o: Pilha.c Pilha_interface.h Pilha_privado.h
	gcc $(CCFLAGS) -c Pilha.c -o Pilha.o

FilaDePilha.o: Fila_de_pilha.c Fila_de_pilha_interface.h Fila_de_pilha_privado.h Fila.o Pilha.o
	gcc $(CCFLAGS) -c Fila_de_pilha.c Fila.o Pilha.o -o FilaDePilha.o

main: main.c main.h FilaDePilha.o Fila.o Pilha.o
	gcc $(CCFLAGS) main.c FilaDePilha.o Fila.o Pilha.o -o main
