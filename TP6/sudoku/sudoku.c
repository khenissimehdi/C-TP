#include <stdio.h>

#include "sudoku.h"

void initialize_empty_board(Board grid){

}






int checkRow(Board grid, int row,int num,int lo,int ho){

    if (lo < ho)
    {
        if (grid[row][lo] == num){
            return 0;
        }
        checkRow( grid,row, num,lo+1,ho);
  
    }		

}
int checkCol(Board grid, int col,int num,int lo,int ho){
 
    if (lo < ho)
    {
        if (grid[lo][col] == num){
            return 0;
        }
			
        checkCol( grid,col, num,lo+1,ho);
  
    }		

}
int checkZone(Board grid, int startRow,int startCol,int num,int lo,int ho){
    int  j ;
 
    if (lo < ho)
    {
      
		for ( j = 0; j < ho; j++)
			if (grid[lo + startRow][j + startCol] == num){
                return 0;
            }
        checkZone( grid,  startRow, startCol, num, lo +1, ho);
    }		

}

int safe(Board grid, int row, int col, int num)
{
	int i,j;
    int rowCheck,colCheck,zoneCheck;
	
	rowCheck = checkRow( grid,  row, num, 0, 8);
    if (rowCheck == 0)
    {
        return rowCheck;
    }
    colCheck = checkCol( grid,  col, num, 0, 8);
    if (colCheck == 0)
    {
        return colCheck;
    }


	
	int startRow = row - row % 3, 
				startCol = col - col % 3;

	zoneCheck = checkZone( grid,  startRow, startCol, num,0, 3);
    if (zoneCheck == 0)
    {
        return zoneCheck;
    }
    

	return 1;
}



int solve(Board grid, int row, int col)
{
	int num;
    if (row == 8 && col == 9){
         print_board(grid);
    }
      
	if (col == 9) 
	{
		row++;
		col = 0;
	}

	
	if (grid[row][col] > 0)
		return solve(grid, row, col + 1);

	for ( num = 1; num <= 9; num++) 
	{
		

		if (safe(grid, row, col, num)==1) 
		{
		
			grid[row][col] = num;
		
		
			if (solve(grid, row, col + 1)==1)
				return 1;
		}
	

		grid[row][col] = 0;
	}
	return 0;
}



	


void print_board(Board grid){
    int i,j;
   
    printf("-------------------------------------");
 
    putchar('\n');
    for (i=0 ; i<9 ; i++){
       printf("|");
        for (j=0 ; j<9 ; j++){
        
        if (grid[i][j] == 0)
        {
            printf("   |");
        }
        else
        {
             printf(" %d |",grid[i][j]);
        }
        }
      putchar('\n');
      printf("-------------------------------------");
      putchar('\n');
  }
  putchar('\n');

}
