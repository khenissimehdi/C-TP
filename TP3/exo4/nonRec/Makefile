
dicSearch: dicSearch.o main.o
	gcc -o dicSearch dicSearch.o main.o

dicSearch.o: dicSearch.c
	gcc -o dicSearch.o -c dicSearch.c -W -Wall -ansi -pedantic

main.o: main.c dicSearch.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic