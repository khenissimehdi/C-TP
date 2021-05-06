CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lm
DEPS=exo1.h
OBJ=exo1.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exo1: main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) exo1