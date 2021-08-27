#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void init_board(char board[ROWS][COLS],char a)
{
	int i;
	int j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j]= a;
		}
		
	}
}

void show_board(char board[ROWS][COLS])
{
	int i;
	int j;
	for (i = 0; i < COLS-1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= COL; j++)
		{
			
			printf("%c ", board[i][j]);
		}
		printf("\n");
		
	}
	printf("\n");
}


void put_mine(char board[ROWS][COLS])
{
	int i = 0;
	int x;
	int y;
	while (i < EZGAME)
	{
		x = (rand() % ROW) + 1;
		y = (rand() % COL) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			i++;
		}
		
	}
	
}

void find_mine(char iboard[ROWS][COLS], char oboard[ROWS][COLS])
{
	int x;
	int y;
	int count = 0;
	
	while (1)
	{
		printf("请玩家扫雷：\n");
		scanf("%d%d", &x, &y);
		if (x <= ROW && x >= 1 && y >= 1 && y <= COL)
		{
			if (iboard[x][y] == '0')
			{
				oboard[x][y] =
					iboard[x - 1][y - 1] - '0' +
					iboard[x - 1][y] - '0' +
					iboard[x - 1][y + 1] - '0' +
					iboard[x][y - 1] - '0' +
					iboard[x][y + 1] - '0' +
					iboard[x + 1][y - 1] - '0' +
					iboard[x + 1][y] - '0' +
					iboard[x + 1][y + 1] - '0' + '0';
				show_board(oboard);
				count++;
				if (count == ROW * COL - EZGAME)
				{
					printf("您已扫完所有雷，游戏胜利！\n");
					show_board(iboard);
					break;
				}
				
			}
			else
			{
				printf("您踩中了雷，游戏失败!\n");
				break;
			}
		}
		else
		{
			printf("非法输入，请重新输入!\n");
		}
	}

}