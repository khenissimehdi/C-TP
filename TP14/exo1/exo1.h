#include <stdio.h>
#include <stdlib.h>
#ifndef H_GL_HELLO
#define H_GL_HELLO
typedef struct cell
{
    char *path_name;
    int size;

    struct cell *next;
} Cell, *List;

void print_first_10(List *list);
Cell *allocate_cell(char *path_name, int size);
void ordered_insertion(List *l, Cell *newcell, int order_func(Cell *, Cell *));
int great_order(Cell *p1, Cell *p2);
void free_list(List *list);

#endif
