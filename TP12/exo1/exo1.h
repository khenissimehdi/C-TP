#include <stdio.h>
#include <stdlib.h>
#ifndef H_GL_HELLO
#define H_GL_HELLO

typedef struct node
{
    char *word;
    struct node *next;

} Node, *List;

void print(int *array, int s);
int *allocate_integer_array(int size);
void swap_mem(void *z1, void *z2, size_t size);
#endif
