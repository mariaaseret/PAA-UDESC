# GNU Makefile

CC = gcc
CCFLAGS = -Wall
LDFLAGS =
TARGET = main

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

all: $(TARGET)

# Dependencias

main: Lista.o $(TARGET).c
Lista.o: Lista.c Lista_publica.h Lista_privada.h

clean:
	rm -f *.o *~ $(TARGET)
