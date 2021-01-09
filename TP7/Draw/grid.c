#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include "draw.h"




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
			g->cells[i][j].marked = 0;
			g->cells[i][j].number = 0;
		}

	return g;
}
int fillGrid( grid *board){
    int i,j,c;
    c = 1;
    
    for (i=0 ; i<3; i++){
        for (j=0 ; j<3; j++){
         board->cells[j][i].number = c;
         c++;
    }
  }
}
int fread_board(const char* file, grid *board,int grid_w,int grid_h){
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
      board->cells[i][j].number = entry;
    }
  }
  return 1;
}
