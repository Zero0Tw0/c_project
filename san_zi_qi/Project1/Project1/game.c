#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void show_border(char bor[LINE][ROW], int line, int row)
{
	int i;
	int j;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < row; j++)
		{
			printf(" %c ", bor[i][j]);
			if (j < row - 1)
				printf("|");
			else
				printf("\n");

		}
		if (i < line - 1)
		{
			printf("---|---|---\n");

		}
	}
}

void player_move(char bor[LINE][ROW], int line, int row)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("轮到玩家行动。。。\n");
		printf("请玩家输入下棋位置\n");
		scanf("%d%d", &x, &y);
		if (x <= LINE  && y <= ROW  && bor[x-1][y-1]== ' ')
		{
			bor[x - 1][y -1] = '*';
			break;
		}
		else
		{
			printf("输入超出范围请重新输入\n");
		}

	}
}
void computer_move(char bor[LINE][ROW],int line, int row)
{
	int x = 0;
	int y = 0;
	printf("轮到电脑移动。。。\n请等待\n");

	while (1)
	{
		x = rand() % LINE;
		y = rand() % ROW;
		if (bor[x][y] == ' ')
		{
			bor[x][y] = '#';
			break;
		}
	}

}

char choose_winner(char bor[LINE][ROW], int line, int row)
{
	int i;
	int j;
	static int count = 0;
	count++;
	for (i = 0; i < LINE; i++)
	{

		if (bor[i][0] == bor[i][1] && bor[i][1] == bor[i][2])
		{
			return bor[i][0];
		}
	}
	for (j = 0; j < ROW; j++)
	{
		if (bor[0][j] == bor[1][j] && bor[1][j] == bor[2][j])
		{
			return bor[0][j];
		}
	}
	if (bor[0][0] == bor[1][1] && bor[1][1] == bor[2][2])
	{
		return bor[0][0];
	}
	if (bor[0][2] == bor[1][1] && bor[1][1] == bor[2][0])
	{
		return bor[0][2];
	}
	if (count == 9)
		return 'p';
	return ' ';

}