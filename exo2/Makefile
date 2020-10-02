
add: add.o main.o
	gcc -o add add.o main.o

add.o: add.c
	gcc -o add.o -c add.c -W -Wall -ansi -pedantic

main.o: main.c add.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic