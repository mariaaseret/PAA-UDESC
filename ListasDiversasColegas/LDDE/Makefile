all: aplicacao

aplicacao: ldde.o main.o
	gcc ldde.o main.o -o aplicacao

ldde.o: ldde.c
	gcc -c ldde.c -o ldde.o

main.o: main.c
	gcc -c main.c -o main.o

clean: 
	rm -f aplicacao *.o 
