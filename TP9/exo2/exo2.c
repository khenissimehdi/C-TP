#include <stdio.h>
#include <stdlib.h>

void print(char** array,int s,int s2){
    int i,j;
   
    for ( i = 0; i < s; i++)
    {
       for ( j = 0; j <  s2; j++){
           printf("%c\t",array[i][j]);
       }
       
    }
    
}
char** allocate_char2D_array(int DIM_1,int DIM_2){
    int i ;
    char** new_tab = (char**)malloc(DIM_1 * sizeof(char*));
   for( i=0; i<DIM_1 ;i++){

   new_tab[i] = (char *)malloc (DIM_2 * sizeof (char));

  } 
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

void free_2D_char(char** tab, int DIM_1){  
  int i;
  for(i=0 ; i< DIM_1 ; i++)
    free(tab[i]);
  free(tab);
}

void init_tab_2d(char** tab, int n, int m){
    int x,y = 0;
    for(x = 0; x < n ; x++){

      for(y=0; y < m ; y++ ){
         tab[x][y] = 'a' + ((x+y) % 26);
          }
      }
    }

		