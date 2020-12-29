#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);
int checkRow(Board grid, int row,int num,int lo,int ho);
int checkCol(Board grid, int col,int num,int lo,int ho);
int checkZone(Board grid, int startRow,int startCol,int num,int lo,int ho);
int safe(Board grid, int row, int col, int num);
int solve(Board grid, int row, int col);
void print_board(Board grid);

#endif
