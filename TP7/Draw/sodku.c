#include <MLV/MLV_all.h>
#include "draw.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

#define LINE_COLOR MLV_COLOR_BLUE
#define BACKGROUND_COLOR MLV_COLOR_WHITE
#define GRID_WIDTH  9
#define GRID_HEIGHT 9
#define GRID_SCALE 60
void draw_cell_actualise_window(cell *c,int scale,int move_x,int move_y) {
	draw_cell(c,scale,move_x,move_y);
	MLV_actualise_window();
}

int main(int argc, char* argv[]) {

	/* Create the window */
	MLV_create_window("Draw", "Draw", 1200, 800);
	MLV_draw_filled_rectangle(0, 0, 1200, 800, BACKGROUND_COLOR);

	

	grid *g = create_grid(GRID_WIDTH, GRID_HEIGHT);
	
	fread_board(argv[1], g,GRID_WIDTH,GRID_HEIGHT);
	draw_grid(g,60,0,0);

	
	grid *c = create_grid(3,3);
	fillGrid(c);
	draw_grid(c,50,750,200);

/* Main game loop */
	MLV_Event event = MLV_NONE;
	MLV_Keyboard_button key_button;
	MLV_Mouse_button mouse_button;
	MLV_Button_state mouse_state;
	int x_pixel, y_pixel, x_pos, y_pos,x_pos2, y_pos2;

	
	while (!(event == MLV_KEY && key_button == MLV_KEYBOARD_ESCAPE)) {

		event = MLV_wait_event(
				&key_button,
				NULL,
				NULL,
				NULL,
				NULL,
				&x_pixel,
				&y_pixel,
				&mouse_button,
				&mouse_state
			);
		
		if (event == MLV_MOUSE_BUTTON && mouse_state == MLV_RELEASED) {

			/* The player has pressed a button */
			x_pos = x_pixel;
			y_pos = y_pixel;
			x_pos2 = ((x_pixel-750)/50);
			y_pos2 = ((y_pixel-200)/50);
			printf("Mouse click on (%d,%d)\n", x_pos2, y_pos2);
			/*cell *ce = &g->cells[x_pos][y_pos];*/
			cell *ce2 = &c->cells[x_pos-3][y_pos];

			/*if (mouse_button == MLV_BUTTON_LEFT ) {

				ce->number = 1;

				
			}
			draw_cell_actualise_window(ce,60,0,0);*/

			
		}
	}


	
	
	/*recd( 200 ,  200 , width/2);*/
	MLV_update_window();

	/* Wait and quit */

	MLV_wait_seconds(100000);
	MLV_free_window();

	return 0;
}