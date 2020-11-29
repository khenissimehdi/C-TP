
stack: stack.o main.o
	gcc -o stack stack.o main.o

stack.o: stack.c
	gcc -o stack.o -c stack.c -W -Wall -ansi -pedantic

main.o: main.c stack.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic