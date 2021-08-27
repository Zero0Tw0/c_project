#define ROWS ROW+2
#define COLS COL+2

#define ROW 9
#define COL 9

#define EZGAME 10

#include<time.h>
#include<stdio.h>


void init_board(char board[ROWS][COLS],char a);
void show_board(char board[ROWS][COLS]);
void put_mine(char board[ROWS][COLS]);
void find_mine(char iboard[ROWS][COLS], char oboard[ROWS][COLS]);