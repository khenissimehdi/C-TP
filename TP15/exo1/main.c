#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"
#include "operation.h"
#include <readline/readline.h>
#include <readline/history.h>
stack *create_stack_empty()
{
  stack *s = (stack *)malloc(sizeof(stack));
  s->top = NULL;
  s->size = 0;
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
        if (s->size >= 2)
        {
          addition(s);
        }
        else
        {
          printf(" the size is less then 2 ");
        }
      }
      else if (strcmp("-", word) == 0)
      {
        if (s->size >= 2)
        {
          soustraction(s);
        }
        else
        {
          printf(" the size is less then 2 ");
        }
      }
      else if (strcmp("*", word) == 0)
      {
        if (s->size >= 2)
        {
          product(s);
        }
        else
        {
          printf(" the size is less then 2 ");
        }
      }
      else if (strcmp("/", word) == 0)
      {
        if (s->size >= 2)
        {
          quotient(s);
        }
        else
        {
          printf(" the size is less then 2 ");
        }
      }
      else if (strcmp("%%", word) == 0)
      {
        if (s->size >= 2)
        {
          modulo(s);
        }
        else
        {
          printf(" the size is less then 2 ");
        }
      }
      else if (strcmp("^", word) == 0)
      {
        if (s->size >= 2)
        {
          expo(s);
        }
        else
        {
          printf(" the size is less then 2 ");
        }
      }
      else if (strcmp("!", word) == 0)
      {

        factorial(s);
      }

      else if (strcmp("r", word) == 0)
      {
        if (s->size >= 2)
        {
          reverse(s);
        }
        else
        {
          printf(" the size is less then 2 ");
        }
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
      else if (strcmp("s", word) == 0)
      {
        printf("%d ", s->size);
      }
      else if (strcmp("h", word) == 0)
      {
        printf(" ======COMMANDS======= ");
        printf("p : print the whole stack \n ");
        printf("s : print the current size \n ");
        printf("r : reverse the first two values on the stack \n ");
        printf("q: exit the program \n ");
        printf(" ======OPERATIONS====== ");
        printf("+ : addition \n ");
        printf("* : multiplication \n ");
        printf("- : soustraction \n ");
        printf("/ : division \n ");
        printf("! : factoriel \n ");
        printf("^ : exponentiation \n ");
      }
      else
      {
        char *endptr;
        long val;
        if (isNumeric(word) == 1)
        {
          val = strtol(word, &endptr, 10);
          push_stack(s, val);
        }
        else
        {
          printf("Unknown operation %s \n", word);
        }
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
