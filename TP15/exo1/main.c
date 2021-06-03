#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "exo1.h"
#include "operation.h"
#include <readline/readline.h>
#include <readline/history.h>
stack *create_stack_empty()
{
  stack *s = (stack *)malloc(sizeof(stack));
  s->top = NULL;
  s->size = 1;
  return s;
}
int isNumeric(char *str)
{
  int i;
  for (i = 0; i < strlen(str); i++)
  {
    if (isdigit(str[i]) == 1)
    {
      return 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[])
{
  int exit = 0;
  stack *s = create_stack_empty();
  char *line;
  while ((line = readline("> ")))
  {
    char *word = strtok(line, " ");

    add_history(line);
    while (word != NULL)
    {
      if (strcmp("+", word) == 0)
      {
        addition(s);
      }
      else if (strcmp("+", word) == 0)
      {
        addition(s);
      }
      else if (strcmp("-", word) == 0)
      {
        soustraction(s);
      }
      else if (strcmp("*", word) == 0)
      {
        product(s);
      }
      else if (strcmp("/", word) == 0)
      {
        quotient(s);
      }
      else if (strcmp("%%", word) == 0)
      {
        modulo(s);
      }

      else if (strcmp("p", word) == 0)
      {
        print_Stack(s);
      }

      else if (strcmp("q", word) == 0)
      {
        exit = 1;
        break;
      }
      else
      {
        char *endptr;
        long val;
        val = strtol(word, &endptr, 10);
        push_stack(s, val);
      }
      word = strtok(NULL, " ");
    }
    if (exit == 1)
    {
      break;
    }
  }
  clear_history();
  return 0;
}
