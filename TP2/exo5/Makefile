
pointeur: Pointeur.o main.o
	gcc -o pointeur Pointeur.o main.o

pointeur.o: pointeur.c
	gcc -o pointeur.o -c pointeur.c -W -Wall -ansi -pedantic

main.o: main.c pointeur.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic