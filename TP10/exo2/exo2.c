#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

void print(int *array, int s)
{
  int i, size;
  size = s;
  for (i = 0; i < size; i++)
  {
    printf("%d\t", array[i]);
  }
}
int *allocate_integer_array(int size)
{
  int *new_tab;

  new_tab = (int *)malloc((size + 1) * sizeof(int));
  if (new_tab == NULL)
  {
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

Cell *allocate_cell(char *first, char *last, int age)
{
  Cell *c = (Cell *)malloc(sizeof(Cell));
  if (c == NULL)
  {
    printf("no memory");
    exit(1);
  }
  c->first_name = first;
  c->last_name = last;
  c->age = age;
  return c;
}
