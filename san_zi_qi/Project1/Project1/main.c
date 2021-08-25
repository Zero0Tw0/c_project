#define _CRT_SECURE_NO_WARNINGS 1



#include"game.h"

 void init_border(char bor[LINE][ROW], int line ,int row)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < row;j++)
		{
			bor[i][j] = ' ';
		}
	}
}
void menu()
{
	int s;

	do
	{
		printf("***********************\n");
		printf("****play.1   exit.0****\n");
		printf("***********************\n");
		scanf("%d", &s);
		if (s == 1)
		{
			printf("游戏开始\n");
			
		}
		else if (s == 0)
		{
			printf("退出游戏\n");
			
		}
		else
		{
			printf("非法输入，请重新输入\n");

		}
	} while (s!=1);
}

int main()
{
	srand((unsigned int)time(NULL));
	char bor[LINE][ROW] = {0};
	char win = ' ';
	//菜单
	menu();
	//初始化棋盘
	init_border(bor, LINE, ROW);
	//展示棋盘
	show_border(bor, LINE, ROW);
	while (1)
	{
		//玩家下棋
		player_move(bor, LINE, ROW);
		//展示棋盘
		show_border(bor, LINE, ROW);
		//判断胜利
		win = choose_winner(bor, LINE, ROW);
		if (win == '*')
		{
			printf("游戏结束，玩家胜利！！\n");
			break;
		}
		else if (win == 'p')
		{
			printf("游戏结束，平局！！\n");
			break;
		}
		//电脑下棋
		computer_move(bor, LINE, ROW);
		//展示棋盘
		show_border(bor, LINE, ROW);
		//判断胜利
		win = choose_winner(bor, LINE, ROW);
		if (win == '#')
		{
			printf("游戏结束，电脑胜利！！\n");
			break;
		}
		else if (win == 'p')
		{
			printf("游戏结束，平局！！\n");
			break;
		}
	}
	return 0;
}