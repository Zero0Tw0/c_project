#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"

void game()
{
	srand((unsigned int)time(NULL));
	
	char out_board[ROWS][COLS] = {0};
	char in_board[ROWS][COLS] = {0};
	//��ʼ������
	init_board(out_board,'*');
	init_board(in_board, '0');
	//չʾ����//������
	//show_board(out_board);
	//show_board(in_board);
	//������
	put_mine(in_board);
	//չʾ����
	show_board(out_board);
	//show_board(in_board);
	//ɨ��
	find_mine(in_board, out_board);
	

}	



void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");
	printf("���������:");
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
			printf("��ʼ��Ϸ\n");
			game();
			
		}
		else if (input == 0)
		{
			printf("�˳���Ϸ\n");
			break;
		}
		else
		{
			printf("�Ƿ����룬����������\n");
		}
	} while (1);
}


int main()
{
	test();
	return 0;
}