#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include "fusion.h"


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
    table[size] = -1;
    printf(" %d",table[0]);
    printf("your table is finished enjoy our service \n");
    return table ;                         

}
int* random_array(int size, int max_entry){
    int i;
    int* table;
    table = allocate_int_array(size);
    srand(time(0));
    for(i=0;i<=size;i++){
     if( i == size){
         table[i]=-1;
     }
     else
     {
        table[i]=(rand()%max_entry); 
     }
     
     
    }
    return table;
}
int* concat_array(int* first, int* second){
      int* table;
      int size ; 
      int sizeF,sizeS;
      int i;
      int j;

      sizeF = array_size(first);
      sizeS = array_size(second);
      size  = array_size(first) + array_size(second);
      table = allocate_int_array(size);
      for ( i = 0; i < sizeF; i++)
      {
          table[i] = first[i];
      }
      for ( j = 0; j < sizeS; j++)
      {
          
          table[sizeF++] = second[j];
      }
      table[size] = -1;
      return table;
}

int* merge_sorted_arrays(int* first, int* second){
    int i = 0, j = 0, k = 0; 
    
    int* table; 
    int size,sizeF,sizeS;
    sizeF = array_size(first);

    sizeS = array_size(second);

    size  = sizeS + sizeF;
    
    table = allocate_int_array(size);
    
    while (i<sizeF && j <sizeS) 
    { 
	
	
        if (first[i] < second[j]){
			
			table[k++] = first[i++]; 
			

		}
            
		
        else{
			
			table[k++] = second[j++]; 
		}
            
    }   
	
    while (i < sizeF) 
        table[k++] = first[i++]; 
  
	
    while (j < sizeS){
		
        table[k++] = second[j++]; 
	} 

    table[size] = -1;
    ;
    return table;

}

void split_arrays(int* array, int** first, int** second){
    int i,k1,k2,length,mid;

    k1 = 0;
    k2 = 0;
    length = array_size(array);
    mid = length / 2;
   
    if (length % 2 != 0)
    {
        mid = mid + 1;
       /* printf(" im in\n");*/
        *first = allocate_int_array(mid);
        *second = allocate_int_array(mid-1);
        *(first[0] + mid) = -1;
        *(second[0] + mid-1) = -1;
    }
    else
    {
        *first = allocate_int_array(mid);
        *second = allocate_int_array(mid);
        *(first[0] + mid) = -1;
        *(second[0] + mid) = -1;
    }
    
    
    
   
    for ( i = 0; i < length; i++)
    {
        if (i < mid)
        {
             *(first[0] + k1++) = array[i];
        }
        else
        {
            *(second[0] + k2++) = array[i];
        } 
    }
    

}
int* merge_sort(int* array){
    int* first;
    int* second;
    int m = array_size(array);
    if ( m <= 1)
    {
        return array;
    }
  
    split_arrays(array,&first,&second);
    printf(" origin \n");
    print_array(array);
    putchar('\n');

    first = merge_sort(first);
    
    second = merge_sort(second);

    printf( "first \n");
    print_array(first);
    putchar('\n');

    printf( "second \n");
    print_array(second);
    putchar('\n');

   
    
    
    return merge_sorted_arrays(first,second);
   

    
}
int array_size(int* array){
    int y = 0; 
    while (array[y] != - 1)
    {
     y+=1;
     
    } 
    return y;

}

void print_array(int* array){
    int i,size;
    size = array_size(array);
    for ( i = 0; i < size; i++)
    {
        printf("%d\t",array[i]);
    }
    
}

int are_arrays_equal(int* first, int* second){
    int i,firstSize,secondSize;
    firstSize = array_size(first);
    secondSize = array_size(second);

    if (firstSize != secondSize)
    {
        return 0 ;
    }
    

    for ( i = 0; i < firstSize; i++)
    {
        if (first[i] != second[i])
        {
           return 0;
        }
        
    }
    return 1;
    
}
int* copy_array(int* array){
   int i,size;
   int* deepCopy;
   
   
   size =  array_size(array);
   
   
    deepCopy = allocate_int_array(size);
	for (i = 0; i <= size; ++i) { 
			if(i == size){
			   deepCopy[4] = -1;
			   break;
			}
            deepCopy[i] = i + 1; 
        } 
   
   return deepCopy;
}

