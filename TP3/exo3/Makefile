
charconv: charconv.o main.o
	gcc -o charconv charconv.o main.o

charconv.o: charconv.c
	gcc -o charconv.o -c charconv.c -W -Wall -ansi -pedantic

main.o: main.c charconv.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
	rm charconv
