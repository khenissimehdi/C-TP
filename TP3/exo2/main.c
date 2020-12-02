#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wc.h"


/* int main(int argc, char *argv[]) */
/* { */

/*     char str[] = "windobe     hello\n hi\tbye "; */

/* 	int res = wc(str); */
/* 	printf("%d\n",res); */
/* 	return EXIT_SUCCESS; */
/* } */
					

int main(int argc, char *argv[])
{
  printf("%d\n", wc2());
  return EXIT_SUCCESS;
}

/* Voici des preuves de bon fonctionnement de wc2 */
/*
nborie@bayer:~/Review/C-TP/TP3/exo2$ echo "un deux trois quatre" | wc
      1       4      21
nborie@bayer:~/Review/C-TP/TP3/exo2$ echo "un deux trois quatre" | ./wc
4
nborie@bayer:~/Review/C-TP/TP3/exo2$ man man | wc -w
5169
nborie@bayer:~/Review/C-TP/TP3/exo2$ man man | ./wc
5169
nborie@bayer:~/Review/C-TP/TP3/exo2$ ./wc
voici deux mots en plus
une autre ligne
encore quelques mots
mais je termine par CTRL+D (c'est EOF en console CRTL+D)
21
*/
