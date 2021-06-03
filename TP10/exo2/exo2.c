#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"
#include <string.h>

void print_list(List *list)
{

  List current = (*list);
  
  while (current != NULL)
  {
    printf("%s %s %d\n", current->first_name, current->last_name, current->age);
    current = current->next;
  }
}

Cell *allocate_cell(char *first, char *last, int age)
{
  Cell *cell = (Cell *)malloc(sizeof(Cell));

  char *firt_alloc = (char *)malloc((strlen(first) + 1) * sizeof(char));
  char *last_alloc = (char *)malloc((strlen(last) + 1) * sizeof(char));

  if (cell == NULL)
  {
    printf("no memory");
    exit(1);
  }
  strcpy(firt_alloc, first);
  strcpy(last_alloc, last);
  cell->first_name = firt_alloc;
  cell->last_name = last_alloc;
  cell->age = age;
  cell->next = NULL;
  return cell;
}
void ordered_insertion(List *l, Cell *new, int order_func(Cell *, Cell *))
{
  Cell *ptr;
  if (*l == NULL)
  {
    *l = new;
    return;
  }
  else if (order_func(*l, new))
  {
    new->next = *l;
    *l = new;
    return;
  }
  else
  {
    ptr = *l;
    while (ptr->next != NULL && !order_func(ptr->next, new))
      ptr = ptr->next;

    new->next = ptr->next,
    ptr->next = new;
  }
}

int age_order(Cell *p1, Cell *p2)
{
  if (p1->age > p2->age)
    return 1;
  else if (p1->age == p2->age)
    return name_order(p1, p2);
  else
    return 0;
}

int name_order(Cell *p1, Cell *p2)
{
  int cmp_last_name = strcmp(p1->last_name, p2->last_name);
  int cmp_first_name;

  if (cmp_last_name > 0)
    return 1;
  else if (cmp_last_name == 0)
  {
    cmp_first_name = strcmp(p1->first_name, p2->first_name);

    if (cmp_first_name > 0)
      return 1;
    else if (cmp_first_name == 0)
    {
      if (p1->age >= p2->age)
        return 1;
      else
        return 0;
    }
    else
      return 0;
  }
  else
  {
    return 0;
  }
}

void free_cell(Cell *c)
{
  free(c->first_name);
  free(c->last_name);
  free(c);
}
void free_list(List *list)
{
  while (*list)
  {
    Cell *tmp = (*list);
    *list = (*list)->next;
    free_cell(tmp);
  }
}
