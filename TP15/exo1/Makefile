CC=gcc
CFLAGS=-Wall -ansi -lreadline
LDFLAGS=-lm
DEPS=exo1.h operation.h
OBJ=exo1.o operation.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exo1: main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) exo1