#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

void print_Stack(stack *stack)
{
  link *current = (stack->top);

  while (current != NULL)
  {
    printf("%ld \n", current->elt);
    current = current->next;
  }
}

link *allocate_link(long elt)
{

  link *l = (link *)malloc(sizeof(link));

  if (l == NULL)
  {
    printf("no memory");
    exit(1);
  }

  l->elt = elt;

  l->next = NULL;
  return l;
}

stack *create_stack(long first_elt)
{
  stack *s = (stack *)malloc(sizeof(stack));
  link *l = allocate_link(first_elt);
  s->top = l;
  s->size = 1;
  return s;
}

void push_stack(stack *s, long elt)
{
  link *new_lnk = (link *)malloc(sizeof(link));
  new_lnk->elt = elt;
  new_lnk->next = s->top;
  s->top = new_lnk;
  s->size++;
}
long pop_stack(stack *s)
{
  link *tmp = s->top;
  long pop = tmp->elt;
  s->top = s->top->next;
  s->size--;
  return pop;
}

void free_link(link *c)
{
  free(c);
}

void free_Stack(stack *stack)
{

  while (stack->top)
  {
    link *tmp = stack->top;
    stack->top = stack->top->next;
    free_link(tmp);
  }
}

void swap_mem(void *a, void *b, size_t len)
{
  char *p = a, *q = b, tmp;
  size_t i;
  for (i = 0; i != len; ++i)
  {
    tmp = p[i];
    p[i] = q[i];
    q[i] = tmp;
  }
}

void reverse(stack *s)
{
  swap_mem(s->top, s->top->next, s->size);
}