#ifndef GRID_H
#define GRID_H

#include "draw.h"
typedef int tablenumber[3][3];
typedef int table[9][9];


grid *create_grid(int x_size, int y_size);

int fillGrid( grid *board,tablenumber table);
int fread_board(const char* file, grid *board,int grid_w,int grid_h,table table);
int checkRow(table grid,int row,int col,int num);
int checkCol(table grid, int row,int col,int num);
int checkZone(table grid, int startRow,int startCol,int num);
/*int safe(grid* grid, int row, int col, int num);*/

#endif /* GRID_H */