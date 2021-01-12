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
	table t1;
	tablenumber t2;
	MLV_create_window("Draw", "Draw", 1200, 800);
	MLV_draw_filled_rectangle(0, 0, 1200, 800, BACKGROUND_COLOR);

	

	grid *g = create_grid(GRID_WIDTH, GRID_HEIGHT);
	
	fread_board(argv[1], g,GRID_WIDTH,GRID_HEIGHT,t1);
	draw_grid(g,60,0,0);

	
	grid *c = create_grid(3,3);
	fillGrid(c,t2);


/* Main game loop */
	MLV_Event event = MLV_NONE;

	MLV_Keyboard_button key_button;
	MLV_Mouse_button mouse_button;
	MLV_Button_state mouse_state;
	int x_pixel, y_pixel, x_pos, y_pos,x_pos2, y_pos2;




	int enter = 0;
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

		
			if (enter != 1)
			{
				x_pos = x_pixel/GRID_SCALE;
				y_pos = y_pixel/GRID_SCALE;
			}
		
			
			
			

			x_pos2 = ((x_pixel-750)/50);
			y_pos2 = ((y_pixel-200)/50);
			int count = 0 ;
			
			printf("Mouse click on ce2 (%d,%d)\n", x_pos2, y_pos2);
			cell *ce ;
			cell *ce2 = &c->cells[x_pos2][y_pos2];
			
			
			
			if (mouse_button == MLV_BUTTON_LEFT && enter == 0 ) {

				printf("Mouse click on ce (%d,%d)\n", x_pos, y_pos); 
				ce = &g->cells[x_pos][y_pos];
				ce->mark = 1;
				enter = 1;	
				draw_grid(c,50,750,200);
			

				
			}
			else if(mouse_button == MLV_BUTTON_LEFT && enter == 1)
			{
				printf("Mouse click on ce2 (%d,%d)\n", x_pos2, y_pos2); 
				printf("Mouse click on  old ce (%d,%d)\n", x_pos, y_pos); 
				ce->x_pos = x_pos ;
				ce->y_pos = y_pos;
			
			
				ce->mark = 0;
				draw_cell_actualise_window(ce,60,0,0);

				ce->number = ce2->number;
				
				
				t1[y_pos][x_pos] = ce2->number;
				int safR,safC,safZ;
					MLV_draw_filled_rectangle(
						750,
						200,
						400,
						400,
						MLV_COLOR_WHITE
						);
				safR = checkRow(t1,y_pos,x_pos,ce->number);
				safC = checkCol(t1,y_pos,x_pos,ce->number);
				safZ = checkZone(t1,y_pos,x_pos,ce->number);
				if (safR+safC+safZ == 3)
				{
					printf(" safe is Row : %d \n",safR);
					printf(" safe is  Col: %d \n",safC);
					printf(" safe is  Zone: %d \n",safZ);
					
					
				}
				enter = 0;
				

				
				
				
				
				
			}
			draw_cell_actualise_window(ce,60,0,0);

			
			
		
		

			
		}
	}


	
	
	/*recd( 200 ,  200 , width/2);*/
	MLV_update_window();

	/* Wait and quit */

	MLV_wait_seconds(100000);
	MLV_free_window();

	return 0;
}