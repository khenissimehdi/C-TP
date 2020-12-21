
power: power.o main.o
	gcc -o power power.o main.o

power.o: power.c
	gcc -o power.o -c power.c -W -Wall -ansi -pedantic

main.o: main.c power.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
	rm power
