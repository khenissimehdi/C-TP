#ifndef GRID_H
#define GRID_H

#include "draw.h"



grid *create_grid(int x_size, int y_size);

int fillGrid( grid *board);
int fread_board(const char* file, grid *board,int grid_w,int grid_h);

#endif /* GRID_H */