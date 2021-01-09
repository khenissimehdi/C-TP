#include <MLV/MLV_all.h>
#include "draw.h"
#define LINE_COLOR MLV_COLOR_BLUE
#define BACKGROUND_COLOR MLV_COLOR_WHITE
#define GRID_SCALE 60
#define GRID_WIDTH  9
#define GRID_HEIGHT 9


void draw_rectangle(int x, int y, MLV_Color line_color,int scale,int move_x, int move_y) {

	MLV_draw_rectangle(
			scale*x+move_x,
			scale*y+move_y,
			scale,
			scale,
			line_color
		);
}
void draw_cell(cell *c,int scale,int move_x,int move_y) {

	char label[] = "0";
	MLV_Color col;
	col = MLV_COLOR_BLACK;
	draw_rectangle(c->x_pos, c->y_pos, MLV_COLOR_BLACK,scale,move_x,move_y);

		
		sprintf(label, "%c", '0'+c->number);
		
		if (c->number != 0)
		{	
			MLV_draw_text(
					scale*c->x_pos+move_x+(scale-10)/2,
					scale*c->y_pos+move_y+(scale-10)/2,
					label,
					col
				);
		}
		
		

	
	
	
	
}
	

void draw_grid(grid *g,int scale,int move_x, int move_y) {
	int i, j;
	for (i = 0; i < g->x_size; i++)
		for (j = 0; j < g->y_size; j++)
			draw_cell(&g->cells[i][j],scale,move_x,move_y);
	MLV_actualise_window();
}


