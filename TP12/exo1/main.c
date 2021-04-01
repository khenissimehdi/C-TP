#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo1.h"
void read_words(FILE *f)
{
  char x[1024];

  while (fscanf(f, " %s", x) == 1)
  {
    puts(x);
  }
}

int main(void)
{

  FILE *ptr = fopen("Germinal.txt", "r");
  if (ptr == NULL)
  {
    printf("no such file.");
    return 0;
  }

  read_words(ptr);

  return EXIT_SUCCESS;
}
