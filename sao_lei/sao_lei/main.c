#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"

void game()
{
	srand((unsigned int)time(NULL));
	
	char out_board[ROWS][COLS] = {0};
	char in_board[ROWS][COLS] = {0};
	//初始化棋盘
	init_board(out_board,'*');
	init_board(in_board, '0');
	//展示棋盘//调试用
	//show_board(out_board);
	//show_board(in_board);
	//布置雷
	put_mine(in_board);
	//展示棋盘
	show_board(out_board);
	//show_board(in_board);
	//扫雷
	find_mine(in_board, out_board);
	

}	



void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");
	printf("请玩家输入:");
}

void test()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		if (input == 1)
		{
			printf("开始游戏\n");
			game();
			
		}
		else if (input == 0)
		{
			printf("退出游戏\n");
			break;
		}
		else
		{
			printf("非法输入，请重新输入\n");
		}
	} while (1);
}


int main()
{
	test();
	return 0;
}