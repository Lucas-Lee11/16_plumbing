all: input.o process.o
	gcc -o console input.o
	gcc -o processor process.o

input.o: input.c
	gcc -c input.c

process.o: process.c
	gcc -c process.c

run: console processor
	./console
