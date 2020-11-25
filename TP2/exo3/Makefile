
n: n.o main.o
	gcc -o n n.o main.o

n.o: n.c
	gcc -o n.o -c n.c -W -Wall -ansi -pedantic

main.o: main.c n.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic