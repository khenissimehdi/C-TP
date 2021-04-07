#include <stdio.h>
#include <stdlib.h>
#ifndef H_GL_HELLO
#define H_GL_HELLO

typedef struct node
{
    char *word;
    struct node *next;

} Node, *List;

void print_list(List *list);
void fill_list(List *lst, FILE *f);
int len(List *list);
Node *create_node(char *word);
int check_exist(List *lst, char *word);
void swap_mem(void *z1, void *z2, size_t size);
#endif
