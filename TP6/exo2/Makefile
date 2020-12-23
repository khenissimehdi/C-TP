
permutations: permutations.o main.o
	gcc -o permutations permutations.o main.o

permutations.o: permutations.c
	gcc -o permutations.o -c permutations.c -W -Wall -ansi -pedantic

main.o: main.c permutations.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic