#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int* allocate_int_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}


int* fill_array(void){
 
    

    int size;
    int count = 0 ;
    int element;
    int* table;
    
    printf("welcome Sir !\n");
    printf("Enter a size for your array please: \n");
    scanf("%d", &size);

    table = allocate_int_array(size);
    printf("Memory have been alocated\n");
    printf("Enter  %d elements for your array please: \n",size);
    while (count != size)
    {
        printf("Enter an element please: \n");
        scanf(" %d", &element);
        table[count] = element;
        count+=1;
    }
    
    printf("your table is finished enjoy our service \n");
    return table ;                         

}



int main()
{		
	int* array ;
	array = fill_array();
	putchar('\n');
	printf(" %d",array[0]);
	return EXIT_SUCCESS;
}

					
