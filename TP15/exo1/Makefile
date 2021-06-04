CC=gcc
CFLAGS=-Wall -ansi -lreadline -L. -lstack
LDFLAGS=-lm
DEPS=stack.h operation.h
OBJ=stack.o operation.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) exo1