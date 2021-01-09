CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=$(shell pkg-config --libs-only-l MLV)
DEPS=grid.h draw.h
OBJ=sodku.o grid.o draw.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sodku: $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) sodku