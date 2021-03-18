
exo3: exo3.o main.o
	gcc -o exo3 exo3.o main.o

exo3.o: exo3.c
	gcc -o exo3.o -c exo3.c -W -Wall -ansi 

main.o: main.c exo3.h
	gcc -o main.o -c main.c -W  -Wall -ansi 