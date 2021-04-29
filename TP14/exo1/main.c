
#include <stdio.h>
#include <ftw.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include "exo1.h"
List head = NULL;

int ls_rec(const char *fpath, const struct stat *sb, int typeflag)
{
  puts(fpath);
  return 0;
}

int engine(const char *fpath, const struct stat *sb, int tflag)
{

  char *path_name = (char *)malloc((strlen(fpath) + 1) * sizeof(char));

  strcpy(path_name, fpath);

  ordered_insertion(&head, allocate_cell(path_name, sb->st_size), great_order);
  free(path_name);
  return tflag - tflag;
}

int main(int argc, char *argv[])
{
  int i;
  if (argc < 1)
  {
    printf("Usage: %s file[path][file]... \n", argv[0]);
    return 0;
  }

  for (i = 1; i < argc; ++i)
  {

    if (ftw(argv[i], engine, 10) == -1)
    {
      perror("ftw()");

      exit(-1);
    }
  }

  print_first_10(&head);
  free_list(&head);

  return 0;
}
