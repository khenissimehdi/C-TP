#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"
#include <string.h>

void print_first_10(List *list)
{

  List current = (*list);
  int len = 0;
  while (current != NULL && len < 10)
  {
    printf("%s %d\n", current->path_name, current->size);
    current = current->next;
    len++;
  }
}

void ordered_insertion(List *l, Cell *newcell, int order_func(Cell *, Cell *))
{
  Cell *ptr;

  if ((*l) == NULL)
  {

    *l = newcell;

    return;
  }

  else if (!order_func((*l), newcell))
  {

    newcell->next = (*l);
    (*l) = newcell;

    return;
  }
  else
  {

    ptr = (*l);

    while (ptr->next != NULL && order_func(ptr, newcell))
      ptr = ptr->next;

    newcell->next = ptr->next,
    ptr->next = newcell;
  }
}

Cell *allocate_cell(char *path_name, int size)
{
  Cell *cell = (Cell *)malloc(sizeof(Cell));

  char *memory_path = (char *)malloc((strlen(path_name) + 1) * sizeof(char));

  if (cell == NULL)
  {
    printf("no memory");
    exit(1);
  }
  strcpy(memory_path, path_name);

  cell->path_name = memory_path;

  cell->size = size;
  cell->next = NULL;
  return cell;
}

int great_order(Cell *p1, Cell *p2)
{
  if (p1->size > p2->size)
  {

    return 1;
  }

  else
  {
    return 0;
  }
}

void free_list(List *list)
{
  List current = (*list);

  while (current != NULL)
  {
    free(current->path_name);
    free(current);
    current = current->next;
  }
}
