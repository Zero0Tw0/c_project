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
			printf("��Ϸ��ʼ\n");
			
		}
		else if (s == 0)
		{
			printf("�˳���Ϸ\n");
			
		}
		else
		{
			printf("�Ƿ����룬����������\n");

		}
	} while (s!=1);
}

int main()
{
	srand((unsigned int)time(NULL));
	char bor[LINE][ROW] = {0};
	char win = ' ';
	//�˵�
	menu();
	//��ʼ������
	init_border(bor, LINE, ROW);
	//չʾ����
	show_border(bor, LINE, ROW);
	while (1)
	{
		//�������
		player_move(bor, LINE, ROW);
		//չʾ����
		show_border(bor, LINE, ROW);
		//�ж�ʤ��
		win = choose_winner(bor, LINE, ROW);
		if (win == '*')
		{
			printf("��Ϸ���������ʤ������\n");
			break;
		}
		else if (win == 'p')
		{
			printf("��Ϸ������ƽ�֣���\n");
			break;
		}
		//��������
		computer_move(bor, LINE, ROW);
		//չʾ����
		show_border(bor, LINE, ROW);
		//�ж�ʤ��
		win = choose_winner(bor, LINE, ROW);
		if (win == '#')
		{
			printf("��Ϸ����������ʤ������\n");
			break;
		}
		else if (win == 'p')
		{
			printf("��Ϸ������ƽ�֣���\n");
			break;
		}
	}
	return 0;
}