#ifndef DRAW_H
#define DRAW_H

#include <MLV/MLV_all.h>
typedef struct {
	int x_pos;
	int y_pos;
	int mark;
	int number;
} cell;

typedef struct {
	cell **cells;
	int x_size;
	int y_size;
} grid;


void draw_rectangle(int x, int y, MLV_Color line_color,int scale,int move_x, int move_y);
void draw_cell(cell *c,int scale,int move_x, int move_y);
void draw_grid(grid *g,int scale,int move_x, int move_y);

#endif /* DRAW_H */