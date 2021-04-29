
exo1: exo1.o main.o
	gcc -o exo1 exo1.o main.o

exo1.o: exo1.c
	gcc -o exo1.o -c exo1.c -W -Wall -ansi -pedantic

main.o: main.c exo1.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic