
wc: wc.o main.o
	gcc -o wc wc.o main.o

wc.o: wc.c
	gcc -o wc.o -c wc.c -W -Wall -ansi -pedantic

main.o: main.c wc.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
	rm wc
