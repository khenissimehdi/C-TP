#include <stdio.h>
#include <stdlib.h>

void print(int *array, int s)
{
  int i, size;
  size = s;
  for (i = 0; i < size; i++)
  {
    printf("%d\t", array[i]);
  }
}
