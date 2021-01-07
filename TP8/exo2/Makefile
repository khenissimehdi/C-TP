
syracuse: syracuse.o main.o
	gcc -o syracuse syracuse.o main.o

syracuse.o: syracuse.c
	gcc -o syracuse.o -c syracuse.c -W -Wall -ansi -pedantic

main.o: main.c syracuse.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic