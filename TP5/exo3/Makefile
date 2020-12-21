
fusion: fusion.o main.o
	gcc -o fusion fusion.o main.o

fusion.o: fusion.c
	gcc -o fusion.o -c fusion.c -W -Wall -ansi 

main.o: main.c fusion.h 
	gcc -o main.o -c main.c -W -Wall -ansi 