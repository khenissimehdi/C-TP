
fabrication: fabrication.o main.o
	gcc -o fabrication fabrication.o main.o

fabrication.o: fabrication.c
	gcc -o fabrication.o -c fabrication.c -W -Wall -ansi -pedantic

main.o: main.c fabrication.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic