all: input.o process.o
	gcc -o prgrm input.o
	gcc -o helper process.o

input.o: input.c
	gcc -c input.c

process.o: process.c
	gcc -c process.c

run: prgrm helper
	./prgrm
