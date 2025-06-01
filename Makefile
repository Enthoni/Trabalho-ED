CC=gcc
CFLAGS=-Wall -Wextra -std=c11

all: main

main: main.o bd_paciente.o
	$(CC) $(CFLAGS) -o main main.o bd_paciente.o

main.o: main.c bd_paciente.h
	$(CC) $(CFLAGS) -c main.c

bd_paciente.o: bd_paciente.c bd_paciente.h paciente.h
	$(CC) $(CFLAGS) -c bd_paciente.c

clean:
	rm -f *.o main