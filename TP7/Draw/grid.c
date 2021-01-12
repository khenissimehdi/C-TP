#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "grid.h"

int checkRow(table grid,int row,int col,int num){
    int x;
    for ( x = 0; x <= 8; x++){

      if (x != row && x != col)
      {
       if (grid[row][x] == num){
            return 0;
        }
    }
   
  }
   return 1;
   
    
     
}

int checkCol(table grid, int row,int col,int num){
    int x ;
    for ( x = 0; x <= 8; x++){
     
      if (x != row && x != col)
      {

      
          if (grid[x][col] == num){
          
          return 0;	
        }
      }
    }
    return 1;
       
            
}

int checkZone(table grid, int row,int col,int num){
    int  i,j ;
 
    int startRow = row - row % 3,startCol = col - col % 3;
   
    for ( i = 0; i < 3; i++){
      for ( j = 0; j < 3; j++){
        if (i != startRow && j != startCol ){
           if (grid[i + startRow][j + startCol] == num){
                return 0;	
            }
        }

        }
    }
    return 1;
        
           
              

}




grid *create_grid(int x_size, int y_size) {
	int i, j;
	grid *g = (grid *)malloc(sizeof(grid));
	g->x_size = x_size;
	g->y_size = y_size;
	g->cells = (cell **)malloc(x_size*sizeof(cell *));
	for (i = 0; i < x_size; i++)
		g->cells[i] = (cell *)malloc(y_size*sizeof(cell));

	for (j = 0; j < y_size; j++)
		for (i = 0; i < x_size; i++) {
			g->cells[i][j].x_pos = i;
			g->cells[i][j].y_pos = j;
      g->cells[i][j].mark = 2;
			g->cells[i][j].number = 0;
		}

	return g;
}
int fillGrid( grid *board,tablenumber table){
    int i,j,c;
    c = 1;
    
    for (i=0 ; i<3; i++){
        for (j=0 ; j<3; j++){
         board->cells[j][i].number = c;
         /*table[i][j] = c;*/
         /*printf("%d %d %d " ,board->cells[i][j].number,i,j);*/
         c++;
    }
  }
}
int fread_board(const char* file, grid *board,int grid_w,int grid_h,table table){
  FILE* f;
  int i,j;
  int entry;

  f = fopen(file, "r");
  if (f == NULL){
    fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
    return 0;
  }

  for (i=0 ; i<grid_w ; i++){
    for (j=0 ; j<grid_h ; j++){
      fscanf(f, "%d", &entry);
      board->cells[j][i].number = entry;
      table[i][j] = entry;
    }
  }
  return 1;
}
