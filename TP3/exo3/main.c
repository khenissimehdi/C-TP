#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "charconv.h"

/*
int main(int argc, char *argv[])
{

    char str = 'a';

	int res = charconv(str);
	printf("%d\n",res);
	return EXIT_SUCCESS;
}
*/					


int main(int argc, char *argv[])
{
  if (is_number(argv[1])){
    print_base_26(atoi(argv[1]));
    putchar('\n');
  }
  else{
    printf("%d\n", str_to_decimal(argv[1]));
  }
  return EXIT_SUCCESS;
}


/* QUELQUES PREUVES DE BON FONCTIONNEMENT */

/*
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 123
et
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv et
123
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 73654
eeyw
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv eeyw
73654
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 262535 | xargs ./charconv 
262535
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 0 | xargs ./charconv 
0
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 1 | xargs ./charconv 
1
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 2 | xargs ./charconv 
2
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 3 | xargs ./charconv 
3
nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv 8263524 | xargs ./charconv 
8263524

---> -12 makes a bug... more work would be needed to secure that!

nborie@bayer:~/Review/C-TP/TP3/exo3$ ./charconv -12 | xargs ./charconv
-639639848
*/
