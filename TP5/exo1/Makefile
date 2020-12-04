
tableaux: tableaux.o main.o
	gcc -o tableaux tableaux.o main.o

tableaux.o: tableaux.c
	gcc -o tableaux.o -c tableaux.c -W -Wall -ansi -pedantic

main.o: main.c tableaux.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic