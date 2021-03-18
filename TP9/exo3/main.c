#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int length(const char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

char** optizAloc2(int argc, char *argv[]){
    int i ;
    char** new_tab = (char**)malloc(argc * sizeof(char*));
   for( i=0; i< argc ;i++){

   new_tab[i] = (char *)malloc ((length(argv[i]) * sizeof(char))* sizeof (char));
    memcpy(new_tab[i], argv[i], (length(argv[i]) * sizeof(char)));

  } 
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}
void print_2D_array(char *array[], int size_row) {
    int i;
    for (i = 0; i < size_row; i++) {
        printf("arg[%d] : %s ", i, array[i]);
        printf("\n");
    }
}
void free_2D_array(char **array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        free(array[i]);
    }

    free(array);
}

int main(int argc, char * argv[])
{
	
	
	char** result;
	result = optizAloc2(argc,argv);

    print_2D_array(result, argc);

    free_2D_array(result, argc);
	
	
	return EXIT_SUCCESS;
}
					
