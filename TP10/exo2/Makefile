
exo2: exo2.o main.o
	gcc -o exo2 exo2.o main.o

exo2.o: exo2.c
	gcc -o exo2.o -c exo2.c -W -Wall -ansi -pedantic

main.o: main.c exo2.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic