
#include <stdio.h>
#include <ftw.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include "exo1.h"
List head = NULL;

int engine(const char *fpath, const struct stat *sb, int tflag)
{
  ordered_insertion(&head, allocate_cell(fpath, sb->st_size), great_order);
  return tflag - tflag;
}

int main(int argc, char *argv[])
{
  int i;
  /**
 *  if the argc is equal to 1 means nth have been passed we print a message 
 * and we return 0 to stop the program
 */
  if (argc == 1)
  {
    printf("Usage: %s file[path][file]... \n", argv[0]);
    return 0;
  }
  /**
  *  we use ftw to read throught the file and create cells using engine 
  */
  for (i = 1; i < argc; ++i)
  {

    if (ftw(argv[i], engine, 10) == -1)
    {
      perror("ftw()");

      exit(-1);
    }
  }
  /**
   *  print the first 10 biggest elements 
   */

  print_first_10(&head);
  free_list(&head);

  return 0;
}
