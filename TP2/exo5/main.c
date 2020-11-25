#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pointeur.h"
 #define MAX_LENGTH 1048576
int main(int argc, char *argv[])
{
   FILE *fptr; 
  
   char filename[100], c; 
  
   printf("give me a file to open \n"); 
   scanf("%s", filename); 
  
    //we open the file
    fptr = fopen(filename, "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    //while the file not ended we get and we print the the line  
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
   //close the file 
    fclose(fptr); 
   
	return EXIT_SUCCESS;
}
					
