#define LINE 3
#define ROW  3

#include<stdio.h>
#include<time.h>
void show_border(char bor[LINE][ROW], int line, int row);
void player_move(char bor[LINE][ROW], int line, int row);
void computer_move(char bor[LINE][ROW], int line, int row);
char choose_winner(char bor[LINE][ROW], int line, int row);